#include <bits/stdc++.h>

using namespace std;

void allocArray(int ***p, int m, int n)
{
  int** ary = new int*[m];
  for(int i = 0; i < m; i++) {
    ary[i] = new int [n];
  }
  *p = ary;
}

int main()
{
  int **array, *a;

  int j, k;
  allocArray(&array, 5, 10);

  // int*** prev = &array;
  // int counter = 0;
  for(j = 0;j < 5;j ++)
    for(k = 0;k < 10;k ++) {
      array[j][k] = j * 10 + k;
      cout << &array[j][k] << " ";
    }

  for(j = 0;j < 5;j ++) {
    for(k = 0;k < 10;k ++) {
      printf("%p ", &(array[j][k]));

      // printf("%d %d %d\n", counter, int(&(array[j][k])) , int(**prev));
      // **prev = &(array[j][k]);
      // counter ++;
    }
  }
}
