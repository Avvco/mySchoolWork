#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

using namespace std;

int main() {
  // read double from infile.txt and store in vector
  ifstream infile("infile.txt");
  vector<double> v;
  double x;
  while(infile >> x) {
    v.push_back(x);
  }
  infile.close();

  // calculate average and standard deviation
  double sum = 0;
  for(int i = 0; i < v.size(); i++) {
    sum += v[i];
  }
  double avg = sum / v.size();
  double sum2 = 0;
  for(int i = 0; i < v.size(); i++) {
    sum2 += pow(v[i] - avg, 2);
  }
  double sd = sqrt(sum2 / v.size());
  cout << "Average: " << avg << endl;
  cout << "Standard deviation: " << sd << endl;
}