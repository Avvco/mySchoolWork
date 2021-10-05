#include <bits/stdc++.h>
using namespace std;


class Tower {
  public:
    Tower(int current, Tower *prev) {
      this -> prev = prev;
      this -> next = NULL;
      this -> current = current;
    }
    Tower(int current) {
      this -> prev = NULL;
      this -> next = NULL;
      this -> current = current;
    }

  int getCurrent() {
    return current;
  }
  Tower *getPrev() {
    return prev;
  }
  Tower *getNext() {
    return next;
  }

  void setCurrent(int current) {
    this -> current = current;
  }
  void setPrev(Tower *prev) {
    this -> prev = prev;
  }
  void setNext(Tower *next) {
    this -> next = next;
  }

  private:
    int current;
    Tower *prev;
    Tower *next;
};
Tower *A = new Tower(0);
Tower *As = A;
Tower *B = new Tower(0);
Tower *Bs = B;
Tower *C = new Tower(0);
Tower *Cs = C;

Tower *getTower(char c, int mode) {
  if(mode == 0) {
    switch (c) {
      case 'A':
        return As;
      case 'B':
        return Bs;
      case 'C':
        return Cs;
    }
  }
  switch (c) {
    case 'A':
      return A;
    case 'B':
      return B;
    case 'C':
      return C;
  }
  return NULL;
}

void setBackTower(char from, Tower *tower) {
  switch (from) {
    case 'A':
      A = tower;
      return;
    case 'B':
      B = tower;
      return;
    case 'C':
      C = tower;
      return;
  }
}
void printCurrent(char c) {
  cout << c;
  Tower *current = getTower(c, 0);
  while(current->getNext()) {
    current = current -> getNext();
    cout << current -> getCurrent();
  }
  cout << endl;
}
void printCurrent(Tower *current) {
  cout << current -> getCurrent();
  while(current->getPrev()) {
    current = current -> getPrev();
    cout << current -> getCurrent();
  }
  cout << endl;
}

void change(char from_rod, char to_rod, int mode) {
  Tower *from = getTower(from_rod, 1);

  Tower *to = getTower(to_rod, 1);
  Tower *_t = new Tower(from->getCurrent(), to);
  to -> setNext(_t);
  to = to -> getNext();
  from = from -> getPrev();
  from -> setNext(NULL);


  setBackTower(from_rod, from);
  setBackTower(to_rod, to);
  printCurrent('A');
  printCurrent('B');
  printCurrent('C');
  cout << endl;
}

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)
{
    if (n == 1)
    {
        // cout << "Move disk 1 from rod " << from_rod << " to rod " << to_rod<<endl;
        change(from_rod, to_rod, 1);
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    // cout << "Move disk " << n << " from rod " << from_rod << " to rod " << to_rod << endl;
    change(from_rod, to_rod, 1);

    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main()
{
    int count = 5;
    for(int i = count ; i > 0 ; i--) {
      Tower *current = new Tower(i, A);
      A->setNext(current);
      A = A -> getNext();
    }
    printCurrent('A');
    printCurrent('B');
    printCurrent('C');
    cout << endl;
    int n = count; // Number of disks
    towerOfHanoi(n, 'A', 'C', 'B'); // A, B and C are names of rods
    return 0;
}
