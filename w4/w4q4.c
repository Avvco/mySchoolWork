#include <stdio.h>
#include <stdlib.h>

int main() {
  int alice = 0;
  int bob = 0;

  for(int i = 0 ; i < 5 ; i++) {
    printf("%d\n", i);
    char input[2];

    scanf("%s", input);


    printf("inp1%c ", input[0]);
    printf("inp2%c\n", input[1]);

    if(input[0] == 'P') {
      if(input[1] == 'R') {
        alice++;
      }
      if(input[1] == 'S') {
        bob++;
      }
    }

    if(input[0] == 'R') {
      if(input[1] == 'S') {
        alice++;
      }
      if(input[1] == 'P') {
        bob++;
      }
    }

    if(input[0] == 'S') {
      if(input[1] == 'P') {
        alice++;
      }
      if(input[1] == 'R') {
        bob++;
      }
    }
    printf("hi\n");
  }

  if(alice > bob) {
    printf("Alice");
  }else if(bob > alice) {
    printf("Bob");
  }else {
    printf("Draw");
  }

  return 0;
}
