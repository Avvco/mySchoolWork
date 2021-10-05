#include <bits/stdc++.h>

using namespace std ;

int calculate(char c, int x, int y)
{
    switch(c)
    {
        case '+' : return x + y ;
        case '-' : return x - y ;
        case '*' : return x * y ;
        case '/' : return x / y ;
    }
}

int main(int argc, char const *argv[])
{
    char Operator ;
    int n1, n2 ;
    while(1)
    {
        cout << "operator, integer, integer" << endl ;
        cout << "press \"=\" to finish" << endl ;
        try
        {
            cin >> Operator ;
            if(Operator == '=') return 0 ;
            if(Operator != '+' && Operator != '-' && Operator != '*' && Operator != '/' )
            {
                cin.clear() ;
                cin.ignore() ;
                throw "operator ERROR" ;
            }
            cin >> n1 >> n2 ;
            if(cin.fail())
            {
                cin.clear() ;
                cin.ignore() ;
                throw "number ERROR" ;
            }
            cout << calculate(Operator, n1, n2) << endl ;
        }
        catch(const char *s) { cout << s << endl ; }
    }
    return 0 ;
}
