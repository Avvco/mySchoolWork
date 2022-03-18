// https://www.larrysprognotes.com/UVa-10245/
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define CLR(c) memset(c, 0, sizeof(c))

static auto __ = []
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

// reference: https://ppt.cc/f4Uwtx

const int INF = (int)1e9;
const int MXN = 10000;

struct Point
{
    double x;
    double y;
};

Point P[MXN];
Point tmp[MXN];

int N;

double dist(const Point& l, const Point& r)
{
    return sqrt(pow(l.x - r.x, 2) + pow(l.y - r.y, 2));
}

bool cmp1(const Point& l, const Point& r)
{
    return l.x < r.x;
}

bool cmp2(const Point& l, const Point& r)
{
    return l.y < r.y;
}

void read()
{
    FOR(i, 0, N) cin >> P[i].x >> P[i].y;
}

double DnC(int L, int R)
{
    if (L >= R) return INF;

    auto M = (L + R) / 2;
    auto d = min(DnC(L, M), DnC(M + 1, R));

    int idx = 0;
    for (int i = M; i >= L && P[M].x - P[i].x < d; --i) tmp[idx++] = P[i];
    for (int i = M + 1; i <= R && P[i].x - P[M].x < d; ++i) tmp[idx++] = P[i];

    sort(tmp, tmp + idx, cmp2);

    FOR(i, 0, idx) FOR(j, 1, 4 && i + j < idx) d = min(dist(tmp[i], tmp[i + j]), d);

    return d;
}

void solve()
{
    sort(P, P + N, cmp1);
    auto ret = DnC(0, N - 1);
    if (ret >= 1e4) cout << "INFINITY\n";
    else cout << setprecision(4) << fixed << ret << '\n';
}

int main()
{
    while (cin >> N && N)
    {
        read();
        solve();
    }
}
