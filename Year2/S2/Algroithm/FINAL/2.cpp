#include<iostream>
using namespace std;

int grid[10][10];
int grid_[10][10];
int cnt=0;
bool bl=false;
void copy(int n){
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            grid_[i][j] = grid[i][j];
        }
    }
}

int cal(int n){
    int sum=1;
    for(int i=n;i>0;--i){
        sum*= i;
    }
    return sum;
}
//print the solution
void print(int n) {
    bool ch=false;
   for(int k=0;k<=n-1;k++){
            if(ch) ch=false;
    for (int i = 0;i <= n-1; i++) {
        //if(ch)break;
        for (int j = 0;j <= n-1; j++) {
                if(grid_[i][j]==1 && (!ch)){
                    ch = true;
                    cout <<grid_[i][j]<< " ";
                    grid_[i][j]=0;

                }
                else
                    cout <<0<< " ";
        }
        cout<<endl;
    }
    cout<<endl;
   }
    cout<<endl;
}
/*function for check the position is safe or not
row is indicates the queen no. and col represents the possible positions*/
bool isSafe(int col, int row, int n) {
  //check for same column
    for (int i = 0; i < row; i++) {
        if (grid[i][col]) {
            return false;
        }
    }
    //check for upper left diagonal
    for (int i = row,j = col;i >= 0 && j >= 0; i--,j--) {
        if (grid[i][j]) {
            return false;
        }
    }
    //check for upper right diagonal
    for (int i = row, j = col; i >= 0 && j < n; j++, i--) {
        if (grid[i][j]) {
            return false;
        }
    }
    return true;
}
/*function to find the position for each queen
row is indicates the queen no. and col represents the possible positions*/
bool solve (int n, int row) {
    if (n == row) {
        ++cnt;
         if(!bl){
            copy(n);
            bl = true;
         }
        return true;
    }
    //variable res is use for possible backtracking
    bool res = false;
    for (int i = 0;i <=n-1;i++) {
        if (isSafe(i, row, n)) {
            grid[row][i] = 1;
            //recursive call solve(n, row+1) for next queen (row+1)
            res = solve(n, row+1) || res;//if res ==false then backtracking will occur
            //by assigning the grid[row][i] = 0

            grid[row][i] = 0;
        }
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        int n;
        cout<<"Enter the number of queen"<<endl;
        cin >> n;
        for (int i = 0;i < n;i++) {
            for (int j = 0;j < n;j++) {
                grid[i][j] = 0;
                grid_[i][j] = 0;
            }
        }

        bool res = solve(n, 0);
        if(res == false)
            cout << -1 << endl; //if there is no possible solution
        else {
            cout <<"There are "<<cnt*cal(n)<<" solutions in "<<n<<"-queens problem in 3-D"<<endl<<
            "And one of the solutions is "<<endl<<"(from top to bottom)"<<endl<<endl;
            print(n);
        }
  return 0;
}
