#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#define INF 0x3f3f3f3f

using namespace std;

struct node
{
    int end;//���I
    int weight;//�v��
} t;

int n;//n������
vector<node>q[500001];//�F�����x�s�Ϫ����T�]�۷����@���x�s�۵��c�骺�G���}�C�^
int dis[500001];//�Z���}�C
bool vis[500001];//�аO�}�C

void ShortestPath(int start, int end)
{
    memset(vis, false, sizeof(vis));
    for(int i=0; i<=n; i++)
    {
        dis[i] = INF;
    }
    int len=q[start].size();
    for(int i=0; i<len; i++)
    {
        if(q[start][i].weight < dis[q[start][i].end] )
            dis[q[start][i].end]=q[start][i].weight; //�q�_�I�}�l��dis�}�C���s
    }

    vis[start]=true;//�_�I�аO��1

    for(int k=0; k<n-1; k++)
    {
        int pos, min=INF;
        for(int i=1; i<=n; i++)
        {
            if( !vis[i] && dis[i]<min )
            {
                //���e�`�I���Q�X�ݹL�B�v�ȸ��p
                min=dis[i];
                pos=i;
            }
        }

        vis[pos]=true;

        //�A�����sdis�}�C
        len=q[pos].size();
        for(int j=0; j<len; j++)
        {
            if( !vis[q[pos][j].end] && dis[ q[pos][j].end ]>q[pos][j].weight+dis[pos] )
                dis[q[pos][j].end ] = q[pos][j].weight + dis[pos];
        }
    }
    cout<<endl<<"the shortest distance is "<<dis[end]<<endl;
}


int main()
{
    int m;
    cout<<"please input the amount of nodes and edges:"<<endl;
    cin>>n>>m;//���J�I�M��

    for(int i=0; i<=n; i++)
        q[i].clear();//�Nvector�}�C�M��
    cout<<endl<<"please key in the begin-node, the end-node, and the weight"<<endl;

    for(int i=0; i<m; i++)
    {
        int begin,end, weight;
        cin>>begin>>end>>weight;//���J
        /*t�@��node���{���ܼơA���F���K���J,�H�U�{���X���L�V�Ϫ����J��*/
        t.end=end;
        t.weight=weight;
        q[begin].push_back(t);  //���J�����ƨ̦��s��q[begin][0]�Bq[begin][1]��

        t.end=begin;
        t.weight=weight;
        q[end].push_back(t);
    }

    int start, end;//�ۤv�T�w�_�l�I�M�פ��I
    cout<<endl<<"please key in the starting node and the ending node of the whole path."<<endl;
    cin>>start>>end;//���J�_�l�I�M�פ��I

    ShortestPath(start, end);
    return 0;
}
