#include <stdio.h>
#include <stdlib.h>


int prime(int z); //use as boolean function    0 = not a prime, 1 = prime

int main(int argc, char const *argv[]) {
  int a;
  scanf("%d", &a);

  int counter = 0;
  for(int i = 2 ; i < a ; i++) {
    int j = a - i;
    if(prime(i) == 1 && prime(j) == 1 && i<=j) {
      counter++;
    }
  }
  printf("%d", counter);

  return 0;
}



int prime(int z) {

  for(int i = 2 ; i < z ; i++) {
    if(z % i == 0) {
      return 0;
    }
  }
  return 1;
}
