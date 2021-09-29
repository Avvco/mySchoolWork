//  http://134.208.3.66/problem/PR1090705

//not finished yet

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double Slope(int, int, int, int);

int main(int argc, char const *argv[]) {
  /* code */
  int exeTime;
  scanf("%d", &exeTime);
  for(int i = 0 ; i < exeTime ; i++) {
    int contentLength;
    scanf("%d", &contentLength);

    int coordinate[contentLength][2]; //[][0]x, [][1]y
    int sequent[contentLength];
    for(int j = 0 ; j < contentLength ; j++) {
      for(int k = 0 ; k < 2 ; k++) {
        scanf("%d", &coordinate[j][k]);
      }
    }

    for (int j = 0; j < contentLength; j++) {
      sequent[j] = j;
    }

    //sort
    for (int j = 0; j < contentLength - 1; j++) {
      for (int k = j + 1; k < contentLength; k++) {
        if(coordinate[sequent[j]][0] > coordinate[sequent[k]][0]) {
          int tmp = sequent[j];
          sequent[j] = sequent[k];
          sequent[k] = tmp;
        }
      }
    }

    int yAxis = 0;
    double line = 0;
    for (int j = contentLength - 1 ; j > 0; j--) {

      if(coordinate[sequent[j-1]][1] > yAxis) {

        double slope = Slope(coordinate[sequent[j]][0], coordinate[sequent[j]][1], coordinate[sequent[j-1]][0], coordinate[sequent[j-1]][1]);

        double b = coordinate[sequent[j-1]][1] - slope * coordinate[sequent[j-1]][0];
        double X = (yAxis - b) / slope;



        line = line + pow(pow(X-coordinate[sequent[j-1]][0], 2) + pow(yAxis - coordinate[sequent[j-1]][1], 2), 0.5);
        yAxis = coordinate[sequent[j-1]][1];
      }
    }
    printf("%.2lf\n", line);
  }
  return 0;
}

double Slope(int x1, int y1, int x2, int y2) {
  double ans = ((double)y1 - (double)y2) / ((double)x1 - (double)x2);
  return ans;
}
