#include <stdio.h>
#include <string.h>
#include <stack>
#include <queue>
using namespace std;
int g[40][40][4];
int visited[40][40];
int dx[] = {1, 0, 0,-1};//UP, left, right,DOWN
int dy[] = {0, -1, 1,0};
int n, m;
stack<int> X, Y;
int remove() {
    if(X.empty())
        return 0;
    int i, tx, ty;
    for(i = 0; i < 4; i++) {
        tx = X.top()+dx[i];
        ty = Y.top()+dy[i];
        if(tx < 0 || ty < 0 || tx >= n || ty >= m)
            continue;
        if(visited[tx][ty] == 0)
            return 0;
    }
    return 1;
}
void print() {
    int i, j;
    for(j = 0; j < m; j++) {
        putchar(' ');
        putchar('_');
    }
    puts("");
    for(i = n-1; i >= 0; i--) {
        putchar('|');
        for(j = 0; j < m; j++) {
            //printf("(%d,%d,%d,%d)", g[i][j][0], g[i][j][1], g[i][j][2], g[i][j][3]);
            putchar(g[i][j][3] ? '_' : ' ');
            putchar(g[i][j][2] ? '|' : ' ');
        }
        puts("");
    }
}
int main() {
    int testcase;
    int sx, sy;
    int i, j, k, x, y;
    scanf("%d", &testcase);
    while(testcase--) {
        scanf("%d %d", &n, &m);
        scanf("%d %d", &sx, &sy);
        sx--, sy--;
        memset(visited, 0, sizeof(visited));
        X.push(sx), Y.push(sy);
        for(i = 0; i < n; i++) {
            for(j = 0; j < m; j++) {
                g[i][j][0] = g[i][j][1] = g[i][j][2] = g[i][j][3] = 1;//wall
            }
        }
        visited[sx][sy] = 1;
        char cmd[10];
        int dir = 0;
        //The input for each test case contains exactly the number of commands needed for that maze.
        while(!X.empty()) {
            scanf("%s", cmd);
            if(cmd[0] == 'F') {
                scanf("%d", &x);
                queue<int> tx, ty;
                int cnt = X.size()-x+1;
                for(i = 0; i < cnt; i++) {
                    tx.push(X.top());
                    ty.push(Y.top());
                    X.pop(), Y.pop();
                }
                while(!tx.empty()) {
                    X.push(tx.front());
                    Y.push(ty.front());
                    tx.pop(), ty.pop();
                }
            } else {
                if(cmd[0] == 'U') dir = 0;
                if(cmd[0] == 'D') dir = 3;
                if(cmd[0] == 'L') dir = 1;
                if(cmd[0] == 'R') dir = 2;
                int tx, ty;
                tx = X.top()+dx[dir];
                ty = Y.top()+dy[dir];
                //printf("%d %d %d\n", tx, ty, dir);
                if(tx >= 0 && tx < n && ty >= 0 && ty < m) {
                    if(visited[tx][ty] == 0) {
                        g[X.top()][Y.top()][dir] = 0;
                        g[tx][ty][3-dir] = 0;
                        X.push(tx), Y.push(ty);
                        visited[tx][ty] = 1;
                    }
                }

            }
            while(remove()) {X.pop(), Y.pop();}
        }
        print();
        puts("");
    }
    return 0;
}
