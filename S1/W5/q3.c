#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char const *argv[]) {
  int a;
  while (1) {
    scanf("%d", &a);

    while(getchar() != '\n');

    if(a == 0) {
      return 0;
    }

    bool prime = false;

    if(a == 1) {
      printf("not a prime\n");
      continue;
    }else {
      for(int i = 2 ; i < a ; i++) {
        if(a % i == 0) {
          prime = true;
          printf("not a prime\n");
          break;
        }
      }
      if(!prime) {
          printf("prime\n");
      }
    }
  }
  return 0;
}
