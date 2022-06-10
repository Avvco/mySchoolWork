#include <bits/stdc++.h>

using namespace std;

string largestNumber(vector<int> &num) {
  vector<string> arr;
  for(auto i : num) {
    arr.push_back(to_string(i));
  }
  sort(begin(arr), end(arr), [](string &a, string &b) {return a+b>b+a;});
  string res;
  for(auto s : arr) {
    res+=s;
  }
  while (res[0] == '0' && res.length() > 1) {
    res.erase(0, 1);
  }
  return res;
} 

int main() {
  vector<int> num = {0, 0, 0};
  cout << largestNumber(num) << endl;
  num = {1, 23, 456, 789, 101112};
  cout << largestNumber(num) << endl;
  num = {1, 2, 3, 4, 5};
  cout << largestNumber(num) << endl;
  return 0;
}