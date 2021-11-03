#include <bits/stdc++.h>

using namespace std;

class Node {
  public:
    Node() {
      next = NULL;
      prev = NULL;
    }
    Node(int data) {
      next = NULL;
      prev = NULL;
      this -> data = data;
    }
    int getData() {
      return data;
    }
    Node *getNext() {
      return next;
    }
    Node *getPrev() {
      return prev;
    }
    void setNext(Node *next) {
      this -> next = next;
    }
    void setPrev(Node *prev) {
      this -> prev = prev;
    }
  private:
    Node *next;
    Node *prev;
    int data;
};

class DEQ { // double ended queue
  public:
    DEQ() {
      front = NULL;
      end = NULL;
    }
    ~DEQ() {
      cout << "deconstructed" << endl;
    }

    bool IsEmpty() {
      if(!front && !end) return true;
      return false;
    }
    bool IsFull() {
      return false;
    }
    void AddFront(int x) {
      Node *node = new Node(x);
      if(!front) {
        front = node;
      }else {
        node -> setNext(front);
        front -> setPrev(node);
        front = node;
      }
      if(!end) {
        end = node;
      }
    }
    void AddRear(int x) {
      Node *node = new Node(x);
      if(!front) {
        front = node;
      }
      if(!end) {
        end = node;
      }else {
        node -> setPrev(end);
        end -> setNext(node);
        end = node;
      }
    }
    void DeleteFront() {
      if(CheckFront()) {
        front = front -> getNext();
        front -> setPrev(NULL);
      }
    }
    void DeleteRear() {
      if(CheckRear()) {
        end = end -> getPrev();
        end -> setNext(NULL);
      }
    }
    bool CheckFront() {
      if(front -> getNext()) return true;
      return false;
    }
    bool CheckRear() {
      if(end -> getPrev()) return true;
      return false;
    }
    DEQ *Reverse() {
      DEQ *deq = new DEQ();
      while(end) {
        deq -> AddRear(end -> getData());
        end = end -> getPrev();
      }
      return deq;
    }

    void printFromFront() {
      Node *node = front;
      while(node) {
        cout << node -> getData() << " ";
        node = node -> getNext();
      }
      cout << endl;
    }

  private:
    Node *front;
    Node *end;
};

int main(int argc, char const *argv[]) {
  DEQ *deq = new DEQ();
  deq -> AddRear(1);
  deq -> printFromFront();
  deq -> AddRear(2);
  deq -> printFromFront();
  deq -> AddRear(3);
  deq -> printFromFront();
  deq -> AddFront(4);
  deq -> printFromFront();
  deq -> AddFront(5);
  deq -> printFromFront();
  deq -> AddFront(6);
  deq -> printFromFront();
  deq -> AddRear(7);
  deq -> printFromFront();
  deq -> AddFront(8);
  deq -> printFromFront();
  deq -> DeleteRear();
  deq -> printFromFront();
  deq -> DeleteFront();
  deq -> printFromFront();
  deq -> DeleteRear();
  deq -> printFromFront();
  deq -> DeleteFront();
  deq -> printFromFront();
  deq = deq -> Reverse();
  deq -> printFromFront();
  return 0;
}
