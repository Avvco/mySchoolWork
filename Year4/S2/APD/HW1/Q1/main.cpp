#include <iostream>
#include <fstream>

using namespace std;

int main() {
  string s1;
  string s2;
  cout << "Enter the first string: ";
  cin >> s1;
  cout << "Enter the second string: ";
  cin >> s2;

  // concate first half string of s1 and second half string of s2 into s3
  string s3 = s1.substr(0, s1.length() / 2) + s2.substr(s2.length() / 2);
  cout << "The new string is: " << s3 << endl;

  ofstream myfile;
  myfile.open ("1.txt");
  myfile << "The processed string is:" << endl << s3;
  myfile.close();
}