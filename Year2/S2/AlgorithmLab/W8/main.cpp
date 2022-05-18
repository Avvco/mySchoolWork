#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
#define F first
#define S second
 
bool cmp(pair<double, double> a, pair<double, double> b) {
  if (a.first == b.first) return a.second > b.second;
  return a.first < b.first;
}
 
int main() {
  int n;
  double p, r; // position, radius
  double l, w, dx;
    
  while (cin >> n >> l >> w) {
    w /= 2.0;
    vector<pair<double, double> > v;
    for (int i=0; i<n; i++) {
      cin >> p >> r;
      if (r > w){ //排除沒用的噴水頭
        dx = sqrt(r*r - w*w);
        v.push_back({p-dx, p+dx}); //轉換成區間覆蓋問題
      }
    }
    sort(v.begin(), v.end(), cmp);
      
    int ans = 0;
    double right = 0.0;
    for (int i = 0; i < v.size(); i++){
      if (v[i].F > right) break;
      for (int j = i+1; j < v.size() && v[j].F <= right; j++) {
        if (v[j].S > v[i].S){
          i = j;
        }
      }
      ans++;
      right = v[i].S;
      if (right >= l) break;
    }
      
    if (right >= l) cout << ans << "\n";
    else cout << "-1\n";
  }
  return 0;
}