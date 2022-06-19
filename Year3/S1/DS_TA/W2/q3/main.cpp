/**
 * Please finish a class "Stack" by the class "LinkedList" you made from the previous question
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

/**
 * A Stack class
 */
template<class T>
class Stack {
  public:

  /**
   * Construct a new Stack object with no parameter
   */
  Stack() {}

  /**
   * Add a data to stack
   * @param data data to be added to stack
   */
  void push(T data) {}

  /**
   * Remove a data from stack and return it
   * @return the data removed from stack
   */
  T pop() {}

  /**
   * @return the last element in the stack
   */
  T top() {}

  /**
   * @return true if stack is empty, false otherwise
   */
  bool isEmpty() {}

  /**
   * @return the size of the stack
   */
  int size() {}

  private: 
    LinkedList<T> *list;
};

int main() {
  Stack<int> * stack = new Stack<int>();
  cout << stack -> isEmpty() << endl;
  stack->push(1);
  stack->push(2);
  stack->push(3);
  stack->push(4);
  stack->push(5);
  cout << stack -> size() << endl;
  cout << stack->pop() << endl;
  cout << stack -> isEmpty() << endl;
  cout << stack->top() << endl;
  cout << stack->pop() << endl;
  cout << stack->pop() << endl;
  cout << stack->pop() << endl;
  cout << stack->pop() << endl;
  /**
   * expect output:
   * 1
   * 5
   * 5
   * 0
   * 4
   * 4
   * 3
   * 2
   * 1
   * 
   */
  return 0;
}