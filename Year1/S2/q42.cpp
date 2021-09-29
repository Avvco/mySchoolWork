#include <iostream>
using namespace std;

template <class T>
void exange(T &a, T &b) {
  T t = a;
  a = b;
  b = t;
}
