#include <bits/stdc++.h>

using namespace std;

class Dictionary {
  public:
    Dictionary() {
      contains = 0;
      for (int i = 97; i <= 122; i++) {
        alpha.insert(pair<char, int>(char(i), 0));
      }
      for (int i = 65; i <= 90; i++) {
        alpha.insert(pair<char, int>(char(i), 0));
      }
    }

    map<char, int>::iterator find(char c) {
      map<char, int>::iterator iter;
      iter = alpha.find(c);
      return iter;
    }
    int add(map<char, int>::iterator iter) {
      if(iter -> second == 0) contains++;
      iter -> second++;
      return 0;
    }
    void print() {
      for (const auto& _alpha : alpha) {
        if(_alpha.second == 0) continue;

        cout << _alpha.first << " ";
        for (int i = 0; i < _alpha.second; i++) {
          cout << "*";
        }
         cout << _alpha.second << endl;
      }
      return;
    }
    int getContains() {
      return contains;
    }
  private:
    map<char, int> alpha;
    int contains;
};

int subcompare(Dictionary a, Dictionary b, int mode) {
  int common = 0;
  if(mode == 0) {
    for (int i = 97; i <= 122; i++) {
      if((a.find(char(i)) -> second != 0) != (b.find(char(i)) -> second != 0)) return 0;
    }
    for (int i = 65; i <= 90; i++) {
      if((a.find(char(i)) -> second != 0) != (b.find(char(i)) -> second != 0)) return 0;
    }
  }else if(mode == 1) {
    for (int i = 97; i <= 122; i++) {
      if(a.find(char(i)) -> second < b.find(char(i)) -> second) return 0;
    }
    for (int i = 65; i <= 90; i++) {
      if(a.find(char(i)) -> second < b.find(char(i)) -> second) return 0;
    }
  }else if(mode == 2) {
    for (int i = 97; i <= 122; i++) {
      if((a.find(char(i)) -> second != 0) != (b.find(char(i)) -> second != 0)) common++;
    }
    for (int i = 65; i <= 90; i++) {
      if((a.find(char(i)) -> second != 0) != (b.find(char(i)) -> second != 0)) common++;
    }
  }
  if(common != 0) return 2;
  return 1;
}


int compareWordSets(Dictionary a, Dictionary b) {
  if(a.getContains() == b.getContains() && subcompare(a, b, 0) == 1) return 0;
  if(subcompare(a, b, 1) == 1) return 1;
  if(subcompare(b, a, 1) == 1) return -1;
  if(subcompare(a, b, 2) == 2) return INT_MAX;
  return 3;
}


int main(int argc, char const *argv[]) {
  string a = "fasdiuhasdfhuasdfuiohlawfyuoasdf";
  string b = "qeyuieqwyuqweyuoiooyfasdhjasdfhuioasdy";
  string c = "abcdee";
  string d = "abcdeee";
  Dictionary A;
  Dictionary B;
  Dictionary C;
  Dictionary D;
  for (size_t i = 0; i < a.length(); i++) {
    A.add(A.find(a[i]));
  }
  for (size_t i = 0; i < b.length(); i++) {
    B.add(B.find(b[i]));
  }
  for (size_t i = 0; i < c.length(); i++) {
    C.add(C.find(c[i]));
  }
  for (size_t i = 0; i < d.length(); i++) {
    D.add(D.find(d[i]));
  }
  cout << compareWordSets(C, D) << endl;
  return 0;
}
