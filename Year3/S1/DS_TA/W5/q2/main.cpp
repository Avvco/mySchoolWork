/**
 * BinaryTree II
 * 
 * @Description:
 * Please finish the class "BinaryTree" and use it in the main function
 * You can add any function or variable if you want.
 * 
 * @Input Description
 *  Each line will contain the following information till the end-of-file:
 *  ．First part will be a string that needs to be deserialized to the tree, which is separated by ","
 *  and the null pointer is indicated by "NULL", there is no space in this string.
 *  ．Second part will be multiple strings which is the value that needs to be added to the tree.
 *  Example: assume the input is "15,6,23,NULL,7 71 50 5", then 15,6,23,NULL,7 is the string that needs to be deserialized, "71 50 5" is to be added.
 *  Suggest data type for TreeNode: int
 *  
 * 
 * @Output Description
 * Result of the serialized tree after add and delete, no space between and ending with a "\n" of each line.
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
     * Preorder traversal of the tree
     */
    virtual vod preorder() = 0;

    /**
     * Inorder traversal of the tree
     */
    virtual void inorder() = 0;

    /**
     * Postorder traversal of the tree
     */
    virtual void postorder() = 0;

    /**
     * Levelorder traversal of the tree
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

    /**
     * Deserialize the string to a tree with levelorder traversal
     * @param tree to be deserialized
     */
    virtual void deSerialize(string tree) = 0;

    /**
     * Serialize the tree to a string with levelorder traversal
     * @return the serialized string
     */
    virtual string serialize() = 0;
  protected:
    TreeNode<T> *root;
};

template<class T>
class BinaryTree : binaryTree<T> {
  
};


int main() {
  return 0;
}