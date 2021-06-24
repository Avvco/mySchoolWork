#include <iostream>
#include <string>
using namespace std;

int main(){
    int row,col,x,y;
    string act,f;

    cin >> row >> col;  //界線
    int sc[100][100] = {0}; //判斷是否有標記
    while(cin >> x >> y >> f >> act){
        for(int i = 0; i < act.length(); i++){
            string a;
            a = act[i];
            int s = sc[x][y];

            if((y<0 || y>col) || (x<0 || x>row)){ //超出範圍，死掉
                break;
            }

            if(a == "R"){ //向右轉
                if(f == "E"){
                    f = "S";
                }
                else if(f == "S"){
                    f = "W";
                }
                else if(f == "W"){
                    f = "N";
                }
                else if(f == "N"){
                    f = "E";
                }
            }
            else if(a == "L"){    //向左轉
                if(f == "E"){
                    f = "N";
                }
                else if(f == "S"){
                    f = "E";
                }
                else if(f == "W"){
                    f = "S";
                }
                else if(f == "N"){
                    f = "W";
                }
            }
            else if(a == "F"){    //往前走
                if(f == "E" && (s!=1 || x+1<=row)){ //有標記時不能死
                    x += 1;
                }
                else if(f == "S" && (s!=1 || y-1>0)){
                    y -= 1;
                }
                else if(f == "W" && (s!=1 || x-1>0)){
                    x -= 1;
                }
                else if(f == "N" && (s!=1 || y+1<=col)){
                    y += 1;
                }
            }
        }

        if(x < 0){    //死掉
            cout << x+1 << " " << y << " " << f << " LOST" << endl;
            sc[x+1][y] = 1;
        }
        else if(y < 0){
            cout << x << " " << y+1 << " " << f << " LOST" << endl;
            sc[x][y+1] = 1;
        }
        else if(x > row){
            cout << x-1 << " " << y << " " << f << " LOST" << endl;
            sc[x-1][y] = 1;
        }
        else if(y > col){
            cout << x << " " << y-1 << " " << f << " LOST" << endl;
            sc[x][y-1] = 1;
        }
        else{   //沒死
            cout << x << " " << y << " " << f << endl;
        }
    }
    return 0;
}
