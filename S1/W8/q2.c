#include <stdio.h>
#include <stdlib.h>


int reach = 0;

void visit(int **maze, int column, int size, int startX, int startY, int endX, int endY) {

  *((int *)maze + startY * column + startX) = 2;

  if(startX == endX && startY == endY) {
    reach = 1;
  }


// =========
  if(reach != 1 && (startY + 1) < size && *((int *)maze + (startY + 1) * column + startX) == 0) {
    visit((int **)maze, column, size,  startX, (startY + 1), endX, endY);
  }
  if(reach != 1 && (startY - 1) >= 0 && *((int *)maze + (startY - 1) * column + startX) == 0) {
    visit((int **)maze, column, size, startX, (startY - 1), endX, endY);
  }
  if(reach != 1 && (startX + 1) < size && *((int *)maze + startY * column + (startX + 1)) == 0) {
    visit((int **)maze, column, size, (startX + 1), startY, endX, endY);
  }
  if(reach != 1 && (startX - 1) >= 0 && *((int *)maze + startY * column + (startX - 1)) == 0) {
    visit((int **)maze, column, size, (startX - 1), startY, endX, endY);
  }
// ========

  *((int *)maze + startY * column + startX) = 3;
}

int main(int argc, char const *argv[]) {
  int size;
  scanf("%d", &size);

  int maze[size][size];

  for (int i = 0 ; i < size ; i++) {
    for (int j = 0 ; j < size ; j++) {
      scanf("%d", &maze[i][j]);
    }
  }
	visit((int **)maze, size, size, 0, 0, size-1, size-1);
  if(reach) {
    printf("Yes\n");
  }else {
    printf("No\n");
  }
  return 0;
}
