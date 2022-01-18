#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

struct Edge
{
    int start;
    int end;
    int value;
};
const int MAXN = 100, MAXM = 100;

//樹中有n個點，其中有m個邊
int n, m, answer = 0, edgeNum = 0, father[MAXN];
Edge edge[MAXM];

void init()
{
    char s, e;
    int temp;
    // 並查集根結點，初始為-1，合併之後為-num,num表示集合中的個數
    memset(father, -1, MAXN);
    cout<<"please input the AMOUNT of the nodes and the edges of your tree sequently"<<endl<<endl;
    cin >> n >> m;
    cout<<"key in the data of those "<<m<<" edges"<<endl<<endl;
    for (int i = 0; i < m; i++)
    {
        cin >> s >> e >> temp;
        edge[i].start = s - 'A';
        edge[i].end = e - 'A';
        edge[i].value = temp;
    }
}

bool compare(const Edge &a, const Edge &b)
{
    return a.value < b.value;
}

int findFather(int s)
{
    int root = s, temp;
    // 查詢s的最頂層根
    while (father[root] >= 0)
    {
        root = father[root];
    }
    // 路徑壓縮，提高後續查詢效率
    while (s != root)
    {
        temp = father[s];
        father[s] = root;
        s = temp;
    }
    return root;
}

void unionSet(int s, int e)
{

    int rootS = findFather(s);
    int rootE = findFather(e);

    int weight = father[rootS] + father[rootE];
    // 將結點數少的集合作為結點數多的集合的兒子節點
    if (father[rootS] > father[rootE])
    {
        father[rootS] = rootE;
        father[rootE] = weight;
    }
    else
    {
        father[rootE] = rootS;
        father[rootS] = weight;
    }
}

int main()
{
    init();
    sort(edge, edge + m, compare);
    for (int i = 0; i < m; i++)
    {
        if (findFather(edge[i].start) != findFather(edge[i].end))
        {
            unionSet(edge[i].start, edge[i].end);
            answer += edge[i].value;
            edgeNum++;
            if (edgeNum == n - 1)//生成樹中包含的邊需少於n-1個
            {
                break;
            }
        }
    }
    cout<<endl<<"the minimum-cost is ";
    cout << answer << endl;
    return 0;
}
