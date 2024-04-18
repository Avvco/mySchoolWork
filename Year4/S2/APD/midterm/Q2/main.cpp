#include <iostream>
#include <string>

using namespace std;

int main() {
  string str;
  cout << "Enter a string: ";
  cin >> str;

  // convert uppercase to lowercase and vice versa
  for(int i = 0; i < str.length(); i++) {
    if(str[i] >= 'A' && str[i] <= 'Z') {
      str[i] += 32;
    } else if(str[i] >= 'a' && str[i] <= 'z') {
      str[i] -= 32;
    }
  }
  cout << "The string after converting uppercase to lowercase and vice versa: " << str << endl;

  string str2;
  cout << "Enter another string: ";
  cin >> str2;
  
  // check if str contains str2
  if(str.find(str2) != string::npos) {
    cout << "The first string contains the second string." << endl;
  } else {
    cout << "The first string does not contain the second string." << endl;
  }
}