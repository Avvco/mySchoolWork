int between(int *a, int *b)
{
  int sum = 0;
  while(a < b) {
  	sum = sum + *a;
    a++;
  }
  return sum;
}
