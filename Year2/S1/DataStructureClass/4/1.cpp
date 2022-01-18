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

//�𤤦�n���I�A�䤤��m����
int n, m, answer = 0, edgeNum = 0, father[MAXN];
Edge edge[MAXM];

void init()
{
    char s, e;
    int temp;
    // �ìd���ڵ��I�A��l��-1�A�X�֤��ᬰ-num,num��ܶ��X�����Ӽ�
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
    // �d��s���̳��h��
    while (father[root] >= 0)
    {
        root = father[root];
    }
    // ���|���Y�A��������d�߮Ĳv
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
    // �N���I�Ƥ֪����X�@�����I�Ʀh�����X����l�`�I
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
            if (edgeNum == n - 1)//�ͦ��𤤥]�t����ݤ֩�n-1��
            {
                break;
            }
        }
    }
    cout<<endl<<"the minimum-cost is ";
    cout << answer << endl;
    return 0;
}
