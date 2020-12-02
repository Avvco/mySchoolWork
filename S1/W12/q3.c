int merger(int *a, int *b, int *c)
{
  int arr[10];

  for(int i = 0 ; i < 5 ; i++) {
  	arr[i] = *(a + i);
  }
  for(int i = 0 ; i < 5 ; i++) {
  	arr[i+5] = *(b + i);
  }
  for(int i = 0 ; i < 10 - 1 ; i++) {
    for(int j = 0 ; j < 10 - i - 1 ; j++) {
      if(arr[j] > arr[j+1]) {
        int tmp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = tmp;
      }
    }
  }
  for(int i = 0 ; i < 10 ; i++) {
  	*(c + i) = arr[i];
  }
}
