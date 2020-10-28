//  http://134.208.3.66/problem/PR1090705

//not finished yet

#include <stdio.h>
#include <stdlib.h>

void selectionSort(int*);

int main(int argc, char const *argv[]) {
  /* code */
  int exeTime;
  scanf("%d", &exeTime);
  for(int i = 0 ; i < exeTime ; i++) {
    int contentLength;
    scanf("%d", &contentLength);

    int coordinate[contentLength][2]; //[][0]x, [][1]y

    for(int j = 0 ; j < contentLength ; j++) {
      for(int k = 0 ; k < 2 ; k++) {
        scanf("%d\n", &coordinate[j][k]);
      }
    }
    int min = coordinate[0][0];
    int lastMin = 0;
    int sortCoordinate[contentLength];
    int sortCoordinateConter = 0;
    for(int j = 0 ; j < contentLength ; j++) {
      int minLoc = 0;
      if(coordinate[j][0] <= min && coordinate[j][0] >= lastMin) {
        min = coordinate[j][0];
        minLoc = j;
      }
    }
    return 0;
  }
}
