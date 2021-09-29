// http://134.208.3.66/problem/PR109-2-01-4

using namespace std;
#include <iostream>

int main(int argc, char const *argv[]) {
  int a, s, n;
  cin >> a >> s >> n;

  for (int i = 1 ; i <= n ; i++) {
    cout << "a[" << i << "]=" << a << endl;
    a = a + s; 
  }
  return 0;
}
