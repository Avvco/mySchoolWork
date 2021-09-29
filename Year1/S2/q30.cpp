//  I HATE UVA

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

unordered_map<char, string> morse;
unordered_map<string, vector<string>> context;

// a是b的前缀
bool isPrefixOf(const string &a, const string &b)
{
    // a是b的前缀：a长度小于b 且 b的前a.size()个字符与a相同
    return a.size() < b.size() && b.compare(0, a.size(), a) == 0;
}

void solve(string m)
{
    if (context.count(m))
    {
        auto v = context[m];
        cout << v.front();
        if (v.size() > 1)
            cout << "!";
        cout << endl;
        return;
    }

    map<int, string> ans;
    for (auto p : context)
    {
        string cm = p.first;
        if (isPrefixOf(m, cm))
            ans[(int)(cm.size() - m.size())] = p.second.front();
        else if (isPrefixOf(cm, m))
            ans[(int)(m.size() - cm.size())] = p.second.front();
    }
    cout << ans.begin()->second << "?" << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    string C, M;
    while (cin >> C && C != "*")
    {
        cin >> M;
        morse[C[0]] = M;
    }

    while (cin >> C && C != "*")
    {
        M.clear();
        for (auto c : C)
            M += morse[c];
        context[M].push_back(C);
    }

    while (cin >> M && M != "*")
        solve(M);

    return 0;
}
