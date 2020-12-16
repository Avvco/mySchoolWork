#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_string(const void* _a , const void* _b)
{
    char* a = (char*)_a;
    char* b = (char*)_b;
    return strcmp(a,b);
}


int main(int argc, char const *argv[]) {
  int length;
  scanf("%d", &length);
  char strings[length][51];

  for(int i = 0 ; i < length ; i++) {
    scanf("%s", strings[i]);
  }

  qsort((void *)strings, length, sizeof(strings[0]), compare_string);

  for(int i = 0 ; i < length ; i++) {
    printf("%s\n", strings[i]);
  }
  return 0;
}
