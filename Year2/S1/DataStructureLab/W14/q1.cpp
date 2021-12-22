#include<iostream>
#include<string>
#include <map>

using namespace std;

class Child {
  public:
    Child(char data) {
      this -> data = data;
      this -> next = nullptr;
      this -> child = nullptr;
      this -> end = false;
    }
    char getData() {
      return data;
    }
    Child *next;
    Child *child;
    bool end;
  private:
    char data;
};

class Tree {
  public:
    Tree() {
      root = nullptr;
    }
    void insert(string word) {

      insert(word, &root, true);
    }
    int search(string word) {
      Child *current = root;
      bool ended;
      for(char w : word) {
        Child *currentLevel = current;
        while(true) {
          ended = false;
          if(currentLevel == nullptr) return 0;
          if(w == currentLevel -> getData()) {
            ended = currentLevel -> end;
            current = currentLevel -> child;
            break;
          }
          currentLevel = currentLevel -> next;
        }
      }
      if(ended) return 1;
      return 0;
    }

  private:
    Child *root;
    void insert(string word, Child **current, bool existed) {
      if(word.length() <= 0) return;
      char w = word[0];
      if((*current) == NULL) {
        (*current) = new Child(w);
        if(word.length() == 1) (*current) -> end = true;
        insert(word.substr(1,word.length()), &((*current) -> child), false);
      }else {
        bool repeated = (*current) -> getData() == w;
        if(existed && !repeated) {
          insert(word, &((*current) -> next), true);
        }else {
          if(word.length() == 1) (*current) -> end = true;
          insert(word.substr(1,word.length()), &((*current) -> child), repeated);
        }
      }
    }
};

int main() {
    Tree *tree = new Tree();
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
      string word;
      cin >> word;
      tree -> insert(word);
    }
    for(int i = 0 ; i < m; i++) {
      string word;
      cin >> word;
      cout << tree -> search(word) << endl;
    }
}
