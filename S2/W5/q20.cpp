// http://134.208.3.66/problem/PR109-2Q20
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>

using namespace std;

class Encode
{
  public:

    // Constructor
    Encode(string str) {
      this -> str = str;
    }
    
    string encode() {
      string encoded;
      for (size_t i = 0 ; i < str.size() ; i++) {
        string encoding = to_string(int(str[i]));
        if(encoding.size() == 2) {
          encoded = encoded + '0' + encoding;
        }else if(encoding.size() == 3) {
          encoded = encoded + encoding;
        }
        else if(encoding.size() == 1) {
          encoded = encoded + '0' + '0' + encoding;
        }
      }
      return encoded;
    }

  private:
    string str;
};

int main() {
  string str;
  getline(cin, str);
  Encode *code = new Encode(str);
  cout << code -> encode();
  return 0;
}
/*
int main() {
  string str;
  cin >> str;
  Encode *code = new Encode(str);
  cout << code -> encode();
  return 0;
}
*/
