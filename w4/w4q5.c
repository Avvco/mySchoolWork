#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int length[5];
   scanf("%d %d %d", &length[0], &length[1], &length[2]);

  length[3] = length[0];
  length[4] = length[1];



  for(int i = 0 ; i < 3 ; i++) {
    if(length[i] + length[i+1] <= length[i+2]){
      printf("can not construct");
      return 0;  
    }
  }

  for(int i = 0 ; i < 3 ; i++){
    if(length[i] + length[i+1] > length[i+2]) {
      if(length[i]*length[i] + length[i+1]*length[i+1] == length[i+2]*length[i+2]){
        printf("right triangle");
        return 0;
      }
      if(length[i]*length[i] + length[i+1]*length[i+1] > length[i+2]*length[i+2]){
        printf("acute triangle");
        return 0;
      }
      if(length[i]*length[i] + length[i+1]*length[i+1] < length[i+2]*length[i+2]){
        printf("obtuse triangle");
        return 0;
      }
    }
  }
  return 0;
}
