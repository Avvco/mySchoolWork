#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  char question[50];
  char answer[50];

  int a = 0;
  int b = 0;

  scanf("%s", question);
  scanf("%s", answer);

  for(size_t i = 0 ; i < strlen(question) ; i++) {
    if(question[i] == answer[i]) {
      a++;
      question[i] = 'a';
      answer[i] = 'b';
    }
  }

  for(size_t i = 0 ; i < strlen(answer) ; i++) {
    for(size_t j = 0 ; j < strlen(question) ; j++) {
      if(answer[i] == question[j]) {
        b++;
        question[j] = 'c';
      }
    }
  }
  printf("%d %d", a, b);

  return 0;
}
