#include <bits/stdc++.h>
using namespace std;


int _map[5][4];
bool visited[5][4];
int minefield = 0;


void judge(int x,int y) {
  if(x<0 || x>=5 || y<0 || y>=4)
    return;
  if (visited[x][y])
    return;
  visited[x][y] = true;
  if(_map[x][y] == 0)
    return;
  else {
    judge(x+1,y);
    judge(x-1,y);
    judge(x,y-1);
    judge(x,y+1);
    return;
  }
}

int main() {

  for(int i = 0 ; i < 4 ; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> _map[i][j];
      visited[i][j] = false;
    }
  }

  for(int i = 0 ; i < 4 ; i++) {
    for (int j = 0; j < 5; j++) {
      if(!visited[i][j]) {
        judge(i, j);
        if(_map[i][j] == 1) minefield++;
      }
    }
  }
  cout << minefield <<endl;
  return 0;
}
