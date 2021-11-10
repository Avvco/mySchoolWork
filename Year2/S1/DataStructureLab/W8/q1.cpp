#include <bits/stdc++.h>

using namespace std;

class Node {
public:
	int level, data;
	Node *left, *right;
};

class Tree {
public:
	Tree() {
		root = NULL;
	}
	void insert(Node *n) {
		insert(&root, n, 0);
	}
  // ======
	void inorder() {
    if (root == NULL) {
      return;
    }
    /* first recur on left child */
    inorder(root->left);

    /* then print the data of node */
    cout << root->data << "\t" << root->level <<endl;

    /* now recur on right child */
    inorder(root->right);
	}

  // ======
	void preorder() {
    if (root == NULL) {
      return;
    }

    /* first print data of node */
    cout << root->data << "\t" << root->level <<endl;

    /* then recur on left subtree */
    preorder(root->left);

    /* now recur on right subtree */
    preorder(root->right);
	}
	void postorder() {
    if (root == NULL){
      return;
    }
    // first recur on left subtree
    postorder(root->left);

    // then recur on right subtree
    postorder(root->right);

    // now deal with the node
    cout << root->data << "\t" << root->level <<endl;
	}
	void levelorder() {
    if (root == NULL) {
      return;
    }
    // Create an empty queue for level order traversal
    queue<Node*> q;

    // Enqueue Root and initialize height
    q.push(root);

    while (q.empty() == false) {
      // Print front of queue and remove it from queue
      Node* node = q.front();
      cout << node->data << "\t" << node->level <<endl;
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
	Node *root;
	void insert(Node **r, Node *n, int lev) {
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
  void inorder(Node *root) {
    if (root == NULL) {
      return;
    }
    inorder(root->left);
    cout << root->data << "\t" << root->level <<endl;
    inorder(root->right);
  }
  void preorder(Node *root) {
    if (root == NULL) {
      return;
    }
    cout << root->data << "\t" << root->level <<endl;
    preorder(root->left);
    preorder(root->right);
	}
  void postorder(Node *root) {
    if (root == NULL){
      return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root -> data << "\t" << root -> level <<endl;
  }
};

int main() {
	Tree *tree = new Tree();
	Node *node;
	int j;
	srand(time(NULL));
	for(j = 0;j < 10;j ++) {
		node = new Node();
		node->data = rand();
		node->left = NULL;
		node->right = NULL;
		tree->insert(node);
	}
	tree->inorder();
	printf("\n");
	tree->preorder();
	printf("\n");
	tree->postorder();
	printf("\n");
  printf("\n");
	tree->levelorder();
	printf("\n");
}
