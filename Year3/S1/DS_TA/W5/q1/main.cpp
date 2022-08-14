/**
 * Binary Search Tree I
 * 
 * @Description:
 * Please finish the class "BinarySearchTree"
 * You can add any function or variable if you want.
 * 
 * @Input Description
 * NONE
 *  
 * @Output Description
 * NONE
 */

#include <iostream>
#include <string>
using namespace std;

/**
 * A TreeNode class of binarySearchTree class
 */
template<class T>
class TreeNode {
  public: 

  private:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;
};

/**
 * A binarySearchTree abstract class for BinarySearchTree class
 */
template<class T>
class binarySearchTree {
  public:
    /**
     * Print preorder traversal of the tree
     * Format: "4,5,6,7". Data seperate by "," with no spaces between and without quotes
     */
    virtual void preorder() = 0;

    /**
     * Print inorder traversal of the tree
     * Format: "4,5,6,7". Data seperate by "," with no spaces between and without quotes
     */
    virtual void inorder() = 0;

    /**
     * Print postorder traversal of the tree
     * Format: "4,5,6,7". Data seperate by "," with no spaces between and without quotes
     */
    virtual void postorder() = 0;

    /**
     * Print levelorder traversal of the tree
     * Format: "4,5,6,7". Data seperate by "," with no spaces between and without quotes
     */
    virtual void levelorder() = 0;

    /**
     * Insert data into the tree if the value is not present
     * @param data data to insert
     * @return true if insert successfully, false if the value is already present
     */
    virtual bool insert(T data) = 0;

    /**
     * Set the value of the root
     * @param data to set to root
     */
    virtual void setRoot(T data) = 0;

    /**
     * Search the tree for the given value
     * @param target target to find
     * @return true if found, false if not found
     */
    virtual bool serach(T target) = 0;
  protected:
    TreeNode<T> *root;
};

template<class T>
class BinarySearchTree : public binarySearchTree<T> {
  public:
    void preorder()  {

    }

    void inorder() {
      
    }

    void postorder() {
      
    }

    void levelorder() {
      
    }

    bool insert(T data) {

    }

    void setRoot(T data) {
      
    }

    bool serach(T target) {
      
    }
};


int main() {
  BinarySearchTree<int> *bst = new BinarySearchTree<int>();
  bst->setRoot(41);
  bst->insert(20);
  bst->insert(65);
  bst->insert(11);
  bst->insert(29);
  bst->insert(32);
  bst->insert(50);
  bst->insert(91);
  bst->insert(99);
  bst->insert(72);
  bst->insert(19);
  bst->insert(49);
  bst->insert(64);
  bst->insert(5);
  bst->insert(10);
  bst->insert(1);

  bst->preorder();
  bst->inorder();
  bst->postorder();
  bst->levelorder();

  return 0;
}