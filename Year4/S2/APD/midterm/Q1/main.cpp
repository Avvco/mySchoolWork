#include <iostream>

using namespace std;

int main() {
  int size;
  cout << "Enter size: ";
  cin >> size;
  char *p = new char[size];
  cout << "Enter a string: ";
  for(int i = 0; i < size; i++) {
    cin >> p[i];
  }
  cout << "The string is: ";
  for(int i = 0; i < size; i++) {
    cout << p[i];
  }
  cout << endl;
}