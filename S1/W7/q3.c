//  http://134.208.3.66/problem/PR1090703

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char const *argv[]) {
  char a[100001];

  while(scanf("%s", a) != EOF);

  size_t length = strlen(a);
  size_t start = 0;

  while(start <= length-1) {
    if(tolower(a[start]) != tolower(a[length-1])) {
      printf("%s is not a palindrome.", a);
      return 0;
    }
    start++;
    length--;
  }
  printf("%s is a palindrome.", a);
  return 0;
}
