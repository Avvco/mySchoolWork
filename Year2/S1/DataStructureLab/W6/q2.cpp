#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

#define SIZE 10
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

class Grid {
  public:
  	Grid():Grid(0) {}
  	Grid(int s) {
  		state = s;
  		dir[UP] = NULL;
  		dir[DOWN] = NULL;
  		dir[LEFT] = NULL;
  		dir[RIGHT] = NULL;
  	}
  	Grid *getDir(int d) const { return dir[d]; }
  	int getState() const { return state; }
  	void setDir(int d, Grid *g) { dir[d] = g; }
  	void setState(int s) { state = s;}
  private:
  	Grid *dir[4];
  	int state;
};

class List {
  public:
  	List() {
  		top = 0;
  	}
  	/*
  	Insert an element from top
  	*/
  	void addElement(Grid *g){
			data[top] = g;
      top++;
  	}
  	/*
  	remove an element from top and return a pointer point to the element.
  	If list is empty, return NULL.
  	*/
  	Grid *removeElement() {
			if(top == 0) return NULL;
			top--;
			return data[top+1];
  	}
  	void printPath() const {
  		int j;
  		for(j = top ; j >= 0 ; j--) {
  			if(data[j] == data[j - 1]->getDir(UP)) {
  				cout<<"UP\n";
  			}
  			else if(data[j] == data[j - 1]->getDir(DOWN)) {
  				cout<<"DOWN\n";
  			}
  			else if(data[j] == data[j - 1]->getDir(LEFT)) {
  				cout<<"LEFT\n";
  			}
  			else if(data[j] == data[j - 1]->getDir(RIGHT)) {
  				cout<<"RIGHT\n";
  			}
  		}
  	}
		int getTop() {
			return top;
		}
  private:
  	Grid *data[SIZE * SIZE];
  	int top;
};

class Maze {
  public:
  	Maze() {
  		initMaze(SIZE);
  	}
  	/*
  	function initMaze
  	Alocate a 2-D link list with s * s sizes as the map of maze.
  	Inside the maze enery gird with state 0 represent empty space and 1 represent wall.
  	The gird in left top is start point and right bottom is finish point.
  	Randomly generate 20% wall in the maze.
  	Make sure start point and finish point are 0

  	動態配置一個二維的鏈結串列，大小是 s * s，用這個鏈結串列表示迷宮的地圖
  	節點中 0 的值表示可以移動的空間， 1 表示牆壁
  	左上角的位置表示起點，右下角的位置表示終點
  	請在迷宮中加入 20% 的牆壁
  	然後確定起點跟終點都是可以移動的位置
  	*/
  	void initMaze(int s) {
      Grid *_maze[s][s];
			for (int i = 0; i < s; i++) {
				for (int j = 0; j < s; j++) {
					_maze[i][j] = new Grid();
				}
			}
      for (int y = 0; y < s; y++) {
        for (int x = 0; x < s; x++) {
          int random = rand() % 100; // 20/100

					// WALL
          if(random < 90) {
            _maze[y][x]->setState(1); // wall
          } else {
            _maze[y][x]->setState(0); // road
          }
          if((y == 0 && x == 0) || (y == s - 1 && x == s-1)) {
            _maze[y][x]->setState(0);
          }
					// =========
					// Diraction
						if((y + 1) < SIZE) _maze[y][x]->setDir(DOWN, _maze[y + 1][x]);
						if((y - 1) >= 0) _maze[y][x]->setDir(UP, _maze[y - 1][x]);
						if((x + 1) < SIZE) _maze[y][x]->setDir(RIGHT, _maze[y][x + 1]);
						if((x - 1) >= 0) _maze[y][x]->setDir(LEFT, _maze[y][x - 1]);
					// =========
          //cout <<_maze[y][x]->getState()<< " ";
        }
        //cout<<endl;
      }
      maze = **_maze;
  	}
  	/*
  	function getPath
  	This function will find a path between start point and finish point.
  	Return a list content the path information inside.
  	If there is no path between two point then the list will be empty.

  	這個函數會找到起點到終點間的一條路徑
  	回傳一個 list 包含著路徑的資訊
  	如果找不到路徑的話 list 就會是空的
  	*/
  	List *getPath() {
			List *list = new List();
      visit(list, maze);
      if(list -> getTop() <= 1) return NULL;
      return list;
  	}
  	void printMaze() const {
  		Grid *j = maze, *k;
  		while(j != NULL) {
  			k = j;
  			while(k != NULL) {
  				cout<<k->getState()<<" ";
  				k = k->getDir(RIGHT);
  			}
  			cout<<endl;
  			j = j->getDir(DOWN);

  		}
  	}

		void visit(List *list, Grid* maze) {
      if(maze->getDir(RIGHT) == NULL && maze->getDir(DOWN)) {
        list->addElement(maze);
        reach = true;
        return;
      }
      maze -> setState(3);
    // =========
      if(!reach && maze->getDir(UP) && maze->getDir(UP)->getState() == 0) {
        visit(list, maze->getDir(UP));
      }
      if(!reach && maze->getDir(DOWN) && maze->getDir(DOWN)->getState() == 0) {
        visit(list, maze->getDir(DOWN));
      }
      if(!reach && maze->getDir(LEFT) && maze->getDir(LEFT)->getState() == 0) {
        visit(list, maze->getDir(LEFT));
      }
      if(!reach && maze->getDir(RIGHT) && maze->getDir(RIGHT)->getState() == 0) {
        visit(list, maze->getDir(RIGHT));
      }
      if(maze->getState() == 3) maze->setState(0);
    // ========
      if(reach) {
        list -> addElement(maze);
      }
    }
  private:
  	Grid *maze;
		bool reach;
};

int main() {
	Maze *maze = new Maze();
	maze->printMaze();
  List *list = maze->getPath();
  if(!list) {
    cout<<"No path"<<endl;
  }else {
    list->printPath();
  }
}
