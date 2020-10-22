#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int height, up, down;
  int buttom = 0;
  int counter = 0;

  scanf("%d%d%d", &height, &up, &down);

  while(1) {
    counter++;
    buttom = buttom + up;
    if(buttom >= height) {
      printf("%d", counter);
      return 0;
    }
    buttom = buttom - down;
    if(buttom <= 0) {
      printf("-1");
      return 0;
    }
  }
}
