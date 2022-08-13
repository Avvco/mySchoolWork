/**
 * BinaryTree I
 * 
 * @Description:
 * Please finish the class "BinaryTree"
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
 * A TreeNode class of binaryTree class
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
 * A binaryTree abstract class for BinaryTree class
 */
template<class T>
class binaryTree {
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
class BinaryTree : binaryTree<T> {
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
  BinaryTree<int> *bt = new BinaryTree<int>();
  bt->setRoot(41);
  bt->insert(20);
  bt->insert(65);
  bt->insert(11);
  bt->insert(29);
  bt->insert(32);
  bt->insert(50);
  bt->insert(91);
  bt->insert(99);
  bt->insert(72);
  bt->insert(19);
  bt->insert(49);
  bt->insert(64);
  bt->insert(5);
  bt->insert(10);
  bt->insert(1);

  bt->preorder();
  bt->inorder();
  bt->postorder();
  bt->levelorder();

  return 0;
}