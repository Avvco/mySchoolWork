#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>

int calculator(char *);

int f(int x) {
  return x + 1;
}

int g(char * current) {
  int counter = 0;
  int inner = 1;
  while(1) {
    if(*(current + counter) == 'G') {
      inner++;
    }
    if(*(current + counter) == ',') {
      inner--;
    }
    if(inner == 0) {
      break;
    }
    counter++;
  }
  return calculator(current) + calculator(current + counter + 1);
}

int calculator(char * input) {
  int current = 0;
  if(*input == 'F') {
    current = f(calculator(input + 2));
  } else if(*input == 'G') {
    current = g(input + 2);
  } else if(isdigit((int)*input)) {
    return atoi(input);
  }
  return current;
}

int main(int argc, char const *argv[]) {
  char input[1000];
  scanf("%[^\n]", input);
  printf("%d\n", calculator(&input[0]));

  return 0;
}
