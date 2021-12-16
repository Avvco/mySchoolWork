#include <bits/stdc++.h>

using namespace std;

template <class WHAT_THE_HELL>
class Node {
public:
  Node(WHAT_THE_HELL data, Node *left, Node *right) {
    this -> data = data;
    this -> left = left;
    this -> right = right;
  }
  WHAT_THE_HELL data;
	int level;
	Node *left, *right;
  Node *prev = NULL;
  Node *next = NULL;
};

template <class I_AM_TIRED>
class Linked_List {
  public:
    Linked_List(Node<I_AM_TIRED> *node) {
      head = node;
      tail = node;
    }
    void add(Node<I_AM_TIRED> *node) {
      tail -> next = node;
      node -> prev = tail;
      tail = node;
    }
    Node<I_AM_TIRED> *getHead() {
      return head;
    }
    void literal() {
      Node<I_AM_TIRED> *current = head;
      while(current) {
        cout << current -> data << " ";
        current = current -> next;
      }
    }

  private:
    Node<I_AM_TIRED> *head;
    Node<I_AM_TIRED> *tail;
};

template <class I_WANT_TO_SLEEP>
class Base_List {
  public:
    Base_List() {
      next = NULL;
      data = NULL;
    }
    Base_List(Node<I_WANT_TO_SLEEP> *node) {
      next = NULL;
      data = new Linked_List<I_WANT_TO_SLEEP>(node);
    }

    void add(Base_List<I_WANT_TO_SLEEP> *current, Node<I_WANT_TO_SLEEP> *node) {
      Base_List<I_WANT_TO_SLEEP> *exist = find(current, node -> data);
      if(exist) {
        exist -> getData() -> add(node);
      }else {
        Base_List<I_WANT_TO_SLEEP> *Blist = new Base_List<I_WANT_TO_SLEEP>(node);
        while(current -> getNext()) {
          current = current -> getNext();
        }
        current -> setNext(Blist);
      }
    }

    Base_List<I_WANT_TO_SLEEP> *find(Base_List<I_WANT_TO_SLEEP> *current, I_WANT_TO_SLEEP data) {
      current = current -> getNext();
      while(current) {
        if(current -> getData() -> getHead() -> data == data) {
          return current;
        }
        current = current -> getNext();
      }
      return NULL;
    }

    void literal(Base_List<I_WANT_TO_SLEEP> *current) {
      current = current -> getNext();
      while (current) {
        current -> getData() -> literal();
        current = current -> getNext();
        cout << endl;
      }
    }
    Base_List<I_WANT_TO_SLEEP> *getNext() {
      return next;
    }
    void setNext(Base_List<I_WANT_TO_SLEEP> *next) {
      this -> next = next;
    }

    Linked_List<I_WANT_TO_SLEEP> *getData() {
      return data;
    }

  private:
    Base_List<I_WANT_TO_SLEEP> *next;
    Linked_List<I_WANT_TO_SLEEP> *data;
};


template <class ZZzzz>
class Tree {
public:
  Tree() {
    root = NULL;
  }
	Tree(int amount) {
		root = NULL;
    //cout<<typeid(ZZzzz).name();
	}
	void insert(ZZzzz data) {
    Node<ZZzzz> *node = new Node<ZZzzz>(data, NULL, NULL);
		insert(&root, node, 0);
	}
  // ======
	void levelorder(Base_List<ZZzzz> *list = NULL) {
    if (root == NULL) {
      return;
    }
    // Create an empty queue for level order traversal
    queue<Node<ZZzzz> *> q;

    // Enqueue Root and initialize height
    q.push(root);

    while (q.empty() == false) {
      // Print front of queue and remove it from queue
      Node<ZZzzz> *node = q.front();
      if(list) {
        list -> add(list, node);
      }
      if(!list) {
        cout << "Data: " <<node -> data << "\t" << "Level: " <<node -> level <<endl;
      }

      q.pop();

      /* Enqueue left child */
      if (node->left != NULL) {
        q.push(node->left);
      }
      /*Enqueue right child */
      if (node->right != NULL) {
        q.push(node->right);
      }
    }
	}
private:
	Node<ZZzzz> *root;
	void insert(Node<ZZzzz> **r, Node<ZZzzz> *n, int lev) {
		if(*r == NULL) {
      n -> level = lev;
      *r = n;
    }
		else if(n->data > (*r)->data) {
      insert(&((*r)->right), n, lev + 1);
    }
		else {
      insert(&((*r)->left), n, lev + 1);
    }
	}
};

int main(int argc, char const *argv[]) {
  srand(time(NULL));
  Tree<int> *tree = new Tree<int>();
  for(int j = 0 ; j < 50 ; j ++) {
    if(j<5) {
      tree -> insert(rand());
    }else if(j<7) {
      tree -> insert(55);
    }else if(j<10) {
      tree -> insert(77);
    }else if(j<16) {
      tree -> insert(33);
    }else if(j<20) {
      tree -> insert(999);
    }else {
      tree -> insert(rand());
    }
  }
	tree -> levelorder();
  cout<<endl;
  Base_List<int> *list = new Base_List<int>();
  tree -> levelorder(list);
  list -> literal(list);
	cout << endl;
  return 0;
}
