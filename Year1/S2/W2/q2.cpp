using namespace std;
#include <iostream>
#include <string>

int main(int argc, char const *argv[]) {
  string str;
  cin >> str;
  for (int i = str.length() - 1 ; i >= 0 ; i--) {
    cout << str[i];
  }
  return 0;
}
