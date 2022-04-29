#include <bits/stdc++.h>

using namespace std ;

class C {
  public :
    C() {
      length = 0;
    }
    vector<string> s_original;
    string s_reduced;
    int length;
};

void display (vector<string> s) {
  for(auto _s : s) {
    cout << _s << " ";
  }
  cout << endl;
}

string combine(string s1, string s2) {
  string _s1;
  string _s1f = "";
  if(s1.length() <= s2.length()) {
    _s1 = s1;
  }else {
    _s1 = s1.substr(s1.length()-s2.length(), s1.length());
    _s1f = s1.substr(0, s1.length()-s2.length());
  }

  int overlapEndIndex = 0;
  for(int i = 0; i < _s1.length(); i++) {
    bool overlapFound = false;
    if(_s1[i] == s2[0]) {
      overlapFound = true;
      int current = i;
      for(int j = 0 ; j + i < _s1.length() ; j++) {
         overlapEndIndex = j + 1;
        if(_s1[current + j] != s2[j]) {
          overlapFound = false;
          break;
        }
      }
      if(!overlapFound) overlapEndIndex = 0;
    }
  }
  
   
  //cout<<s1<<" " << s2 << " " <<_s1 << " " << _s1f << " " << overlapEndIndex <<endl;
  return _s1f + _s1 + s2.substr(overlapEndIndex, s2.length());
}

int main(int argc, char const **argv) {
  int wordsCount;
  cin >> wordsCount;
  vector<string> word;

  for (int i = 0; i < wordsCount; i++) {
    string _word;
    cin >> _word;
    word.push_back(_word);
  }
  int maxLength = 0;

  for (auto w : word) {
    maxLength = maxLength + w.length();
  }

  vector<C> dp(maxLength + 1);

  do{
    string currentWord = "";
    for(auto w : word) {
      //cout<<currentWord<<" " << w << " ";
      currentWord = combine(currentWord, w);
      
    }
    //display(word);
    //cout<<currentWord.length()<<endl;
    dp[currentWord.length()].s_reduced = currentWord;
    dp[currentWord.length()].s_original= word;
    dp[currentWord.length()].length = currentWord.length();
    
    //cout<<currentWord<< " " << currentWord.length() <<endl <<endl;

  } while(next_permutation(word.begin(), word.end()));

  /*for(int i = 0 ; i < dp.size() ; i++) {
    cout<<dp[i].length<<endl;
  }*/

  for(auto d : dp) {
    if(d.length != 0) {
      cout<<d.length<<endl;
      display(d.s_original);
      cout<<d.s_reduced<<endl;
      break;
    }
  }
  return 0 ;
}