#include "q15.cpp"

class Shape {
public:
  Shape() {
    edgeCount = 0;
  }
  Shape(Segment * s, int x) {
    for(int i = 0 ; i < x ; i ++) {
      seg[i] = s[i];
    }
    edgeCount = x;
  }
private:
  Segment seg[10];
  int edgeCount;
};
