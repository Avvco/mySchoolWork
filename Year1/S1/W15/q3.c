#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printString(char * string, char * end_ptr) {
  printf("%c", *end_ptr);
  if(string == end_ptr) return;
  printString(string, end_ptr - 1);
}

int main(int argc, char const *argv[]) {
  char string[1000];
  scanf("%s", string);

  char * end_ptr = string + strlen(string) - 1;
  printString(string, end_ptr);

  return 0;
}
