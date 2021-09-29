#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int row, column;
  scanf("%d%d", &row, &column);

  int matrix[row][column];
  int gone[row][column];

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < column; j++) {
      scanf("%d", &matrix[i][j]);
      gone[i][j] = 0;
    }
  }

  int rowCounter = 0;
  int columnCounter = 0;
  while (1) {
    if(gone[rowCounter][columnCounter] == 1) return 0;
    while (1) { //to right
      printf("%d ", matrix[rowCounter][columnCounter]);
      gone[rowCounter][columnCounter] = 1;
      if(gone[rowCounter][columnCounter + 1] == 0 && columnCounter + 1 < column) {
        columnCounter++;
      }else {
        break;
      }
    }
    rowCounter++;
    if(gone[rowCounter][columnCounter] == 1) return 0;
    while (1) { //to down
      printf("%d ", matrix[rowCounter][columnCounter]);
      gone[rowCounter][columnCounter] = 1;
      if(gone[rowCounter + 1][columnCounter] == 0 && rowCounter + 1 < row) {
        rowCounter++;
      }else {
        break;
      }
    }
    columnCounter--;
    if(gone[rowCounter][columnCounter] == 1) return 0;
    while (1) { //to left
      printf("%d ", matrix[rowCounter][columnCounter]);
      gone[rowCounter][columnCounter] = 1;
      if(gone[rowCounter][columnCounter - 1] == 0 && columnCounter - 1 >= 0) {
        columnCounter--;
      }else {
        break;
      }
    }
    rowCounter--;
    if(gone[rowCounter][columnCounter] == 1) return 0;
    while (1) { //to up
      printf("%d ", matrix[rowCounter][columnCounter]);
      gone[rowCounter][columnCounter] = 1;
      if(gone[rowCounter - 1][columnCounter] == 0 && rowCounter - 1 >= 0) {
        rowCounter--;
      }else {
        break;
      }
    }
    columnCounter++;
  }

  return 0;
}
