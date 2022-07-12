/**
 * BigDecimal
 * 
 * @Description:
 * Please finish the class "BigDecimal"
 * You can add any function or variable in class "BigDecimal" if you want.
 * 
 * Note: You must use your own "LinkedList" class or you will get up to 0 points.
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



class BigDecimal {
  public:

  /**
   * Construct a new BigDecimal object with no parameter
   */
  BigDecimal() {}

  /**
   * Construct a new BigDecimal object with parameter
   * @param data data to put in to the BigDecimal, eg: "123.456" then 123 should be put in at integer and 456 should be put in at decimal
   */
  BigDecimal(string data) {}

  /**
   * Overload the operator + to add two BigDecimal
   * @param bigDecimal BigDecimal to add
   * 
   * Rounding rule:
   *  Banker's rounding to 2nd decimal place
   */
  BigDecimal* operator+(BigDecimal *bigDecimal) {}

  /**
   * Overload the operator - to subtract two BigDecimal 
   * @param bigDecimal BigDecimal to subtract
   * 
   * Rounding rule:
   *  Banker's rounding to 2nd decimal place
   */
  BigDecimal* operator-(BigDecimal *bigDecimal) {}

  /**
   * Overload the operator * to multiply two BigDecimal
   * @param bigDecimal BigDecimal to multiply
   * 
   * Rounding rule:
   *  Banker's rounding to 2nd decimal place
   */
  BigDecimal* operator*(BigDecimal *bigDecimal) {}
  
  /**
   * Overload the operator / to divide two BigDecimal
   * @param bigDecimal BigDecimal to divide
   * 
   * Rounding rule:
   *  Banker's rounding to 2nd decimal place
   */
  BigDecimal* operator/(BigDecimal *bigDecimal) {}

  /**
   * Overload the operator ^ to power two BigDecimal
   * @param bigDecimal BigDecimal to power
   * 
   * Rounding rule:
   *  Banker's rounding to 2nd decimal place
   */
  BigDecimal* operator^(BigDecimal *bigDecimal) {}

  /**
   * Overload the operator << to print out the BigDecimal to 2nd decimal place
   * 
   * Output example: 
   * If your integer is 1234 and decimal is 56 then you should print out "1234.56" with the content in quotes but without the quotes and a \n at the end
   */
  friend std::ostream &operator<<(std::ostream &out, BigDecimal *bigDecimal) {}

  /**
   * Overload the operator >> to read the BigDecimal from input
   */
  friend std::istream &operator>>(std::istream &in, BigDecimal *data) {}

  private:
    // A linked list representing the integer part of the BigDecimal 
    LinkedList<string> *integer;
    // A linked list representing the decimal part of the BigDecimal 
    LinkedList<string> *decimal;
};

int main() {
  BigDecimal *bigDecimal1 = new BigDecimal();
  BigDecimal *bigDecimal2 = new BigDecimal();
  char operation;
  while(cin >> bigDecimal1 >> operation >> bigDecimal2) {
    switch (operation) {
    case '+':
      cout << (*bigDecimal1 + bigDecimal2);
      break;
    case '-':
      cout << (*bigDecimal1 - bigDecimal2);
      break;
    case '*':
      cout << (*bigDecimal1 * bigDecimal2);
      break;
    case '/':
      cout << (*bigDecimal1 / bigDecimal2);
      break;
    case '^':
      cout << (*bigDecimal1 ^ bigDecimal2);
      break;
    default:
      break;
    }
  }
  return 0;
}