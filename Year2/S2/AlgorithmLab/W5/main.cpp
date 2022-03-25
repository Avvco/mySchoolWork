#include <bits/stdc++.h>
using namespace std;

const int maxn = 10240, inf = 0x3f3f3f3f;
int n, v[maxn], dp[maxn], s1[maxn], s2[maxn];

void solve() {

    memset(dp, inf, sizeof(dp));
    for(int i = 0; i < n; ++i) {
        s1[i] = (lower_bound(dp, dp+n, v[i]) - dp);
        dp[s1[i]] = v[i];
    }

    memset(dp, inf, sizeof(dp));
    for(int i = n-1; i >= 0; --i) {
        s2[i] = (lower_bound(dp, dp+n, v[i]) - dp);
        dp[s2[i]] = v[i];
    }

}

int main() {
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; ++i)
            scanf("%d", v + i);
        solve();
        int best = 1;
        for(int i = 0; i < n; ++i)
            best = max(best, min(s1[i], s2[i]) * 2 + 1);
        printf("%d\n", best);
        //
        for(int i = 0; i < n; ++i)
            printf("%d ",s1[i]);
        cout<<endl;
        for(int i = 0; i < n; ++i)
            printf("%d ",s2[i]);
    }
    return 0;
}
