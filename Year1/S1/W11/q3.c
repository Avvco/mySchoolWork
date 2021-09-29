void sort(int array[], int n)
{
  for(int i = 0 ; i < n ; i++) {
    for(int j = 0 ; j < n - 1 ; j++) {
      if(array[j] > array[j+1]) {
      	int tmp = array[j];
        array[j] = array[j+1];
        array[j+1] = tmp;
      }
    }
  }
}
