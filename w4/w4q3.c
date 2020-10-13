#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int a[4];
  int sizeOfa = sizeof(a)/sizeof(a[0]);

  for(int i = 0 ; i < sizeOfa ; i++){
    scanf("%d", &a[i]);
  }

  int bigger = a[0];
  for(int i = 0 ; i < sizeOfa ; i++){
    if(a[i]>=bigger){
      bigger = a[i];
    }
  }
    int occupied[bigger];
    int sizeOfoccupied = sizeof(occupied)/sizeof(occupied[0]);
    printf("%d\n", sizeOfoccupied);

    for(int i = 0 ; i < sizeOfoccupied ; i++){
      occupied[i] = 0;
    }

    if(a[0]>=a[1]){
      int tmp = a[1];
      a[1] = a[0];
      a[0] = tmp;
    }

    if(a[2]>=a[3]){
      int tmp = a[3];
      a[3] = a[2];
      a[2] = tmp;
    }


    for(int i = a[0] ; i < a[1] ; i++){
      occupied[i] = 1;
    }
    for(int i = a[2] ; i < a[3] ; i++){
      if(occupied[i]==1){
        printf("overlay\n");
        return 0;
      }
      occupied[i] = 1;
    }
  printf("no overlay\n");
  return 0;
}
