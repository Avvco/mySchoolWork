#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int a = 0;
  int b;

  while(1) {
    scanf("%d", &b);
    a = a + b;

    if(b == 0) {
      printf("%d\n", a);
      return 0;
    }
  }
}
