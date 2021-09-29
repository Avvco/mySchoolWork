#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char word[1000];
    int counter;
}Stc;

int main(int argc, char const *argv[]) {
  int counter = 0;
  char origin[100000];
  Stc stc[1000];

  scanf("%[^\n]", origin);

  for(size_t i = 0 ; i < strlen(origin) ; i++) {
    char current = origin[i];
    if(current == ' ') {
      counter++;
    }else {
      stc[counter].word[stc[counter].counter] = current;
      stc[counter].counter++;
    }
  }
  for(int i = counter ; i >= 0 ; i--) {
    for(int j = 0 ; j < stc[i].counter ; j++) {
      printf("%c", stc[i].word[j]);
    }
    printf(" ");
  }
  return 0;
}
