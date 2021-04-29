// http://134.208.3.66/problem/PR109-2-01-1

using namespace std;
#include <iostream>
#include <iomanip>

int main(int argc, char const *argv[]) {
  int a;
  int b;
  cin >> a >> b;

  cout << a << "+" << b << "=" << a + b << endl;
  cout << a << "-" << b << "=" << a - b << endl;
  cout << a << "*" << b << "=" << a * b << endl;
  cout << a << "/" << b << "=" << fixed << setprecision(4) << (double)a / (double)b << endl;
  cout.unsetf(ios::fixed);
  cout << a << "%" << b << "=" << a % b << endl;
  return 0;
}
