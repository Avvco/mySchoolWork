//  http://134.208.3.66/problem/PR1090701

//Because of the accuracy, double is too accurate to server, so I changed all double to float

#include <stdio.h>
#include <stdlib.h>

void insertionSort(float*, int);

int main(int argc, char const *argv[]) {

  int length = 0;
  scanf("%d", &length);

  float a[length];
  for(int i = 0 ; i < length ; i++) {
    scanf("%f", &a[i]);
  }

  insertionSort(a,length);

  float sum = 0;
  for(int i = 3 ; i < length - 3 ; i++) {
    sum = sum + a[i];
  }
  printf("%.2f", sum / (length - 6));


  return 0;
}

void insertionSort(float* arr, int size) {
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
