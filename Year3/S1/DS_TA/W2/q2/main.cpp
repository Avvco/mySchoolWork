/**
 * Please finish a class "Queue" by the class "LinkedList" you made from the previous question
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
 * A Queue class
 */
template<class T>
class Queue {
  public:

  /**
   * Construct a new Queue object with no parameter
   */
  Queue() {}

  /**
   * Add a data to queue
   * @param data data to be added to queue
   */
  void enqueue(T data) {}

  /**
   * Remove a data from queue and return it
   * @return the data removed from queue
   */
  T dequeue() {}

  /**
   * @return the first element in the queue
   */
  T front() {}

  /**
   * @return true if queue is empty, false otherwise
   */
  bool isEmpty() {}

  private: 
    LinkedList<T> *list;
};

int main() {
  Queue<int> * queue = new Queue<int>();

  queue->enqueue(1);
  queue->enqueue(2);
  queue->enqueue(3);
  queue->enqueue(4);
  queue->enqueue(5);
  cout << queue->dequeue();
  cout << queue->front();
  cout << queue->dequeue();
  cout << queue->dequeue();
  cout << queue->dequeue();
  cout << queue->dequeue();
  //expect output 122345
  return 0;
}