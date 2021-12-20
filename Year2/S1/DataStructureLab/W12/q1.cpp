#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <ctime>
#include <queue>

using namespace std;

template<class T>
class Node {
public:
	Node() {
		data = new T;
	}
	Node(T d) {
		data = new T;
		(*data) = d;
	}
	Node &operator=(T d) {
		(*data) = d;
		return *this;
	}
	friend std::ostream &operator<<(std::ostream &out, Node n) {
		out<<*(n.data);
		return out;
	}
	friend std::ostream &operator<<(std::ostream &out, Node *n) {
		out<<*(n->data);
		return out;
	}
	void setData(T d) {
		*data = d;
	}
	T &getData() const {
		return *data;
	}
protected:
	T *data;
};


template<class T>
class ListNode : public Node<T> {
public:
	ListNode() : Node<T>() {
		prev = NULL;
		next = NULL;
	}
	ListNode(T d) : Node<T>(d) {
		prev = NULL;
		next = NULL;
    //cout<<typeid(T).name();
	}
	ListNode(ListNode *p, ListNode *n) : Node<T>() {
		prev = p;
		next = n;
	}
	ListNode(T d, ListNode *p, ListNode *n) : Node<T>(d) {
		prev = p;
		next = n;
	}
	ListNode *getNext() const {
		return next;
	}
	ListNode *getPrev() const {
		return prev;
	}
	void setNext(ListNode *n) {
		next = n;
	}
	void setPrev(ListNode *p) {
		prev = p;
	}
	ListNode &operator=(T d) {
		this->setData(d);
		return *this;
	}
private:
	ListNode *prev, *next;
};


template<class T>
class LinkList {
public:
	LinkList() {
		head = NULL;
		tail = NULL;
    size = 0;
	}
	void addFromHead(T d) {
    size++;
		ListNode<T> *node = new ListNode<T>(d);
		if(head != NULL) {
			head->setPrev(node);
		}
		node->setNext(head);
		head = node;
		if(tail == NULL){
      tail = node;
    }
	}
	void addFromTail(T d) {
    size++;
		ListNode<T> *node = new ListNode<T>(d);
		if(tail != NULL) {
			tail->setNext(node);
		}
		node->setPrev(tail);
		tail = node;
		if(head == NULL) {
      head = node;
    }
	}
	void addAfter(ListNode<T> *at, T d) {
		if(!exist(at)) return;
    size++;
		ListNode<T> *node = new ListNode<T>(d);
		if(at->getNext() != NULL){
      at->getNext()->setPrev(node);
    }
		node->setNext(at->getNext());
		at->setNext(node);
		node->setPrev(at);
		if(node->getNext() == NULL) {
      tail = node;
    }
	}
	ListNode<T> *removeFromHead() {
    size--;
		ListNode<T> *n = head;
		if(head != NULL) {
			head = head->getNext();
			if(head != NULL) {
        head->setPrev(NULL);
      }
			else {
        tail = NULL;
      }
			n->setNext(NULL);
		}
		return n;
	}
	ListNode<T> *removeFromTail() {
    size--;
		ListNode<T> *n = tail;
		if(tail != NULL) {
			tail = tail->getPrev();
			if(tail != NULL) {
        tail->setNext(NULL);
      }
			else {
        head = NULL;
      }
			n->setPrev(NULL);
		}
		return n;
	}
	ListNode<T> *remove(ListNode<T> *n) {
		if(!exist(n)) return NULL;
    size--;
		if(n == head) return removeFromHead();
		if(n == tail) return removeFromTail();

		n->getPrev()->setNext(n->getNext());
		n->getNext()->setPrev(n->getPrev());
		n->setNext(NULL);
		n->setPrev(NULL);
		return n;
	}

	ListNode<T> *exist(T d) {
		ListNode<T> *j = head;
		while(j != NULL) {
			if(j->getData() == d) return j;
			j = j->getNext();
		}
		return NULL;
	}

	bool exist(ListNode<T> *n) {
		ListNode<T> *j = head;
		while(j != NULL) {
			if(j == n) return true;
			j = j->getNext();
		}
		return false;
	}
	ListNode<T> &operator[](int i) {
		ListNode<T> *j = head;
		int k;
		for(k = 0;k < i && j != NULL;k ++) {
      j = j->getNext();
    }
		if(j == NULL) {
			throw std::invalid_argument("index does not exist.");
		}
		return *j;
	}
	void print() const {
		ListNode<T> *j;
		j = head;
		while(j != NULL) {
			std::cout<<(*j)<<" ";
			j = j->getNext();
		}
		std::cout<<std::endl;
	}
  ListNode<T> *getHead() {
    return head;
  }
  int getSize() {
    return size;
  }
protected:
	ListNode<T> *head, *tail;
  int size;
};

/*
	Please finish the TreeNode class, TreeNode class respresent a node in a general tree.
	A general tree is different from binary tree, every node in binary tree have at most two child node, but a node in general tree may have more than two child node.
*/
template<class T>
class TreeNode : public Node<T> {
public:
	TreeNode() : Node<T>() {
    child = new LinkList<TreeNode<T> *>;
	}
	TreeNode(T d) : Node<T>(d) {
    child = new LinkList<TreeNode<T> *>;
	}
	/*
		Add a child to this node.
	*/
	void addChild(TreeNode *n) {
    child -> addFromTail(n);
	}
	/*
		Add a child to this node.
	*/
	void addChild(T d) {
    addChild(new TreeNode<T> (d));
	}
	/*
		Return the nth child of the node.
	*/
	TreeNode<T> *operator[](int n) {
    return (*child)[n].getData();
	}

  LinkList<TreeNode<T> *> *getChild() {
    return child;
  }
  size_t size() {
    return child -> getSize();
  }
private:
	LinkList<TreeNode<T> *> *child;
};

/*
	Please finish the Tree class. Tree class respresent a general tree, that means node on this tree may have more than two child node.

*/
template<class T>
class Tree {
public:
	Tree() {
    root = NULL;
	}
	/*
		return the nth node on this tree with level order.
	*/
	TreeNode<T> *operator[](int n) {
    if (root == NULL) return NULL;
  	queue<TreeNode<T> *> q;
    q.push(this->root);
    int k = 0;
    while (!q.empty()) {
      TreeNode<T> *current = q.front();
      q.pop();
      if (k == n) return current;
      for (size_t i = 0; i < current -> size(); i++) {
        q.push((*current)[i]);
      }
      k++;
    }
    return NULL;
	}
	/*
		return the number of nodes on this tree.
	*/
	int count() {
    return levelOrder(1);
	}
	/*
		print all the node on this tree with level order.
	*/
	int levelOrder(int mode = 0) {
		if (root == NULL) return 0;
		if(mode == 0) cout << "levelOrder" << endl;
		int counter = 1;
    queue<TreeNode<T> *> q;
    q.push(root);

    while (!q.empty()) {
      TreeNode<T> *current = q.front();
			if(mode == 0) cout << current -> getData() << endl;
      q.pop();
      for (size_t i = 0; i < current -> size(); i++) {
        q.push((*current)[i]);
				counter++;
      }
    }
    return counter;
	}
	/*
		print all the node on this tree with preorder.
	*/
	void preorder() {
		cout << "preOrder" << endl;
  	preorder(root);
	}
	/*
		print all the node on this tree with postorder.
	*/
	void postorder() {
		cout << "postOrder" << endl;
		postorder(root);
	}
	/*
		set the root of this tree.
	*/
	void setRoot(T d) {
    root = new TreeNode<T>(d);
	}
private:
	TreeNode<T> *root;
  int counter;
  void preorder(TreeNode<T> *current) {
    cout << current -> getData() << endl;
    for (size_t i = 0 ; i < current -> size() ; i++) {
      preorder((*current)[i]);
    }
	}
  void postorder(TreeNode<T> *current) {
		for (size_t i = 0 ; i < current -> size() ; i++) {
			postorder((*current)[i]);
		}
		cout << current -> getData() << endl;
	}
};

int main() {
	Tree<int> *tree = new Tree<int>();
	srand(time(NULL));
	int j, k;
	for(j = 0;j < 20;j ++) {
		if(tree->count() == 0) {
      tree->setRoot(rand() % 100);
    }
		else {
			k = rand() % tree->count();
			(*tree)[k]->addChild(rand() % 100);
		}
	}
	tree->levelOrder();
	cout<<endl;
	tree->preorder();
	cout<<endl;
	tree->postorder();
}
