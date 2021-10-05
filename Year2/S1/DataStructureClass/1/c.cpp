#include <bits/stdc++.h>
using namespace std;


class Dictionary {
  public:
    Dictionary() {
      for (int i = 97; i <= 122; i++) {
        alpha.insert(pair<char, int>(char(i), 0));
      }
    }
    find_add(char c) {
      map<char, int>::iterator iter;
      iter = alpha.find(c);
      iter -> second++;
      return 0;
    }
    print() {
      for (const auto& _alpha : alpha) {
        if(_alpha.second == 0) continue;

        cout << _alpha.first << " ";
        for (int i = 0; i < _alpha.second; i++) {
          cout << "*";
        }
         cout << _alpha.second << endl;
      }
      return 0;
    }
  private:
    map<char, int> alpha;

};
int main(int argc, char const *argv[]) {
  string str;
  Dictionary d;
  ifstream ReadFile("./forC.txt");
  while (getline (ReadFile, str)) {

    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    for (int i = 0; i < str.length(); i++) {
      d.find_add(str[i]);
    }
    d.print();
  }
  return 0;
}
