#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int a;
  scanf("%d", &a);

  //height
  for(int i = 0 ; i < a ; i++) {
    for(int j = 0 ; j < a-1-i ; j++) {
      printf(" ");
    }
    for(int k = 0 ; k < i+1 ; k++) {
      if(k != i){
        printf("* ");
      }else{
        printf("*");
      }

    }
    if(i != a-1) {
      printf("\n");
    }

  }

  return 0;
}
