
#include<iostream>
#include<cstdlib>

using namespace std;

class Node {
  public:
    Node() {
      data = 0;
      next = NULL;
    }
    int data;
    Node *next;
};

class Set {
  public:
    Set() {
      element = NULL;
      start = NULL;
    }

    int addElement(int e) {
      Node *node = new Node();
      node -> data = e;
      if(element == NULL) {
        element = node;
        start = node;
        return 1;
      }
      Node *current = start;
      while(current) {
        if(current -> data == e) return -1;
        current = current -> next;
      }
      element -> next = node;
      element = element -> next;
      return 1;
    }

    Set *setUnions(const Set *b) {
      Set *set = new Set();
      Node *node1 = getElement();
      Node *node2 = b -> getElement();
      while(node1) {
        set -> addElement(node1 -> data);
        node1 = node1 -> next;
      }
      while (node2) {
        set -> addElement(node2 -> data);
        node2 = node2 -> next;
      }
      return set;
    }

    Set *setIntersections(const Set *b) {
      Set *set = new Set();
      Node *node1 = getElement();
      while(node1) {
        Node *node2 = b -> getElement();
        while (node2) {
          if((node1 -> data) == (node2 -> data)) {
            set -> addElement(node1 -> data);
          }
          node2 = node2 -> next;
        }
        node1 = node1 -> next;
      }
      return set;
    }

    Set *setDifference(const Set *b) {
      Set *set = new Set();
      Node *node1 = getElement();
      Node *node2 = b -> getElement();
      while(node1) {
        if(!_equivalent(node1 -> data, node2)) {
          set -> addElement(node1 -> data);
        }
        node1 = node1 -> next;
      }
      node1 = getElement();
      /*
      while(node2) {
        if(!_equivalent(node2 -> data, node1)) {
          set -> addElement(node2 -> data);
        }
        node2 = node2 -> next;
      }
      */
      return set;
    }

    bool equivalent(const Set *b) {
      Node *node1 = getElement();
      Node *node2 = b -> getElement();

      while(node1) {
        if(!_equivalent(node1 -> data, node2)) return false;
        node1 = node1 -> next;
      }
      while(node2) {
        if(!_equivalent(node2 -> data, node1)) return false;
        node2 = node2 -> next;
      }

      return true;
    }

    void listAll() {
      Node *cur = start;
      while(cur != NULL)
      {
        cout<<cur->data<<" ";
        cur = cur->next;
      }
      cout<<endl;
    }
    Node *getElement() const {
      return start;
    }
    bool _equivalent(int x, Node *node) {
      while(node) {
        if(node -> data == x) return true;
        node = node -> next;
      }
      return false;
    }
  private:
    Node *element;
    Node *start;
};

int main() {
  Set *a = new Set();
  Set *b = new Set();
  Set *c;

  a->addElement(1);
  a->addElement(2);
  a->addElement(3);
  b->addElement(3);
  b->addElement(4);
  b->addElement(5);
  b->addElement(5);

  c = a->setUnions(b);
  c->listAll();

  c = a->setIntersections(b);
  c->listAll();

  c = a->setDifference(b);
  c->listAll();

  if(a->equivalent(b) == 0) {
    cout<<"Not equivalent.\n";
  }
  else {
    cout<<"Equivalent!\n";
  }
}
