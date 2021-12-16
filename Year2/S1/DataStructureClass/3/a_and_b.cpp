#include <bits/stdc++.h>

using namespace std ;

template <class T>
class Node
{
    public :
        inline Node() : prev(NULL), next(NULL) {}
        inline Node(T d) : data(d), prev(NULL), next(NULL) {}
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
class List
{
    public :
        inline List() : first(NULL), last(NULL), middle(NULL), counts(-1) {}
        ~List()
        {
            Node<T> *node ;
            for( ; getFirst() ; setFirst(node))
            {
                node = getFirst() -> getNext() ;
                delete first ;
            }
        }
        int Attach(T n)
        {
            Node<T> *node = new Node<T>(n) ;
            if(isEmpty())
            {
                setFirst(node) ;
                setLast(node) ;
                setMiddle(node) ;
            }
            else
            {
                getLast() -> setNext(node) ;
                node -> setPrev(getLast()) ;
                setLast(node) ;
                adjust() ;
            }
            countsPP() ;
            return 1 ;
        }
        void Invert()
        {
            List<T> *l = new List() ;
            Node<T> *node = getLast() ;
            while(node)
            {
                l -> Attach(node -> getData()) ;
                node = node -> getPrev() ;
            }
            *this = *l ;
        }
        void Concatenate(List<T> *b)
        {
            if(isEmpty())
            {
                *this = *b ;
                return ;
            }
            else if(!b -> isEmpty())
            {
                List<T> *z = new List() ;
                Node<T> *node = getFirst() ;
                while(node)
                {
                    z -> Attach(node -> getData()) ;
                    node = node -> getNext() ;
                }
                node = b -> getFirst() ;
                while(node)
                {
                    z -> Attach(node -> getData()) ;
                    node = node -> getNext() ;
                }
                *this = *z ;
            }
        }
        inline int length() const { return counts + 1 ; } // 3a
        T atNth(int pos) // 3a
        {
            if(isEmpty() || pos < 0 || pos >= length()) return 0 ;
            Node<T> *node = getFirst() ;
            for(int i = 1 ; i <= pos ; i++)
            {
                node = node -> getNext() ;
            }
            return node -> getData() ;
        }
        void deleteAll(int n, T d) // 3a
        {
            if(isEmpty() || n <= 0) return ;
            int c = 0 ;
            Node<T> *node = getFirst() ;
            while(node)
            {
                if(node -> getData() == d) c++ ;
                node = node -> getNext() ;
            }
            if(n > c) return ;
            node = getFirst() ;
            List<T> *l = new List<T>() ;
            while(n)
            {
                if(node -> getData() == d) n-- ;
                if(node -> getData() != d) l -> Attach(node -> getData()) ;
                node = node -> getNext() ;
            }
            while(node)
            {
                l -> Attach(node -> getData()) ;
                node = node -> getNext() ;
            }
            *this = *l ;
        }
        void shift(char direction, int n) // 3b
        {
            if(isEmpty() || n < 0) return ;
            n = n % length() ;
            List<T> *l = this ;
            l -> getFirst() -> setPrev(l -> getLast()) ;
            l -> getLast() -> setNext(l -> getFirst()) ;
            Node<T> *node = l -> getFirst() ;
            if(direction == 'L')
            {
                while(node -> getData() != l -> atNth(n))
                {
                    node = node -> getNext() ;
                }
                l -> setFirst(node) ;
                l -> setLast(l -> getFirst() -> getPrev()) ;
            }
            else if(direction == 'R')
            {
                while(node -> getData() != l -> atNth(length() - n))
                {
                    node = node -> getPrev() ;
                }
                l -> setFirst(node) ;
                l -> setLast(l -> getFirst() -> getPrev()) ;
            }
            List<T> *ll = new List<T>() ;
            Node<T> *node2 = new Node<T>() ;
            node2 = l -> getFirst() ;
            do
            {
                ll -> Attach(node2 -> getData()) ;
                node2 = node2 -> getNext() ;
            }
            while(node2 != l -> getFirst()) ;
            *this = *ll ;
        }
        bool symmetric() // 3b
        {
            if(isEmpty() || length() == 1) return true ;
            for(int i = 0 ; i < length() / 2 ; i++)
            {
                if(atNth(i) != atNth(counts - i)) return false ;
            }
            return true ;
        }
        inline Node<T> *getFirst() const { return first ; }
        inline Node<T> *getLast() const { return last ; }
        inline Node<T> *getMiddle() const { return middle ; }
        inline bool isEmpty() const { return !length() ; }
        void print() const
        {
            if(isEmpty()) return ;
            Node<T> *n = getFirst() ;
            while(n)
            {
                cout << n -> getData() << " " ;
                n = n -> getNext() ;
            }
            cout << endl ;
        }
    private :
        Node<T> *first ;
        Node<T> *last ;
        Node<T> *middle ;
        int counts ;
        inline void countsPP() { counts++ ; }
        inline void countsSS() { counts-- ; }
        inline void setFirst(Node<T> *n) { first = n ; }
        inline void setLast(Node<T> *n) { last = n ; }
        inline void setMiddle(Node<T> *n) { middle = n ; }
        int adjust()
        {
            setMiddle(getFirst()) ;
            if(isEmpty()) return 0 ;
            else if(length() == 2) return 1 ;
            int i = 1 ;
            while(i <= length() / 2)
            {
                setMiddle(getMiddle() -> getNext()) ;
                i++ ;
            }
            return 1 ;
        }
} ;

int main(int argc, char **argv)
{
    List<int> *l = new List<int>() ;
    List<int> *l2 = new List<int>() ;
    l -> Attach(1) ;
    l -> Attach(2) ;
    l -> Attach(3) ;
    l -> Attach(4) ;
    l -> Attach(5) ;
    cout << l -> length() << endl ; // 5
    cout << l -> atNth(2) << endl ; // 3
    l -> print() ; // 1 2 3 4 5
    l2 -> Attach(1) ;
    l2 -> Attach(1) ;
    l2 -> Attach(2) ;
    l2 -> Attach(1) ;
    l2 -> Attach(1) ;
    cout << l2 -> symmetric() << endl ; // 1
    l2 -> Attach(2) ;
    cout << l2 -> symmetric() << endl ; // 0
    l -> shift('L', 8) ; // 4 5 1 2 3
    l -> print() ;
    l -> shift('R', 7) ; // 2 3 4 5 1
    l -> print() ;
    l2 -> deleteAll(3, 1) ;
    l2 -> print() ; // 2 2
    return 0 ;
}
