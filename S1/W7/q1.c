//  http://134.208.3.66/problem/PR1090701

#include <stdio.h>
#include <stdlib.h>

void insertionSort(double*, int);

int main(int argc, char const *argv[]) {

  int length = 0;
  scanf("%d", &length);

  double a[length];
  for(int i = 0 ; i < length ; i++) {
    scanf("%lf", &a[i]);
  }

  insertionSort(a,length);

  double sum = 0;
  for(int i = 3 ; i < length - 3 ; i++) {
    sum = sum + a[i];
  }
  printf("%.2lf", sum / (length - 6));


  return 0;
}

void insertionSort(double* arr, int size) {
  for(int i = 1 ; i < size ; i++) {
    int key = arr[i];
    int j = i - 1;
    while(key < arr[j] && j >= 0) {
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1] = key;
  }
}
