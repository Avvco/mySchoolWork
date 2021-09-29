#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char const *argv[]) {
  double a;
  scanf("%lf", &a);

  double upper,lower;

  //整數部分
  for(double i = 0 ; i <= a ; i++) {
    if(i * i <= a && ( i + 1 ) * ( i + 1 ) >= a) {
      lower = i;
      upper = i + 1;
    }
  }

  //小數部分
  for(double i = 1 ; i <= 6 ; i++) {
    for(double j = lower ; j <= upper ; j = j + 1/pow(10,i)) {
      if(j * j <= a && ((j + 1/pow(10,i))*(j + 1/pow(10,i))) >= a) {
        lower = j;
        upper = (j + 1/pow(10,i));
        break;
      }
    }
  }
  printf("%.4lf\n", lower);



  return 0;
}
