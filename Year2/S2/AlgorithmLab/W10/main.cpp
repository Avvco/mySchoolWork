#include <bits/stdc++.h>

using namespace std ;

const int MAX = 20000000 ;

struct Edge
{
    int from ;
    int to ;
    int distance ;
} ;

int main(int argc, char **argv)
{
    int testCase ;
    cin >> testCase ;
    while(testCase--)
    {
        int n, m ;
        cin >> n >> m ;
        Edge e[2005] ;
        for(int j = 0 ; j < m ; j++)
        {
            cin >> e[j].from >> e[j].to >> e[j].distance ;
        }
        vector<int> fromSourceDis(1005, MAX) ;
        for(int i = 0 ; i < n - 1 ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                fromSourceDis[e[j].to] = min(fromSourceDis[e[j].to], fromSourceDis[e[j].from] + e[j].distance) ;
            }
        }
        bool negativeCycle = 0 ;
        for(int j = 0 ; j < m && !negativeCycle ; j++)
        {
            if(fromSourceDis[e[j].from] + e[j].distance < fromSourceDis[e[j].to]) negativeCycle = 1 ;
        }
        cout << ((negativeCycle) ? "possible\n" : "not possible\n") ;
    }
    return 0 ;
}