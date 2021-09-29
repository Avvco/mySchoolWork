template<typename T>
T *sort(T *array, int n)
{
  for (int z = 0; z < n; z++) {
    for (int i = 0; i < n - 1; i++) {
      if(array[i] > array[i+1]) {
        T t = array[i];
        array[i] = array[i + 1];
        array[i + 1] = t;
      }
    }
  }
  return array;
}
