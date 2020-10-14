#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int a;
  scanf("%d", &a);

  for(int i = 1 ; i <= a ; i++) {
    if(a % i == 0) {
      printf("%d ", i);
    }
  }

  return 0;
}
