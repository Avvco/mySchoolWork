#include <iostream>

using namespace std;

class GridType {
  public:
    GridType() {

    }
    GridType(string type) {
      this -> type = type;
    }
    GridType(string type, int number) {
      this -> type = type;
      this -> number = number;
    }

    string getType() {
      return type;
    }
    void setVisit(int visit) {
      this -> visit = visit;
    }
    int getVisit() {
      return visit;
    }
    int getNumber() {
      return number;
    }

  private:
    string type; // accept wall, number, dot
    int visit = 0; // 0: not visited, 1: visited, 2: visited this time
    int number = 0;
};
class Nurikabe {
  public:
    /*
    n is the size of the Nurikabe, n >= 5, n <= 20
    game is the result from some player
    here is one example
    n: 5
    game = { {'W', 'W', 'W', '1', 'W'},
             {'W', '.', 'W', 'W', 'W'},
             {'W', '2', 'W', '.', '3'},
             {'3', 'W', 'W', '.', 'W'},
             {'.', '.', 'W', 'W', 'W'} };
    W represent wall
    */
    Nurikabe(char game[20][20], int n) {
      result = 0;
      size = n;

      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if(game[i][j] == 'W' || game[i][j] == 'w') {
            grid[i][j] = GridType("wall");
          }else if(game[i][j] == '.') {
            grid[i][j] = GridType("dot");
          }else if(isdigit(game[i][j])){
            grid[i][j] = GridType("number", game[i][j] - '0');
          }else {
            grid[i][j] = GridType("number", game[i][j] - '0');
          }
        }
      }
      if(checkWall() && checkDot()){
        result = 1;
      }
    }
  /*
  return 1 if result fit the rule.
  return 0 if result not fit the rule.
  */
    int isCorrect() {
      return result;
    }
  private:
    GridType grid[20][20] = {};
    int size;
    int dotCount;
    int result;

    bool checkWall() {
      int x = getFirstwall(0);
      int y = getFirstwall(1);
      if(x > size || y > size) return true;
      visitWall(x, y);
      for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
          if(grid[i][j].getType() == "wall") {
            if(grid[i][j].getVisit() == 0 || isSquare(i, j)) {
              return false;
            }
          }
        }
      }
      return true;
    }
    void visitWall(int x, int y) {
      if(grid[x][y].getType() != "wall") return;

      grid[x][y].setVisit(1);
      if(y - 1 >= 0 && grid[x][y-1].getVisit() == 0) visitWall(x, y-1);
      if(x - 1 >= 0 && grid[x-1][y].getVisit() == 0) visitWall(x-1, y);
      if(y + 1 < size && grid[x][y+1].getVisit() == 0) visitWall(x, y+1);
      if(x + 1 < size && grid[x+1][y].getVisit() == 0) visitWall(x+1, y);
    }

    int getFirstwall(int mode) {// x, y
      struct result {int x; int y;};
      for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
          if(grid[i][j].getType() == "wall") {
            if(mode == 0) {
              return i;
            }else {
              return j;
            }
          }

        }
      }
      return size + 1;
    }

    bool isSquare(int x, int y) {
      if(x + 1 >= size || y + 1 >= size) return false;
      if(grid[x][y+1].getType() == "wall" && grid[x+1][y].getType() == "wall" && grid[x+1][y+1].getType() == "wall") return true;
      return false;
    }

    bool checkDot() {
      for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
          if(grid[i][j].getType() == "number") {
            dotCount = 0;
            visitDot(i, j, 1);
            setDotToVisit();
            if(dotCount != grid[i][j].getNumber()) return false;
          }
        }
      }
      return true;
    }
    void visitDot(int x, int y, int mode) {
      if(mode == 0) {
        if(grid[x][y].getType() != "dot") return;
      }
      if(dotCount == -1) return;

      if(grid[x][y].getVisit() == 1) {
        dotCount = -1;
        return;
      }
      dotCount++;
      grid[x][y].setVisit(2);
      if(y - 1 >= 0 && grid[x][y-1].getVisit() == 0) visitDot(x, y-1, 0);
      if(x - 1 >= 0 && grid[x-1][y].getVisit() == 0) visitDot(x-1, y, 0);
      if(y + 1 < size && grid[x][y+1].getVisit() == 0) visitDot(x, y+1, 0);
      if(x + 1 < size && grid[x+1][y].getVisit() == 0) visitDot(x+1, y, 0);
    }
    void setDotToVisit() {
      for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
          if(grid[i][j].getVisit() == 2) {
            grid[i][j].setVisit(1);
          }
        }
      }
    }
  //請設計你自己的資料結構來儲存遊戲的結果
  //Please design your own data structure to keet the result

};
int main() {
  int n;
  char game[20][20] = { {'W', 'W', 'W', '1', 'W'},
                       {'W', '.', 'W', 'W', 'W'},
                       {'W', '2', 'W', '.', '3'},
                       {'3', 'W', 'W', '.', 'W'},
                       {'.', '.', 'W', 'W', 'W'} };
  cin >> n;
  for(int j = 0 ; j < n ; j ++) {
    for(int k = 0 ; k < n ; k ++) {
      cin >> game[j][k];
    }
  }

  Nurikabe *a = new Nurikabe(game, n);
  cout << a->isCorrect();
  return 0;
}
