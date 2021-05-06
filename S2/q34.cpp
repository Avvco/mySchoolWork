#include "q15.cpp"

class Shape
{
public:
  Shape() {
    this -> edgeCount = 0;
  }
  Shape(Segment * s, int x) { // to construct a shape with a serial of segment. Throw an invalid_argument if the segment can not construct a close path.
    for(int i = 0 ; i < x ; i++) {
        bool invalid = true;
        for(int j = 0 ; j < x ; j++) {
            if(i == j) continue;
            if(s[i].getP2().getX() == s[j].getP1().getX() && s[i].getP2().getY() == s[j].getP1().getY()) invalid = false;
        }
        if(invalid) {
            throw std::invalid_argument("Invalid syntax.");
            break;
        }
    }
    for(int i = 0 ; i < x ; i++) {
      this -> seg[i] = s[i];
    }
    this -> edgeCount = x;
  }
  virtual float getArea() = 0;

  float getPerimeter() {
    float sum = 0;
    for (int i = 0; i < edgeCount; i++) {
      sum = sum + seg[i].getLength();
    }
    return sum;
  }

  Segment &getSeg(int index)
  {
  	return seg[index];
  }
protected:
  Segment seg[10];
  int edgeCount;
};

class Square : public Shape
{
public:
  Square(Segment *seg) : Shape(seg, 4)
  {
  }
  float getArea()
  {
    return getSeg(0).getLength() * getSeg(0).getLength();
  }
};
