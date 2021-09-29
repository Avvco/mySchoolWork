// http://134.208.3.66/problem/PR109-2-01-2

using namespace std;
#include <iostream>
#include <iomanip>


int combi(int r, int n) {
  int p = 1;
  for(int i = 1; i <= n ; i++) {
    p = p * (r - i + 1) / i;
  }
  return p;
}

int main(int argc, char const *argv[]) {
  int a;
  cin >> a;
  for (int i = 0 ; i < a ; i++) {
    for (int j = a - 1 - i ; j > 0 ; j--) {
      cout << "  ";
    }
    cout << setw(2) << setfill(' ') << combi(i, 0);
    for (int j = 0; j < i ; j++) {
      cout << "  ";
      cout << setw(2) << setfill(' ') << combi(i, j + 1);
    }
    cout << endl;
  }
  return 0;
}
