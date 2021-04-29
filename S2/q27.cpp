#include <iostream>

using namespace std;

char maps[33][33] = {0};

int main(int argc, char const *argv[]) {
    int  times, x, y;
    char arr[1001];
    cin >> times;
    for (int t = 0; t<times; t++) {
        cin >> x >> y;
        cin >> arr;
        for (int i = 0; i < 32; i++) {
          for (int j = 0; j < 32; j++) {
            maps[i][j] = '.';
          }
        }

        for (int i = 0; arr[i]!='.'; ++i) {
            if (arr[i] == 'E') {
                maps[y-1][x] = 'X';
                x++;
            }
            else if (arr[i] == 'N') {
                maps[y][x] = 'X';
                y++;
            }
            else if (arr[i] == 'W') {
                maps[y][x-1] = 'X';
                x--;
            }
            else if (arr[i] == 'S') {
                maps[y-1][x-1] = 'X';
                y--;
            }
        }

        cout << "Bitmap #" << t+1 << endl;
        for (int i = 31; i >= 0; --i) {
          cout << maps[i] << endl;
        }
        cout << "\n";
    }
    return 0;
}
