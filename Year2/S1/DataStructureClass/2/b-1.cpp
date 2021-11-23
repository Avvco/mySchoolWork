#include <bits/stdc++.h>

using namespace std ;

class Node
{
    public :
        inline Node() : data(NULL), prev(NULL), next(NULL) {}
        inline char getData() const { return data ; }
        inline Node *getPrev() const { return prev ; }
        inline Node *getNext() const { return next ; }
        inline void setData(char d) { data = d ; }
        inline Node *setPrev(Node *n) { prev = n ; }
        inline Node *setNext(Node *n) { next = n ; }
    private :
        char data ;
        Node *prev ;
        Node *next ;
} ;

class Stack
{
    public :
        inline Stack() : top(NULL), counts(0) {}
        int push(char d)
        {
            Node *node = new Node() ;
            node -> setData(d) ;
            if(isEmpty()) setTop(node) ;
            else
            {
                peek() -> setNext(node) ;
                node -> setPrev(peek()) ;
                setTop(node) ;
            }
            countsPP() ;
            return 1 ;
        }
        int pop()
        {
            if(isEmpty()) return 0 ;
            else if(getCounts() == 1)
            {
                Node *node = peek() ;
                setTop(NULL) ;
                delete node ;
            }
            else
            {
                Node *node = peek() ;
                setTop(peek() -> getPrev()) ;
                peek() -> getNext() -> setPrev(NULL) ;
                peek() -> setNext(NULL) ;
                delete node ;
            }
            countsSS() ;
            return 1 ;
        }
        int print()
        {
            if(isEmpty()) return 0 ;
            Node *node = peek() ;
            while(node)
            {
                cout << node -> getData()  << " " ;
                node = node -> getPrev() ;
            }
            cout << endl ;
            return 1 ;
        }
        Node *peek() const { return top ; }
        int getCounts() const { return counts ; }
        int isEmpty() { return !getCounts() ; }
    private :
        Node *top ;
        int counts ;
        inline int countsPP() { counts++ ; }
        inline int countsSS() { counts-- ; }
        inline void setTop(Node *n) { top = n ; }
} ;

int check(string str)
{
    Stack *parentheses = new Stack() ;
    Stack *brackets = new Stack() ;
    Stack *braces = new Stack() ;
    int counts = 0 ;
    int pl = 0 ;
    int pr = 0 ;
    int bl = 0 ;
    int br = 0 ;
    int Bl = 0 ;
    int Br = 0 ;
    for(int i = 0 ; i < str.size() ; i++)
    {
        switch(str[i])
        {
            case '(' :
                parentheses -> push(str[i]) ;
                counts++ ;
                pl++ ;
                break ;
            case '[' :
                brackets -> push(str[i]) ;
                counts++ ;
                bl++ ;
                break ;
            case '{' :
                braces -> push(str[i]) ;
                counts++ ;
                Bl++ ;
                break ;
            case ')' :
                parentheses -> pop() ;
                counts++ ;
                pr++ ;
                break ;
            case ']' :
                brackets -> pop() ;
                counts++ ;
                br++ ;
                break ;
            case '}' :
                braces -> pop() ;
                counts++ ;
                Br++ ;
                break ;
        }
    }
    int sumL = pl + bl + Bl ;
    int sumR = pr + br + Br ;
    if(!counts) return 0 ;
    else if(counts % 2 || pl != pr || bl != br || Bl != Br) return 1 ;
    else if((counts == sumL + sumR) && parentheses -> isEmpty() && brackets -> isEmpty() && braces -> isEmpty()) return 2 ;
    else return 3 ;
}

int main(int argc, char const **argv)
{
    string str ;
    cout << "CTRL + C to end this program" << endl ;
    while(getline(cin, str))
    {
        if(!check(str)) cout << "No parentheses, brackets or braces" << endl ;
        else if(check(str) == 1) cout << "Not balanced" << endl << "Not properly nested" << endl ;
        else if(check(str) == 2) cout << "Balanced" << endl << "Properly nested" << endl ;
        else cout << "Balanced" << endl << "Not properly nested" << endl ;
    }
    return 0 ;
}
