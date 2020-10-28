#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {

//end condition unknow
  while (1) {
    int a[3];


    for(int i=0;i<3;i++){
      scanf("%d", &a[i]);
    }


    for(size_t i = 0 ; i < (sizeof(a) / sizeof(int)) - 1 ; i++) {
      for(size_t j = i + 1 ; j < sizeof(a) / sizeof(int) ; j++) {
        if(a[i] > a[j]) {
          int tmp = a[i];
          a[i] = a[j];
          a[j] = tmp;
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
