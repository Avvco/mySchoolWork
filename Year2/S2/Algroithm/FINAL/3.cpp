#include <bits/stdc++.h>

using namespace std;

string findSubstring(string s, string t) {
  vector<int> Map(128, 0);
  for(auto c : t) Map[c]++;
  int counts = t.size(), Start = 0, End = 0, d = INT_MAX, head = 0;
  while(End < s.size()) {
    if(Map[s[End]] > 0) counts--;
    Map[s[End]]--;
    End++;
    while(!counts) {
      if(End - Start < d) d = End - (head = Start);
      if(!Map[s[Start]]) counts++;
      Map[s[Start]]++;
      Start++;
    }
  }
  return d == INT_MAX ? "" : s.substr(head, d);
}

int main() {
  string s = "gocodeiscool";
  string t = "goose";
  cout << findSubstring(s, t) << endl;
  s = "xxxxyxyyyzyzzzz";
  t = "zzxxy";
  cout << findSubstring(s, t) << endl;
  s = "abcdefg";
  t = "cdex";
  cout << findSubstring(s, t);
  return 0;
}