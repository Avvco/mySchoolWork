#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int m, n;
  cout << "Enter m: ";
  cin >> m;
  cout << "Enter n: ";
  cin >> n;
  double **score = new double*[m];
  for(int i = 0; i < m; i++) {
    score[i] = new double[n];
  }
  for(int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++) {
      cout << "Enter score for student " << i + 1 << " and subject " << j + 1 << ": ";
      cin >> score[i][j];
    }
  }

  // calculate average of each subject and min and max
  double *avg = new double[n];
  double *min = new double[n];
  double *max = new double[n];
  for(int i = 0; i < n; i++) {
    double sum = 0;
    min[i] = score[0][i];
    max[i] = score[0][i];
    for(int j = 0; j < m; j++) {
      sum += score[j][i];
      if(score[j][i] < min[i]) {
        min[i] = score[j][i];
      }
      if(score[j][i] > max[i]) {
        max[i] = score[j][i];
      }
    }
    avg[i] = sum / m;
  }
  for(int i = 0; i < n; i++) {
    cout << "==========" << endl;
    cout << "Average score for subject " << i + 1 << ": " << avg[i] << endl;
    cout << "Min score for subject " << i + 1 << ": " << min[i] << endl;
    cout << "Max score for subject " << i + 1 << ": " << max[i] << endl;
  }

  // free all
  for(int i = 0; i < m; i++) {
    delete[] score[i];
  }
  delete[] score;
  delete[] avg;
  delete[] min;
  delete[] max;
}