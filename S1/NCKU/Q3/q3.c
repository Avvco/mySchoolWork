#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void seperate(char * ori, char * sub) {
  int counter = 0;
  while(*(ori + counter) != ' '){
    *(sub + counter) = *(ori + counter);
    counter++;
    printf("%c", *(sub + counter));
  }
  return;
}

int main(int argc, char const *argv[]) {
  FILE *fp;

  char str[1000];

  char filename[] = "./Q3.txt";

  fp = fopen(filename, "r");

  if(fp == NULL) {
    printf("NI");
    return 1;
  }
  int counter = 0;
  double error[10000];
  while(fgets(str, 1000, fp) != NULL) {
    char time[150];
    char m[150];
    char e[150];
    char * ori = str;
    seperate(ori, time);
    ori = ori + strlen(time) + 1;
    seperate(ori, m);
    ori = ori + strlen(m) + 1;
    seperate(ori, e);
    double doubleM = atof(m);
    double doubleE = atof(e);
    error[counter] = doubleM - doubleE;


    printf("\n STR %s", str);
    printf("%lf %lf\n", doubleM, doubleE);
    printf("error %lf\n", doubleM - doubleE );
    counter++;
  }
  counter = counter - 1;
  for (int i = 0; i < counter; i++) {
    //printf("%lf\n", error[i]);
  }
  printf("\n%d\n", counter);

  return 0;
}
