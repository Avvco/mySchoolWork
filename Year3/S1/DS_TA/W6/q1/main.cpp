/**
 * Trie
 * 
 * @Description:
 * Please finish the class "GeneralTree" and use it in the main function to fulfill the request.
 * You can add any function or variable if you want.
 * Note: You must use your own "GeneralTree", "GeneralTreeNode" and "LinkedList" class or you will get up to 0 points.
 * 
 * @Input Description
 * Input starts with two integers n and m, followed by the n line. Each line is a word, use GeneralTree to create a trie with the n word. Next m line, each line is a word, check if the word exists in the trie.
 * 
 * @Output Description
 * Output "1" if the word exists, and "0" if not with a "\n" of each line.
 * And finally, output the serialized string of the trie with a "\n".
 */

#include <iostream>
#include <string>
using namespace std;

/**
 * A Node class of Doublely Linked List class
 */
template<class T>
class Node {
  public:

  /**
   * Construct a new Node object with no parameter
   */
  Node() {}

  /**
   * Construct a new Node object with parameter
   * @param data data to put in
   */
  Node(T data) {}

  /**
   * Construct a new Node object with parameters
   * @param data data to put in
   * @param prev pointer to the previous node
   * @param next pointer to the next node
   */
  Node(T data, Node<T> *prev, Node<T> *next) {}

  private: 
    Node<T> *prev;
    Node<T> *next;
    T data;
};

/**
 * A Doublely Linked List class
 */
template<class T>
class LinkedList {
  public:

  /**
   * Construct a new LinkedList object with no parameter
   */
  LinkedList() {}

  /**
   * Add a node to the tail of the linked list
   * @param data data to put in
   */
  void addToTail(T data) {}

  /**
   * Add a node to the head of the linked list
   * @param data data to put in
   */
  void addToHead(T data) {}

  /**
   * Delete a node from the linked list with the given data from the head
   * If there are no data to be deleted, then do nothing
   * @param data data to delete
   */
  void deleteData(T data) {}

  /**
   * Delete valid n nodes from the linked list with the given data from the head
   * If there are no more data to be deleted, then just skip
   * @param data data to delete
   * @param n max number of nodes to delete
   */
  void deleteData(T data, int n) {} 

  /**
   * Overload the operator << to print out all the data in the linked list from the head
   * There is a \n in the end of each print
   * 
   * Output example: 
   * If your linked list data is 5, 4, 3, 2, 1
   * then you should print out "(5, 4, 3, 2, 1)" with the content in quotes but without the quotes
   */
  friend std::ostream &operator<<(std::ostream &out, LinkedList * n) {}

  private: 
    Node<T> *head;
    Node<T> *tail;
};

/**
 * A abstract class for treenode
 * @tparam T Stored data of the node
 */
template<class T>
class TreeNode {
  public:
    /**
     * Get the Parent
     * @return TreeNode<T>* parent
     */
    virtual TreeNode<T>* getParent() = 0;

    /**
     * Set the Parent
     * @param parent to set
     */
    virtual void setParent(TreeNode<T>* parent) = 0;

    /**
     * Get the Children
     * @return LinkedList<TreeNode<T>*>* children
     */
    virtual LinkedList<TreeNode<T>*>* getChildren() = 0;

    /**
     * Set the Children
     * @param children to set
     */
    virtual void setChildren(LinkedList<TreeNode<T>*>* children) = 0;
  protected:
    /**
     * Data stored in the node
     */
    T data;

    /**
     * A linked list for children nodes
     */
    LinkedList<TreeNode<T>*>* children;
};

/**
 * A abstract class for tree
 * 
 * @tparam T Stored data in each node of the tree
 * @tparam D Data type that is used to insert, remove and search.
 */
template<class T, class D>
class Tree {
  public:
    /**
     * Levelorder traversal of the tree
     */
    virtual void levelorder() = 0;

    /**
     * Inorder traversal of the tree
     */
    virtual void inorder() = 0;

    /**
     * Preorder traversal of the tree
     */
    virtual void preorder() = 0;

    /**
     * Postorder traversal of the tree
     */
    virtual void postorder() = 0;

    /**
     * Insert a node to the tree with the given data if it not exists.
     * @param data data to insert
     * @return true if the node is inserted, false if the node already exists
     */
    virtual bool insert(D data) = 0;

    /**
     * Remove a node from the tree with the given data if it exists.
     * @param data data to insert
     * @return true if the node is removed successfully, false if the node is not found 
     */
    virtual bool remove(D data) = 0;

    /**
     * Find a node with the given data if it exists.
     * @param data data to search
     * @return the node if found, NULL if not found
     */
    virtual TreeNode<T>* search(D data) = 0;

    /**
     * Set the Root object
     * @param root to set to root
     */
    virtual void setRoot(TreeNode<T>* root) = 0;

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
  /**
   * First layer of the tree will be the children of root
   */
    TreeNode<T>* root;
};

template<class T>
class GeneralTreeNode : public TreeNode<T> {

};


/**
 * Rules of Serialize and Deserialize for General Tree:
 * 1. The serialized string should be in the following format which is standard JSON format but without any spaces:
 * {"root":{"children":[{"children":[{"children":[],"data":"d"},{"children":[],"data":"p"}],"data":"a"},{"children":[],"data":"b"}],"data":""}}
 * In each node, there are two data structures.
 *  a. children.
 *  b. data.
 * "children" is an array that always comes first.
 * "data" is a data structure stored in the node, that comes after children, sorted in alphabetical order.
 * 
 * 2. All nodes in the same layer should be sorted in alphabetical order if is a character type, and sorted by numerical order if is a number type.
 * 3. LinkedList is treated as Array in serialization and deserialization.
 */


template<class T, class D>
class GeneralTree : public Tree<T, D> {
  public:
    GeneralTree() {
       this -> root = new GeneralTreeNode<T>();
    }
};


int main() {
  return 0;
}
