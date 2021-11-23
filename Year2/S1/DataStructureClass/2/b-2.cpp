// function "encode" is still not working properly yet

#include <bits/stdc++.h>

using namespace std ;

class Node
{
    public :
        inline Node() : data(NULL), prev(NULL), next(NULL) {}
        inline char getData() const { return data ; }
        inline Node *getPrev() const { return prev ; }
        inline Node *getNext() const { return next ; }
        inline char setData(char d) { data = d ; }
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
                node -> setPrev(peek()) ;
                peek() -> setNext(node) ;
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
        inline Node *peek() const { return top ; }
        inline int getCounts() const { return counts ; }
        inline int isEmpty() { return !getCounts() ; }
    private :
        Node *top ;
        int counts ;
        inline void setTop(Node *n) { top = n ; }
        inline void countsPP() { counts++ ; }
        inline void countsSS() { counts-- ; }
} ;

char *encode(char *str) // Thanks to 小紅
{
    char *front = new char[1000] ;
    char *end = new char[1000] ;
    char *target = new char[1000] ;
    char *ans = new char[1000] ;
    int l, i, c ;
    char *t ;
    l = strlen(str) / 2 ;
    while(l > 0)
    {
        for(i = 0 ; i + l * 2 - 1 < strlen(str) ; i++)
        {
            strncpy(target, str + i, l) ;
            target[l] = '\0' ;
            t = str + l + i ;
            c = 1 ;
            while(strncmp(target, t, l) == 0)
            {
                c++ ;
                t += l ;
            }
            if(c > 1)
            {
                strncpy(front, str, i) ;
                strcpy(front, encode(front)) ;
                front[i] = '\0' ;
                char buf[100] ;
                strcpy(buf, encode(target)) ;
                char *a = buf ;
                int base = 0 ;
                while((*a + 2) / 10 == 5)
                {
                    base = base * 10 + *a - '0' ;
                    a++ ;
                }
                if(*a == '[' && buf[strlen(buf) - 1] == ']')
                {
                    c = c * base ;
                    strcpy(target, a + 1) ;
                    target[strlen(target) - 1] = '\0' ;
                    l = strlen(target) ;
                    while(strncmp(target, t, l) == 0)
                    {
                        c++ ;
                        t += l ;
                    }
                }
                else strcpy(target, buf) ;
                strcpy(end, t) ;
                strcpy(end, encode(end)) ;
                sprintf(ans, "%s%d[%s]%s", front, c, target, end) ;
                return ans ;
             }
        }
        l-- ;
    }
    strcpy(ans, str) ;
    return ans ;
}

string decode(string str) // using stack
{
    Stack *s = new Stack() ;
    for(int i = 0 ; i < str.size() ; i++)
    {
        if(str[i] == ']')
        {
            string t ;
            while(!(s -> isEmpty()) && s -> peek() -> getData() != '[')
            {
                t = s -> peek() -> getData() + t ; // += is not allowed
                s -> pop() ;
            }
            s -> pop() ;
            string num ;
            while(!(s -> isEmpty()) && (s -> peek() -> getData()) <= 57 && 48 <= (s -> peek() -> getData()))
            {
                num = s -> peek() -> getData() + num ; // += is not allowed
                s -> pop() ;
            }
            int number = stoi(num) ;
            string repeat ;
            for(int j = 0 ; j < number ; j++)
            {
                repeat += t ;
            }
            for(char c : repeat)
            {
                s -> push(c) ;
            }
        }
        else s -> push(str[i]) ;
    }
    string result ;
    while(!(s -> isEmpty()))
    {
        result = s -> peek() -> getData() + result ; // += is not allowed
        s -> pop() ;
    }
    return result ;
}

int main(int argc, char const **argv)
{
    cout << "Input \"exit\" to end this program" << endl ;
    cout << "Input \"encode\" to encode a string " << endl ;
    cout << "Input \"decode\" to decode a string " << endl ;
    string cmd ;
    string str ;
    while(1)
    {
        cin >> cmd ;
        if(cmd.compare("exit") == 0) break ;
        else if(cmd.compare("encode") == 0)
        {
            cin >> str ;
            char *c = &str[0] ;
            cout << encode(c) << endl ;
        }
        else if(cmd.compare("decode") == 0)
        {
            cin >> str ;
            cout << decode(str) << endl ;
        }
    }
    return 0 ;
}
