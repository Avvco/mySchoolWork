#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
  char id[10];
  int grade1;
  int grade2;
  int grade3;
  double average;
} Student;

double avg(int a, int b, int c) {
  return ((double)a + (double)b + (double)c) / 3;
}

int main(int argc, char const *argv[]) {
  FILE *fp;
  fp = fopen("./grade.txt", "r");

  if(fp == NULL) {
    printf("NI");
    return -1;
  }

  char str[1000];

  Student student[100];
  int studentCount = 0;

  while(fgets(str, 1000, fp) != NULL) {
    sscanf(str,"%s %d %d %d", student[studentCount].id, &student[studentCount].grade1, &student[studentCount].grade2, &student[studentCount].grade3);

    //printf("%s %d %d %d\n", student[studentCount].id, student[studentCount].grade1, student[studentCount].grade2, student[studentCount].grade3);
    student[studentCount].average = avg(student[studentCount].grade1, student[studentCount].grade2, student[studentCount].grade3);
    studentCount++;
  }
  fclose(fp);

  //sort
  int sortArr[studentCount];

  for (int i = 0; i < studentCount; i++) {
    sortArr[i] = i;
  }

  for(int i = 0 ; i < studentCount - 1; i++) {
    for(int j = i + 1 ; j < studentCount ; j++) {
      if(student[sortArr[i]].average > student[sortArr[j]].average) {
        int tmp = sortArr[i];
        sortArr[i] = sortArr[j];
        sortArr[j] = tmp;
      }
    }
  }
  printf("Sorting by average: \n");
  for (int i = studentCount - 1 ; i >= 0; i--) {
    printf("%s %d %d %d %.2lf\n", student[sortArr[i]].id, student[sortArr[i]].grade1, student[sortArr[i]].grade2, student[sortArr[i]].grade3, student[sortArr[i]].average);
  }

  return 0;
}
