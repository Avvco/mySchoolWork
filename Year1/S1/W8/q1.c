#include <stdio.h>
#include <stdlib.h>

int dataExist(int, int, int[]);  //use as boolean, 0 represent doesn't exist, 1 represent exist.

int main(int argc, char const *argv[]) {
  int row, column, non_zero_count, temp;

  scanf("%d%d%d", &row, &column, &non_zero_count);

  int non_zero[non_zero_count][3];

  /*
   *  row, column start from 0
   *  [][0] row, [][1] column, [][2] data
   *  row --- ,  column |
   */

  for(int i = 0 ; i < non_zero_count ; i++) {
    for (int j = 0 ; j < 3 ; j++) {
      scanf("%d", &non_zero[i][j]);
    }
  }

  for (int i = 0; i < row ; i++) {
    for (int j = 0; j < column; j++) {
      int exist = 0;
      for (int k = 0; k < non_zero_count; k++) {
        if(dataExist(i, j, non_zero[k]) == 1) {
          temp = non_zero[k][2];
          //printf("%d ", non_zero[k][2]);
          exist = 1;
          //break;
        }
      }
      if(exist == 0) {
        printf("0 ");
      } else {
        printf("%d ", temp);
      }
    }
    printf("\n");
  }
  return 0;
}


int dataExist(int currentX, int currentY, int compareData[]) {
  if(currentX == compareData[0] && currentY == compareData[1]) {
    return 1;
  }
  return 0;
}
