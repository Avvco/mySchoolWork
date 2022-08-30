/**
 * Binary Search Tree III
 * 
 * @Description:
 * Please finish the class "BinarySearchTree" with two additional functions "isValidSerialization" and "isValidBinarySearchTree" and your main function.
 * You can add any function or variable if you want.
 * 
 * @Input Description
 * Each line will contain a serialized string of the tree till the end-of-file:
 * The node's value will be separated by "," and the null pointer is indicated by "NULL", which should not have space in this string.
 * Lexicographic ordering is used if data is string or charicater.
 * Serialize and deserialize rules are the same as the question "Binary Search Tree II".
 *  
 * 
 * @Output Description
 * "OK" if the input is a valid serialization and the tree is a valid binary search tree.
 * "Serialization invalid" if the input is not a valid serialization.
 * "Binary Search Tree invalid" if the input is a valid serialization but the tree is not a valid binary search tree.
 * Ending with a "\n" of each line.
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
     * Preorder traversal of the tree
     */
    virtual void preorder() = 0;

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
class BinarySearchTree : public binarySearchTree<T> {
  
};


int main() {
  return 0;
}