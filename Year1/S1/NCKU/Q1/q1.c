#include <stdio.h>
#include <math.h>

void sigma(int * n) {
  double tmp = 0;
  for (int k = 1; k <= *n; k++) {
    tmp = tmp + pow((-1), (k - 1)) / ((2 * k) - 1);
  }
  printf("%.6lf\n", 4 * tmp);
}


int main(int argc, char const *argv[]) {

  int n;
  scanf("%d", &n);
  sigma(&n);

  return 0;
}
