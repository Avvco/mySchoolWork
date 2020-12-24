#include <stdio.h>
#include <stdlib.h>


/*
 * direction
 * 0 = right
 * 1 = down
 * 2 = left
 * 3 = up
 */

int directionCounter(int direction) {
  if(direction < 3) {
    return direction + 1;
  }
  return 0;
}
void printContent(int **content, int **gone, int row, int column, int currentX, int currentY, int direction) {

  printf("%d ", *((int *)content + (currentY * column) + currentX));
  int counter = 0;
  *((int *)gone + (currentY * column) + currentX) = 1;
  while(counter < 2) {
    switch(direction) {
      case 0 :
        if(currentX + 1 < column && *((int *)gone + currentY * column + currentX + 1) == 0) {
          printContent((int **)content, (int **)gone, row, column, currentX + 1, currentY, direction);
        } else {
          direction = directionCounter(direction);
        }
        break;
      case 1 :
        if(currentY + 1 < row && *((int *)gone + (currentY + 1) * column + currentX) == 0) {
          printContent((int **)content, (int **)gone, row, column, currentX, currentY + 1, direction);
        } else {
          direction = directionCounter(direction);
        }
        break;
      case 2 :
        if(currentX - 1 >= 0 && *((int *)gone + currentY * column + currentX - 1) == 0) {
          printContent((int **)content, (int **)gone, row, column, currentX - 1, currentY, direction);
        } else {
          direction = directionCounter(direction);
        }
        break;
      case 3 :
        if(currentY - 1 >= 0 && *((int *)gone + (currentY - 1) * column + currentX) == 0) {
          printContent((int **)content, (int **)gone, row, column, currentX, currentY - 1, direction);
        } else {
          direction = directionCounter(direction);
        }
        break;
    }
    counter++;
  }
}

int main(int argc, char const *argv[]) {
  int row;
  int column;
  int direction = 0;
  scanf("%d%d", &row, &column);

  int content[row][column];
  int gone[row][column];

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < column; j++) {
      scanf("%d", &content[i][j]);
      gone[i][j] = 0;
    }
  }
  printContent((int **)content, (int **)gone, row, column, 0, 0, direction);

  return 0;
}
