//  http://134.208.3.66/problem/PR1090703

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char const *argv[]) {
  char a[100001];

  while(scanf("%100000s", a) != EOF);

  size_t length = strlen(a);
  char b[length];

  for(size_t i = 0 ; i < length ; i++) {
    b[i] = a[i];
    a[i] = tolower(a[i]);
  }
  size_t start = 0;

  while(start <= length-1) {
    if(a[start] != a[length-1]) {
      for(size_t i = 0 ; i < strlen(a) ; i++) {
        printf("%c", b[i]);
      }
      printf(" is not a palindrome.");
      return 0;
    }
    start++;
    length--;
  }
  for(size_t i = 0 ; i < strlen(a) ; i++) {
    printf("%c", b[i]);
  }
  printf(" is a palindrome.");
  return 0;
}
