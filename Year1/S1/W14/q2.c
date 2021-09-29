#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int opration(char o, int x1, int x2) {
  switch (o) {
    case '+' : return x1 + x2;
    case '-' : return x1 - x2;
    case '*' : return x1 * x2;
    case '/' : return x1 / x2;
  }
  return -1;
}


int main(int argc, char const *argv[]) {
  char fol[201];
  char opts[200];
  int number[200];
  int numberCounter = 0;
  int optsCounter = 0;
  scanf("%[^\n]", fol);

  for(int i = 0 ; i < strlen(fol) ; i++) {
    char tmp[200] = {0};
    int tmpCounter = 0;
    switch(fol[i]) {
      case '+' :
        opts[optsCounter] = '+';
        optsCounter++;
        break;

      case '-' :
        opts[optsCounter] = '-';
        optsCounter++;
        break;

      case '*' :
        opts[optsCounter] = '*';
        optsCounter++;
        break;

      case '/' :
        opts[optsCounter] = '/';
        optsCounter++;
        break;

      case ' ' :
        break;
      default :
        while(fol[i] != ' ' && i < strlen(fol)) {
          tmp[tmpCounter] = fol[i];
          i++;
          tmpCounter++;
        }

        number[numberCounter] = atoi(tmp);
        numberCounter++;
    }
  }

  if(numberCounter < 2) {
    printf("%d\n", number[0]);
    return 0;
  }
  int current = opration(opts[0], number[0], number[1]);
  for(int i = 1 ; i < optsCounter ; i++) {
    current = opration(opts[i], current, number[i+1]);

  }

  printf("%d\n", current);

  return 0;
}
