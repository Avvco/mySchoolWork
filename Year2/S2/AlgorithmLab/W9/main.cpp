#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define INF 1e9
 
using namespace std;

vector <int> weight;
vector <vector<pair<int, int>>> matrix;

priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main(){
  int cases, n, m, S, T, a, b, w;
  cin >> cases;
  for(int i = 0; i < cases; i++) {
    cin >> n >> m >> S >> T;
    matrix.assign(n, vector<pair<int, int>>());
    while(m--){
      cin >> a >> b >> w;
      matrix[a].push_back(pair<int, int>(b, w));
      matrix[b].push_back(pair<int, int>(a, w));
    }

    weight.assign(n, INF);
    weight[S] = 0;
    pq.push(pair<int, int> (0, S));
    while(!pq.empty()) {
      pair<int, int> fr = pq.top(); 
      pq.pop();
      int d = fr.first; int u = fr.second;
      if (d == weight[u]){
        for(int j=0; j < matrix[u].size(); j++){
          pair<int, int> v = matrix[u][j];
          if (weight[u] + v.second < weight[v.first]){
            weight[v.first] = weight[u] + v.second;
            pq.push(pair <int, int>(weight[v.first], v.first));
          }
        }
      }
    }
    cout<<"Case #"<<i+1<<": ";
    if (weight[T] != INF)
      cout<<weight[T]<<endl;
    else cout<< "unreachable\n";
  }
}