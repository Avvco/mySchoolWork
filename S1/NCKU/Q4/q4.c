#include <stdio.h>

void istriangle (int a[]) {
  for(int i = 0 ; i < 3 ; i++) {
    if(a[i] < a[i+1] + a[i+2]) {
      printf("NO");
      return;
    }
  }
  printf("YES");
}

int main(int argc, char const *argv[]) {
  int a[5];
  scanf("%d%d%d", &a[0], &a[1], &a[2]);


  a[3] = a[0];
  a[4] = a[1];
  istriangle(a);

  return 0;
}
