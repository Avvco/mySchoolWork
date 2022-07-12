/**
 * Linked List
 * 
 * Please finish a class "LinkedList" by the class "Node".
 * You can add any function or variable in class "LinkedList" and class "Node".
 * 
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


int main() {
  LinkedList<int> * lsInt = new LinkedList<int>();

  lsInt->addToHead(1);
  lsInt->addToHead(2);
  lsInt->addToHead(2);
  lsInt->addToHead(3);
  lsInt->addToHead(3);
  lsInt->addToHead(3);
  lsInt->addToHead(4);
  lsInt->addToTail(4);
  lsInt->addToTail(4);
  lsInt->addToTail(4);
  cout << lsInt; // expect (4, 3, 3, 3, 2, 2, 1, 4, 4, 4)
  lsInt->deleteData(2);
  cout << lsInt; // expect (4, 3, 3, 3, 2, 1, 4, 4, 4)
  lsInt->deleteData(2, 2);
  cout << lsInt; // expect (4, 3, 3, 3, 1, 4, 4, 4)

  LinkedList<char> * lsChar = new LinkedList<char>();

  lsChar->addToHead('a');
  lsChar->addToHead('b');
  lsChar->addToHead('b');
  lsChar->addToHead('c');
  lsChar->addToHead('c');
  lsChar->addToHead('c');
  lsChar->addToHead('d');
  lsChar->addToTail('d');
  lsChar->addToTail('d');
  lsChar->addToTail('d');

  cout << lsChar; // expect (d, c, c, c, b, b, a, d, d, d)
  lsChar->deleteData('b');
  cout << lsChar; // expect (d, c, c, c, b, a, d, d, d)
  lsChar->deleteData('b', 2);
  cout << lsChar; // expect (d, c, c, c, a, d, d, d)

  return 0;
}