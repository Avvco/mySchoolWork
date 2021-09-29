#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int number = 0;
  printf("輸入人數: ");
  scanf("%d", &number);

  char ** tarr = (char **) malloc(sizeof(char*) * number);
  for(int i = 0 ; i < number ; i++) {
    tarr[i] = (char *)malloc(sizeof(char) * 10);
  }

  int * grade = (int*)malloc(sizeof(int) * 10);

  for(int i = 0 ; i< number ; i++) {
    printf("\n輸入第 %d 個學生的姓名: ", i + 1);
    scanf("%s", tarr[i]);
    printf("輸入他/她的成績: ");
    scanf("%d", &grade[i]);
  }
  printf("\n");
  for (int i = 0; i < number; i++) {
    printf("第 %d 位學生: %s , 成績為 %d 分\n", i+1, tarr[i], grade[i]);
  }
  printf("\n");
  return 0;
}
