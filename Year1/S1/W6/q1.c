#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {

  int a[100];

  int length = 0;
  while(scanf("%d", &a[length]) != EOF) {
    length++;
  }


  for(int i = 0 ; i < length - 1 ; i++) {
    for(int j = 0 ; j < length - i - 1 ; j++) {
      if(a[j] > a[j+1]) {
        int tmp = a[j];
        a[j] = a[j+1];
        a[j+1] = tmp;
      }
    }
  }
  printf("%d %d\n", a[length-1], a[0]);
  return 0;
}
