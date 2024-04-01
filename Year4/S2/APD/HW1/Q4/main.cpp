#include <iostream>

using namespace std;

double stuAvg(double **score, int i) {
  double sum = 0;
  for(int j = 0; j < 2; j++) {
    sum += score[i][j];
  }
  return sum / 2;
}

double proAvg(double **score, int row) {
  double sum = 0;
  for(int i = 0; i < row; i++) {
    sum += score[i][0];
  }
  return sum / row;
}

double compAvg(double **score, int row) {
  double sum = 0;
  for(int i = 0; i < row; i++) {
    sum += score[i][1];
  }
  return sum / row;
}

int main() {
  // double 2d array
  int row;

  cout << "How many students?" << endl;
  cin >> row;

  double **score = new double*[row];
  for(int i = 0; i < row; i++) {
    score[i] = new double[2];
  }
  
  for(int i = 0; i < row; i++) {
    cout << "Please input two scores for student#" << i << ": " << endl;
    for(int j = 0; j < 2; j++) {
      cin >> score[i][j];
    }
  }

  // calculate the average of each student
  cout << "The average score of each student is:" << endl;
  for(int i = 0; i < row; i++) {
    cout << "student#" << i << " is: " << stuAvg(score, i) << endl;
  }

  // calculate the average of each project
  cout << "TThe average score of programming is " << proAvg(score, row) << endl;
  cout << "The average score of basic computer concepts is " << compAvg(score, row) << endl;

  free(score);
}