// http://134.208.3.66/problem/PR-1092Q21

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>

using namespace std;

class Decode
{
  public:

    //Constructor
    Decode(string str) {
      this -> str = str;
    }
    string decode() {
      unsigned int current = 0;
      string decoded;
      while(current < str.size()) {
        char decoding[3];
        for (size_t j = 0 ; j < 3 ; j++) {
          decoding[j] = str[current + j];
        }
        int _decoding = atoi(decoding);
        decoded = decoded + (char)_decoding;
        current = current + 3;
      }
      return decoded;
    }

  private:
    string str;
};

int main() {
  string str;
  cin >> str;
  Decode *code = new Decode(str);
  cout << code -> decode();
  return 0;
}
