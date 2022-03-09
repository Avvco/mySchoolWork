#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
double a[10001],pi=acos(-1.0);
int f, n;
bool NOT_bs(double size) {
    int sum=0;
    for(int i=1;i<=n;i++) { // N + 1
        sum = sum + int(a[i]/size);
    }
    return (sum >= f+1);
}
int main() {
    int t;
    scanf("%d",&t);
    double low, high, mid, ans=-1, v=0;
    while(t--) { // T
        low = high = mid = v = 0;
        ans=-1;
        scanf("%d%d",&n,&f);
        for(int i = 1 ; i <= n ; i++) { // N + 1
            scanf("%lf",&a[i]);
            a[i]=a[i]*a[i]*pi;
            v = v + a[i];
        }
        low=0;
        high = v / (f + 1);
        while(high - low > 0.000001) { // logN
            mid = (high + low) / 2;
            if(NOT_bs(mid)) {
                low = mid;
            }
            else high=mid;

        }
        printf("%.4lf\n",mid);
    }
    return 0;
}
