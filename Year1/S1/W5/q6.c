#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  char a[100] = {'a'};
  scanf("%s", a);

  for(int i = 0 ; i < 100 ; i++) {
    char z = a[i];
    switch (z) {
      case '0':
        printf("----- ");
        break;

      case '1':
        printf(".---- ");
        break;

      case '2':
        printf("..--- ");
        break;

      case '3':
        printf("...-- ");
        break;

      case '4':
        printf("....- ");
        break;

      case '5':
        printf("..... ");
        break;

      case '6':
        printf("-.... ");
        break;

      case '7':
        printf("--... ");
        break;

      case '8':
        printf("---.. ");
        break;

      case '9':
        printf("----. ");
        break;
    }
  }
  return 0;
}
