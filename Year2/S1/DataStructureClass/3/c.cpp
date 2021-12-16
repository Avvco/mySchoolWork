#include <bits/stdc++.h>

using namespace std ;

template <class T>
class Node
{
    public :
        Node() : prev(NULL), next(NULL) {}
        inline T getData() const { return data ; }
        inline Node *getPrev() const { return prev ; }
        inline Node *getNext() const { return next ; }
        inline void setData(T d) { data = d ; }
        inline void setPrev(Node *p) { prev = p ; }
        inline void setNext(Node *n) { next = n ; }
    private :
        T data ;
        Node *prev ;
        Node *next ;
} ;

template <class T>
class Queue // triple-ended queue
{
    public :
        inline Queue() : front(NULL), rear(NULL), middle(NULL), counts(0) {}
        inline ~Queue() { cout << "The queue is deconstructed" << endl ; }
        int addFront(T data)
        {
            if(isFull()) return 0 ;
            Node<T> *node = new Node<T>() ;
            node -> setData(data) ;
            if(isEmpty())
            {
                setFront(node) ;
                setRear(node) ;
                setMiddle(node) ;
            }
            else
            {
                node -> setNext(getFront()) ;
                getFront() -> setPrev(node) ;
                setFront(node) ;
                adjust() ;
            }
            countsPP() ;
            return 1 ;
        }
        int addRear(T data)
        {
            if(isFull()) return 0 ;
            Node<T> *node = new Node<T>() ;
            node -> setData(data) ;
            if(isEmpty()) addFront(data) ;
            else
            {
                node -> setPrev(getRear()) ;
                getRear() -> setNext(node) ;
                setRear(node) ;
                adjust() ;
                countsPP() ;
            }
            return 1 ;
        }
        int addMiddle(T data)
        {
            if(isFull()) return 0 ;
            Node<T> *node = new Node<T>() ;
            node -> setData(data) ;
            if(isEmpty()) addFront(data) ;
            else if(getCounts() == 1) addFront(data) ;
            else
            {
                node -> setPrev(getFront()) ;
                node -> setNext(getFront() -> getNext()) ;
                getFront() -> getNext() -> setPrev(node) ;
                getFront() -> setNext(node) ;
                int i = 2 ;
                while(i <= counts / 2)
                {
                    node -> getNext() -> setPrev(node -> getPrev()) ;
                    node -> getPrev() -> setNext(node -> getNext()) ;
                    node -> setPrev(node -> getNext()) ;
                    node -> setNext(node -> getNext() -> getNext()) ;
                    node -> getPrev() -> setNext(node) ;
                    node -> getNext() -> setPrev(node) ;
                    i++ ;
                }
                setMiddle(node) ;
                countsPP() ;
            }
            return 1 ;
        }
        int deleteFront()
        {
            if(isEmpty()) return 0 ;
            else if(getCounts() == 1)
            {
                Node<T> *node = getFront() ;
                setFront(NULL) ;
                setRear(NULL) ;
                setMiddle(NULL) ;
                delete node ;
            }
            else
            {
                Node<T> *node = getFront() ;
                setFront(getFront() -> getNext()) ;
                getFront() -> getPrev() -> setNext(NULL) ;
                getFront() -> setPrev(NULL) ;
                delete node ;
            }
            countsSS() ;
            adjust() ;
            return 1 ;
        }
        int deleteRear()
        {
            if(isEmpty()) return 0 ;
            else if(getCounts() == 1) deleteFront() ;
            else
            {
                Node<T> *node = getRear() ;
                setRear(getRear() -> getPrev()) ;
                getRear() -> getNext() -> setPrev(NULL) ;
                getRear() -> setNext(NULL) ;
                delete node ;
                countsSS() ;
                adjust() ;
            }
            return 1 ;
        }
        int deleteMiddle()
        {
            if(isEmpty()) return 0 ;
            else if(getCounts() == 1) deleteFront() ;
            else
            {
                Node<T> *node = getMiddle() ;
                getMiddle() -> getNext() -> setPrev(getMiddle() -> getPrev()) ;
                getMiddle() -> getPrev() -> setNext(getMiddle() -> getNext()) ;
                getMiddle() -> setPrev(NULL) ;
                getMiddle() -> setNext(NULL) ;
                delete node ;
                countsSS() ;
                adjust() ;
            }
            return 1 ;
        }
        inline Node<T> *getFront() const { return front ; }
        inline Node<T> *getRear() const { return rear ; }
        inline Node<T> *getMiddle() const { return middle ; }
        inline int getCounts() const { return counts ; }
        inline int isEmpty() { return !getCounts() ; }
        int isFull()
        {
            Node<T> *node = new Node<T>() ;
            if(node == NULL) return 1 ;
            return 0 ;
        }
        void print()
        {
            if(getFront() == NULL) cout << "No data" << endl ;
            Node<T> *node = getFront() ;
            while(node)
            {
                cout << node -> getData() << " " ;
                node = node -> getNext() ;
            }
            cout << endl ;
        }
    private :
        Node<T> *front ;
        Node<T> *rear ;
        Node<T> *middle ;
        int counts ;
        inline void countsPP() { counts++ ; }
        inline void countsSS() { counts-- ; }
        inline void setFront(Node<T> *n) { front = n ; }
        inline void setRear(Node<T> *n) { rear = n ; }
        inline void setMiddle(Node<T> *n) { middle = n ; }
        int adjust()
        {
            setMiddle(getFront()) ;
            if(isEmpty()) return 0 ;
            else if(getCounts() == 2) return 1 ;
            int i = 1 ;
            while(i <= getCounts() / 2)
            {
                setMiddle(getMiddle() -> getNext()) ;
                i++ ;
            }
            return 1 ;
        }
} ;

int main(int argc, char **argv)
{
    Queue<int> *q = new Queue<int>() ;
    q -> addMiddle(1) ;
    q -> addMiddle(2) ;
    q -> addMiddle(3) ;
    q -> addMiddle(4) ;
    q -> addMiddle(5) ;
    q -> print() ;
    q -> deleteFront() ;
    q -> print() ;
    q -> addRear(2) ;
    q -> print() ;
    q -> deleteMiddle() ;
    q -> print() ;
    q -> addFront(3) ;
    q -> print() ;
    q -> deleteMiddle() ;
    q -> print() ;
    q -> deleteRear() ;
    q -> print() ;
    q -> deleteMiddle() ;
    q -> print() ;
    q -> addMiddle(5) ;
    q -> print() ;
    delete q ;
    return 0 ;
}
