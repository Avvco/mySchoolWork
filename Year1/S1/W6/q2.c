#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {

//end condition unknow
  while (1) {
    int a[3];

    for(int i=0;i<3;i++){
      if(scanf("%d", &a[i]) == EOF) {
        return 0;
      };
    }


    for(int i = 0 ; i < 3 - 1 ; i++) {
      for(int j = 0 ; j < 3 - i - 1 ; j++) {
        if(a[j] > a[j+1]) {
          int tmp = a[j];
          a[j] = a[j+1];
          a[j+1] = tmp;
        }
      }
    }

    for(int i = a[2] ; i >= 1 ; i--) {
      if(a[0] % i == 0 && a[1] % i == 0 && a[2] % i == 0) {
        printf("%d\n", i);
        break;
      }
    }

  }
  return 0;
}
