#include <iostream>

using namespace std;


/**
* r -> space
* p -> time
*
*/
void sort_by_digit(int *A, int n, int r, int p) {
  int base = 1;
  while (p > 0) {
    --p;
    base = base * r;
    cout<<"base"<<base<<endl;
  }
  cout<<endl;

  int count[r], B[n], m = 0;

  for (int j = 0; j < r; ++j) {
    count[j] = 0;
  }

  for (int i = 0; i < n; ++i) {
    count[(A[i] / base) % r]++;
  }

  for (int j = 0, psum = 0, sum = 0; j < r; ++j) {
    psum = sum;
    sum = sum + count[j];
    count[j] = psum;
  }

  for (int i = 0; i < n; ++i) {
    B[count[(A[i] / base) % r]++] = A[i];
  }

  for (int i = 0; i < n; ++i) {
    A[i] = B[i];
  }

}
void radix_sort(int *A, int n, int r, int d) {
   d = d + 1;
  for (int i = 0; i < d; i++) {
    sort_by_digit(A, n, r, i);
  }
}
 int main(int argc, char const **argv) {
   int datas[] = {54621, 18959, 89, 34, 23, 78, 67, 100, 66, 29, 79, 55, 78, 88, 92, 96, 96, 23, 168, 255, 4567, 1245, 987, 8888, 5555, 9997, 1001, 20, 12, 99, 789};
   radix_sort(datas, 31, 8, 5);
   for (auto data : datas) {
     cout<<data<<endl;
   }
   return 0;
 }
