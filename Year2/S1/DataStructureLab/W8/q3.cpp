// tree using 1D array

#include <bits/stdc++.h>

using namespace std;

class Tree {
public:
	Tree() {
		int j;
		for(j = 0;j < 2000;j ++) {
      root[j] = -1;
    }
	}
	int insert(int node) {
		int index = 0;
		while(index < 2000 && root[index] != -1) {
			if(root[index] < node) { //left
        index = index * 2 + 2;
      }
			else { //right
        index = index * 2 + 1;
      }
		}
		root[index] = node;
    return 0;
	}
	void inorder() {
    int current = 0;
    if(root[current] == -1) {
      return;
    }
    inorder(current * 2 + 2);
    cout << root[current] << endl;
    inorder(current * 2 + 1);
	}
	void preorder() {
    int current = 0;
    if(root[current] == -1) {
      return;
    }
    cout << root[current] << endl;
    preorder(current * 2 + 2);
    preorder(current * 2 + 1);
	}
	void postorder() {
    int current = 0;
    if(root[current] == -1) {
      return;
    }
    postorder(current * 2 + 2);
    postorder(current * 2 + 1);
    cout << root[current] << endl;
	}
	void levelorder() {
    int current = 0;
    if(root[current] == -1) {
      return;
    }
    // Create an empty queue for level order traversal
    queue<int> q;

    // Enqueue Root and initialize height
    q.push(current);

    while (q.empty() == false) {
      // Print front of queue and remove it from queue
      int queue = q.front();
      cout << root[queue] << endl;
      q.pop();
      int left = queue * 2 + 2;
      int right = queue * 2 + 1;
      /* Enqueue left child */
      if(root[left] != -1) {
        q.push(left);
      }
      /*Enqueue right child */
      if(root[right] != -1) {
        q.push(right);
      }
    }
	}
private:
	int root[2000];
  void inorder(int current) {
    if(root[current] == -1) {
      return;
    }
    inorder(current * 2 + 2);
    cout << root[current] << endl;
    inorder(current * 2 + 1);
	}
  void preorder(int current) {
    if(root[current] == -1) {
      return;
    }
    cout << root[current] << endl;
    preorder(current * 2 + 2);
    preorder(current * 2 + 1);
  }
  void postorder(int current) {
    if(root[current] == -1) {
      return;
    }
    postorder(current * 2 + 2);
    postorder(current * 2 + 1);
    cout << root[current] << endl;
  }
};

int main() {
	Tree *tree = new Tree();
	int j, node;
	srand(time(NULL));
	for(j = 0;j < 10;j ++) {
		node = rand();
		tree->insert(node);
	}
	tree->inorder();
	printf("\n");
	tree->preorder();
	printf("\n");
	tree->postorder();
	printf("\n");
	tree->levelorder();
	printf("\n");
}
