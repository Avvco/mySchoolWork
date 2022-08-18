/**
 * Trie
 * 
 * @Description:
 * Please finish the class "GeneralTree" and use it in the main function to fulfill the request.
 * You can add any function or variable if you want.
 * Note: You must use your own "GeneralTree" class or you will get up to 0 points.
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
     * @brief Get the Parent
     * 
     * @return TreeNode<T>* parent
     */
    virtual TreeNode<T>* getParent() = 0;

    /**
     * @brief Set the Parent
     * @param parent to sert
     */
    virtual void setParent(TreeNode<T>* parent) = 0;

    /**
     * @brief Get the Children
     * @return LinkedList<TreeNode<T>*>* children
     */
    virtual LinkedList<TreeNode<T>*>* getChildren() = 0;

    /**
     * @brief Set the Children
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
 * @tparam D Data type that is used to insert and remove.
 */
template<class T, class D>
class Tree {
  public:
    virtual void levelorder() = 0;

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
     * Set the Root object
     * @param root to set to root
     */
    virtual void setRoot(LinkedList<TreeNode<T>*>* root) = 0;


    /**
     * Rules for Serialize and Deserialize:
     * 1. The serialized string should be in the following format which is standard JSON format but without any spaces:
     * {"root":{"data":"","children":[{"data":"a","children":[{"data":"d","children":[]},{"data":"p","children":[]}]},{"data":"b","children":[]}]}}
     * 
     * 2. All nodes in the same layer should be sorted in alphabetical order if is a character type, and sorted by numerical order if is a number type.
     * 3. LinkedList is treated as Array in serialization and deserialization.
     */

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
    LinkedList<TreeNode<T>*>* root;
};

template<class T>
class GeneralTreeNode : public TreeNode<T> {

};

template<class T, class D>
class GeneralTree : public Tree<T,D> {
  public:
    GeneralTree() {
      TreeNode<T>* node = new GeneralTreeNode<T>();
    }
};


int main() {
  return 0;
}
