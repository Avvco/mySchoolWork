#include <stdio.h>

int locate(char ** cb, int differX, int differY, int currentX, int currentY, char current) {
  for(int i = 0 ; i < 5 ; i++) {
    if((currentX >= 0 || currentX < 19) && (currentY >= 0 || currentY < 19) && *((char *) cb + currentY * 19 + currentX) == current) {
      currentX = currentX + differX;
      currentY = currentY + differY;
      continue;
    }
    return 0; //not found
  }
  return 1; //found
}


int found(char ** cb, int currentX, int currentY, char current) {
  for(int i = -1 ; i <= 1 ; i++) {
    for(int j = -1 ; j <= 1 ; j++) {
      if(i == 0 && j == 0) continue;
      if(locate((char**) cb, j, i, currentX, currentY, current) == 1) {
        return 1; //found
      }
    }
  }
  return 0; //not found
}


int main(int argc, char const *argv[]) {
  char checkerboard[19][19];

  for (size_t i = 0; i < 19; i++) {
    scanf("%s", checkerboard[i]);
  }
  for(int i = 0 ; i < 19 ; i++) {
    for (int j = 0; j < 19; j++) {
      if(checkerboard[i][j] == 'O') {
        if(found((char**) checkerboard, j, i, checkerboard[i][j]) == 1) {
          printf("White\n");
          return 0;
        }
      } else if(checkerboard[i][j] == 'X') {
        if(found((char**) checkerboard, j, i, checkerboard[i][j]) == 1) {
          printf("Black\n");
          return 0;
        }
      }
    }
  }
  printf("No winner\n");
  return 0;
}
