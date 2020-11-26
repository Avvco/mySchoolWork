#include <stdio.h>
#include <stdlib.h>

int compaired(int arr[][3], int count, int compair) {
  for(int i = 0 ; i < count ; i++) {
    if(arr[i][1] == compair) {
        return 1;
      }
  }
  return 0;
}
int main(int argc, char const *argv[]) {
  int m, n;
  scanf("%d%d", &m, &n);
  int student_count = 0;
  int student[m][3];
  int score[n][2];

  for(int i = 0 ; i < m ; i++) {
    scanf("%d%d%d", &student[i][0], &student[i][1], &student[i][2]);
    if(compaired(student, i, student[i][1]) == 0) {
        student_count++;
    }
  }

  int failed_student[m][3];
  int failed_student_count = 0;

  for(int i = 0 ; i < n ; i++) {
    scanf("%d%d", &score[i][0], &score[i][1]);
  }

  for(int i = 0 ; i < m ; i++) {
    int currentID = student[i][0];
    double total_grade = 0;
    double total_grade_count = 0;

    for(int j = 0 ; j < n ; j++) {
      if(score[j][0] == currentID) {
        total_grade_count++;
        total_grade = total_grade + score[j][1];
      }
    }
    int avgGrade = total_grade / total_grade_count;
    if(avgGrade < 60) {
      failed_student[failed_student_count][1] = student[i][1];
      failed_student_count++;
    }
  }

  int failed_counter = 0;

  for(int i = 0 ; i < failed_student_count ; i++) {
    if(compaired(failed_student, i, failed_student[i][1]) == 0) {
      failed_counter++;
    }
  }
  printf("%d %d", student_count, failed_counter);
}
