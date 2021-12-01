// source code come from tree.cpp in textbook

#ifndef _IOSTREAM_H
#include <iostream>
#define _IOSTREAM_H
#endif

using namespace std;

class TreeNode {
friend class Tree;
friend int equal(TreeNode*, TreeNode*);
public:
  int getHeight() {
    return height;
  }
  void setheight(int height) {
    this -> height = height;
  }
private:
  TreeNode *LeftChild;
  int height = 0;
  int data;
  TreeNode *RightChild;
  TreeNode() {
    LeftChild = RightChild = 0;
  }
  TreeNode(int data, TreeNode *Lefty, TreeNode *Righty) {
  	this -> data = data;
  	LeftChild = Lefty;
  	RightChild = Righty;
  }
};

class Tree {
  friend int operator==(const Tree&, const Tree&);
  private:
    TreeNode *root;
    void inorder(TreeNode *);
    void preorder(TreeNode *);
    void postorder(TreeNode *, TreeNode *);
    TreeNode* copy(TreeNode *);
  public:
    void setup();
    void inorder();
    void preorder();
    void postorder();
    int size = 0;
    int sum = 0;
    Tree(const Tree&);
    Tree() {
      root = 0;
    };
    int height() {
      return root -> getHeight();
    }
};

void Tree::setup() {
  root = new TreeNode(5,0,0);
  root -> LeftChild = new TreeNode(6,0,0);
  root -> LeftChild -> LeftChild = new TreeNode(7, 0, 0);
  root -> LeftChild -> RightChild = new TreeNode(8, 0, 0);
  root -> LeftChild -> LeftChild -> LeftChild = new TreeNode(9, 0, 0);
}

void Tree::inorder() {
   inorder(root);
}

void Tree::preorder() {
   preorder(root);
}

void Tree::postorder() { //here
   size = 0;
   postorder(root, NULL);
}

void Tree::inorder(TreeNode *CurrentNode) {
  if(CurrentNode) {
	  inorder(CurrentNode->LeftChild);
	  cout << CurrentNode->data;
	  inorder(CurrentNode->RightChild);
  }
}

void Tree::preorder(TreeNode *CurrentNode) {
  if(CurrentNode) {
	  cout << CurrentNode->data;
	  preorder(CurrentNode->LeftChild);
	  preorder(CurrentNode->RightChild);
  }
}

void Tree::postorder(TreeNode *CurrentNode, TreeNode *prevNode) {
  if(CurrentNode) {
    size++;
    sum = sum + CurrentNode -> data;
    postorder(CurrentNode->LeftChild, CurrentNode);
    postorder(CurrentNode->RightChild, CurrentNode);
    int level = 0;
    if(CurrentNode->LeftChild && CurrentNode->LeftChild->getHeight() > level) level = CurrentNode->LeftChild->getHeight();
    if(CurrentNode->RightChild && CurrentNode->RightChild->getHeight() > level) level = CurrentNode->RightChild->getHeight();
    CurrentNode->setheight(level + 1);
    cout << CurrentNode->data;
  }
  else {
    prevNode -> setheight(0);
  }
}

Tree::Tree(const Tree& s) {
  root = copy(s.root);
}

TreeNode* Tree::copy(TreeNode *orignode) {
  if (orignode) {
    TreeNode *temp = new TreeNode;
    temp->data = orignode->data;
    temp->LeftChild = copy(orignode->LeftChild);
    temp->RightChild = copy(orignode->RightChild);
    return temp;
  }
  else return 0;
}

// Driver
int operator==(const Tree& s, const Tree& t) {
   return equal(s.root, t.root);
}

// Workhorse
int equal(TreeNode *a, TreeNode *b) {
/* This function returns 0 if the subtrees at @a@ and @b@ are not
   equivalent. Otherwise, it will return 1 */
 if ((!a) && (!b)) return 1;  // both @a@ and @b@ are 0
 if (a && b &&                // both @a@ and @b@ are non-0
    (a->data == b->data)      // @data@ is the same
    && equal(a->LeftChild, b->LeftChild) // left subtrees are the same
    && equal(a->RightChild, b->RightChild) ) // right subtrees are the same
       return 1;
 return 0;
}

int main() {
  Tree t;
  t.setup();
  Tree s = t;
  s.inorder();
  cout << endl;
  s.preorder();
  cout << endl;
  s.postorder();
  cout << endl;
  if (s == t) {
    cout << 1;
  } else {
    cout << 0;
  }
  cout << endl;
  cout << "height: " << s.height() << endl;
  cout << "size: " << s.size << endl;
  cout << "sum: " << s.sum << endl;
  cout << endl;
}
