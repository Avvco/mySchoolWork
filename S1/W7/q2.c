//  http://134.208.3.66/problem/PR1090702

#include <stdio.h>
#include <stdlib.h>

void insertionSort(int*, int);

int main(int argc, char const *argv[]) {
  int a[10];

  for(int i = 0 ; i < 10 ; i++){
    scanf("%d", &a[i]);
  }
  insertionSort(a, 10);

  for(int i = 0 ; i < 10 ; i++){
    printf("%d ", a[i]);
  }

  return 0;
}

void insertionSort(int* arr, int size) {
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
