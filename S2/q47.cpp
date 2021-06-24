#include <iostream>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;

/*
reference:
https://ppt.cc/fdJC2x
https://ppt.cc/fQY21x
*/

static auto __ = []
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

vector<vector<int>> G;
unordered_set<int> visited;

void bfs(int n)
{
    queue<int> q;
    q.push(n);
    visited.insert(n);
    int day = 1, cnt;
    pair<int, int> _max;

    while (!q.empty())
    {
        int size = q.size();
        cnt = 0;

        // 一天可以往外傳播的人數
        while (size--)
        {
            int u = q.front();
            q.pop();

            for (auto& v : G[u])
            {
                if (visited.count(v)) continue;
                q.push(v);
                visited.insert(v);
                ++cnt;
            }
        }

        if (cnt > _max.second) _max = { day, cnt };
        ++day;
    }

    if (!_max.second) cout << "0\n";
    else cout << _max.second << " " << _max.first << '\n';
}

int main()
{
    int E;
    while (cin >> E)
    {
        // init
        G.assign(E, vector<int>());

        int n, v;
        for (int u = 0; u < E; ++u)
        {
            cin >> n;
            while (n--) cin >> v, G[u].push_back(v);
        }

        int T;
        cin >> T;
        while (T--)
        {
            int n;
            cin >> n;
            visited.clear();
            bfs(n);
        }
    }
}
