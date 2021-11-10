#include <bits/stdc++.h>

using namespace std;

class Tree
{
public:
	Tree() {
		int j, k;
		for(j = 0;j < 20;j ++) {
      for(k = 0;k < 4;k ++) {
        root[j][k] = -1;
      }
    }
	}
	int insert(int node) {
		int f = 0;
    int index = 0;

		while(root[index][0] != -1) {
      index++;
    }
		if(index >= 20) {
      return -1;
    }

		if(index == 0) {
			root[0][0] = 1;
			root[0][1] = node;
			return 1;
		}
		else {
			root[index][0] = 1;
			root[index][1] = node;
			while(1) {
				if(root[f][1] < node) {
					if(root[f][3] == -1) {
						root[f][3] = index;
						return 1;
					}
					else {
						f = root[f][3];
					}
				}
				else {
					if(root[f][2] == -1) {
						root[f][2] = index;
						return 1;
					}
					else {
						f = root[f][2];
					}
				}
			}
		}
	}
  void inorder() {
    int current = 0;
    if(root[current][0] == -1) {
      return;
    }
    inorder(root[current][2]);
    cout << root[current][1] << endl;
    inorder(root[current][3]);
  }
	void preorder() {
    int current = 0;
    if(root[current][0] == -1) {
      return;
    }
    cout << root[current][1] << endl;
    preorder(root[current][2]);
    preorder(root[current][3]);
	}
	void postorder() {
    int current = 0;
    if (root[current][0] == -1) {
      return;
    }
    postorder(root[current][2]);
    postorder(root[current][3]);
    cout << root[current][1] << endl;
	}
	void levelorder() {
    int current = 0;
    if(root[current][0] == -1 ) {
      return;
    }
    // Create an empty queue for level order traversal
    queue<int> q;

    // Enqueue Root and initialize height
    q.push(current);

    while(q.empty() == false) {
      // Print front of queue and remove it from queue
      int queue = q.front();
      cout << root[queue][1] << endl;
      q.pop();
      int left = root[queue][2];
      int right = root[queue][3];
      /* Enqueue left child */
      if (left != -1) {
        q.push(left);
      }
      /*Enqueue right child */
      if(right != -1) {
        q.push(right);
      }
    }
	}
private:
	int root[20][4];
  /*
  root[index][0]: occupied or not, -1: not occupied
  root[index][1]: tree data
  root[index][2]: tree right
  root[index][3]: tree left
  */
  void inorder(int current) {
    /*cout<<current<<"q"<<endl;
    cout<<root[current][0]<<endl;
    cout<<root[current][1]<<endl;
    cout<<root[current][2]<<endl;
    cout<<root[current][3]<<endl<<endl;*/
    if (current == -1) {
      return;
    }
    inorder(root[current][2]);
    cout << root[current][1] << endl;
    inorder(root[current][3]);
  }
  void preorder(int current) {
    if (current == -1) {
      return;
    }
    cout << root[current][1] << endl;
    preorder(root[current][2]);
    preorder(root[current][3]);
  }
  void postorder(int current) {
    if (current == -1) {
      return;
    }
    postorder(root[current][2]);
    postorder(root[current][3]);
    cout << root[current][1] << endl;
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
