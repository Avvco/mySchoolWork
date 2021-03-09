// http://134.208.3.66/problem/PR109-2-01-3

using namespace std;
#include <iostream>
#include <string>

int main(int argc, char const *argv[]) {
  string str;
  cin >> str;

  for (int i = str.size() - 1; i >= 0 ; i--) {
    cout << static_cast<char>(toupper(str[i]));
  }
  return 0;
}
