#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {

int a[100];
for(int i=0;i<100;i++){
  a[i] = -1;
}

//     ***input length unknow***
int length = 0;
while(scanf("%d", &a[length]) == 1) {
  length++;
}
for(int z = 0;z < length;z++) {
  printf("%d\n", a[z]);
  printf("%d\n", length);
}




  for(size_t i = 0 ; i < (sizeof(a) / sizeof(int)) - 1 ; i++) {
    for(size_t j = i + 1 ; j < sizeof(a) / sizeof(int) ; j++) {
      if(a[i] > a[j]) {
        int tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
      }
    }
  }

  printf("%d %d\n", a[99], a[0]);
  return 0;
}
