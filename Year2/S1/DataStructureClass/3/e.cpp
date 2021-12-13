#include <bits/stdc++.h>

using namespace std;

template <class WHATREE_TREEHE_HELL>
class Node {
public:
  Node(WHATREE_TREEHE_HELL data, Node *left, Node *right) {
    this -> data = data;
    this -> left = left;
    this -> right = right;
  }
  WHATREE_TREEHE_HELL data;
	int level;
	Node *left, *right;
  Node *prev = NULL;
  Node *next = NULL;
};

template <class I_DONT_KNOW>
class Linked_List {
  public:
    Linked_List(Node<I_DONT_KNOW> *node) {
      head = node;
      tail = node;
    }
    void add(Node<I_DONT_KNOW> *node) {
      tail -> next = node;
      node -> prev = tail;
      tail = node;
    }
    Node<I_DONT_KNOW> *getHead() {
      return head;
    }
    void literal() {
      Node<I_DONT_KNOW> *current = head;
      while(current) {
        cout << head -> data << " ";
        current = current -> next;
      }
    }

  private:
    Node<I_DONT_KNOW> *head;
    Node<I_DONT_KNOW> *tail;
};

template <class I_DONT_KNOW>
class Base_List {
  public:
    Base_List() {
      next = NULL;
      data = NULL;
    }
    Base_List(Node<I_DONT_KNOW> *node) {
      next = NULL;
      data = new Linked_List<I_DONT_KNOW>(node);
    }

    void add(Base_List<I_DONT_KNOW> *current, Node<I_DONT_KNOW> *node) {
      Base_List<I_DONT_KNOW> *exist = find(current, node -> data);
      if(exist) {
        exist -> getData() -> add(node);
      }else {
        Base_List<I_DONT_KNOW> *Blist = new Base_List<I_DONT_KNOW>(node);
        while(current -> getNext()) {
          current = current -> getNext();
        }
        current -> setNext(Blist);
      }
    }

    Base_List<I_DONT_KNOW> *find(Base_List<I_DONT_KNOW> *current, I_DONT_KNOW data) {
      current = current -> getNext();
      while(current) {
        if(current -> getData() -> getHead() -> data == data) {
          return current;
        }
        current = current -> getNext();
      }
      return NULL;
    }

    void literal(Base_List<I_DONT_KNOW> *current) {
      current = current -> getNext();
      while (current) {
        current -> getData() -> literal();
        current = current -> getNext();
        cout << endl;
      }
    }
    Base_List<I_DONT_KNOW> *getNext() {
      return next;
    }
    void setNext(Base_List<I_DONT_KNOW> *next) {
      this -> next = next;
    }

    Linked_List<I_DONT_KNOW> *getData() {
      return data;
    }

  private:
    Base_List<I_DONT_KNOW> *next;
    Linked_List<I_DONT_KNOW> *data;
};


template <class TREE>
class Tree {
public:
  Tree() {}
	Tree(int amount) {
		root = NULL;
    //cout<<typeid(TREE).name();
	}
	void insert(TREE data) {
    Node<TREE> *node = new Node<TREE>(data, NULL, NULL);
		insert(&root, node, 0);
	}
  // ======
	void levelorder(Base_List<int> *list = NULL) {
    if (root == NULL) {
      return;
    }
    // Create an empty queue for level order traversal
    queue<Node<TREE> *> q;

    // Enqueue Root and initialize height
    q.push(root);

    while (q.empty() == false) {
      // Print front of queue and remove it from queue
      Node<TREE> *node = q.front();
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
	Node<TREE> *root;
	void insert(Node<TREE> **r, Node<TREE> *n, int lev) {
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
  for(int j = 0 ; j < 30 ; j ++) {
    if(j<5) {
      tree -> insert(99);
    }else if(j<7) {
      tree -> insert(55);
    }else if(j<10) {
      tree -> insert(77);
    }else if(j<16) {
      tree -> insert(33);
    }else {
      tree -> insert(rand());
    }
  }
	tree -> levelorder();
  Base_List<int> *list = new Base_List<int>();
  tree -> levelorder(list);
  list -> literal(list);
	cout << endl;
  return 0;
}
