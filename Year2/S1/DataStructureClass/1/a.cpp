#include <bits/stdc++.h>

using namespace std ;

int main()
{
    int FLAG ;
    int n ;
    int guess ;
    bool bingo = false ;
    int upperBound = 100 ;
    int lowerBound = 1 ;
    int count = 0 ;
    while(1)
    {
        try
        {
            cin >> n ;
            if(n < 1 || n > 100)
            {
                cin.clear() ;
                cin.ignore() ;
                throw "the number should be between 1 ~ 100" ;
            }
        }
        catch(const char *s) { cout << s << endl ; }
        if(n >= 1 && n <= 100) break ;
    }
    while(count < 4)
    {
        flag_FLAG :
        cin >> guess ;
        try
        {
            if(guess < lowerBound || guess > upperBound)
            {
                cin.clear() ;
                cin.ignore() ;
                throw "the number should be within the bounds" ;
            }
        }
        catch(const char *s)
        {
            cout << s << endl ;
            goto flag_FLAG ;
        }
        if(guess > lowerBound && guess < upperBound)
        {
            count++ ;
            if(guess == n)
            {
                cout << "BINGO" ;
                bingo = true ;
                break ;
            }
            else if(guess < n)
            {
                lowerBound = guess ;
                if(count <= 3) cout << "the range is between (" << lowerBound << ", " << upperBound << ")" << endl ;
            }
            else
            {
                upperBound = guess ;
                if(count <= 3) cout << "the range is between (" << lowerBound << ", " << upperBound << ")" << endl ;
            }
        }
        else cout << "the number should be within the bounds" << endl ;
    }
    if(!bingo)
    {
        cout << "LOSS" << endl << "ANSWER : " << n ;
    }
    return 0 ;
}
