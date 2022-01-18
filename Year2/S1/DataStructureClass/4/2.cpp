#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;

const int MAXN = 100;
int n, m, temp, ans = 0, map[MAXN][MAXN], length[MAXN];
char s, t;
bool flag[MAXN];

void init() {
    cin >> n >> m;
    memset(map, -1, MAXN * MAXN);
    for (int i = 0; i < n; ++i) {
        map[i][i] = 0;
        flag[i] = false;
        length[i] = 0x7fffffff;
    }
    for (int i = 0; i < m; ++i) {
        cin >> s >> t >> temp;
        map[s - 'A'][t - 'A'] = temp;
        map[t - 'A'][s - 'A'] = temp;
    }
}

int main() {
    init();
    // �N0�@���_�I�[�J���XS
    flag[0] = true;
    for (int i = 0; i < n; ++i) {
        if (map[0][i] >= 0) {
            length[i] = map[0][i];
        }
    }
    cout<<endl<<"the sequence of prim's algorithm:"<<endl;
    // ���N-1����
    for (int i = 0; i < n - 1; ++i) {
        int min = 0x7fffffff;
        int k = 0;
        // �C�|�DS�Ҧ��I�A��̤ܳp����
        for (int j = 1; j < n; ++j) {
            if (!flag[j] && length[j] < min) {
                min = length[j];
                k = j;
            }
        }
        ans += min;
        cout << "step #" << k << ", the cost is " << min << endl;
        // �N�s���Ik�[�J���XS,�óq�Lk��s�DS���I���Z��
        flag[k] = true;
        for (int j = 1; j < n; ++j) {
            if (!flag[j] && map[k][j] >= 0 && map[k][j] < length[j]) {
                length[j] = map[k][j];
            }
        }
    }
    cout<<endl<<"the minimum-cost is "<<ans;
    return 0;
}
