#include "q34.cpp"

class Rectangle : public Shape
{
public:
  Rectangle(Segment * seg): Shape(seg, 4){}
  float getArea() {
    float a = seg[0].getLength();
    float b = seg[0].getLength();
    for(int i = 1 ; i < 4 ; i++) {
        if (seg[i].getLength() != a) {
          b = seg[i].getLength();
        }
    }
    return a * b;
  };
};
