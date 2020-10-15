#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int a;

  while(1) {
    scanf("%d", &a);

    if(a == 0) {
      return 0;
    }


    if(a > 1) {
      printf("%d = ", a);

      for(int i = 2 ; i <= a ; i++) {
        if(a % i == 0) {
          printf("%d", i);
          a = a / i;
          break;
        }
      }

      while(a > 1) {
        for(int i = 2 ; i <= a ; i++) {
          if(a % i == 0) {
            printf(" * %d", i);
            a = a / i;
            break;
          }
        }
      }
    }else{

    }
    printf("\n");
  }
  return 0;
}
