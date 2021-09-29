#include "q15.cpp"

class Shape {
  public:
    Shape() {
      this->edgeCount = 0;
    }
    Shape(Segment * s, int x) {
      for(int i = 0 ; i < x ; i++) {
        this->seg[i] = s[i];
      }
      this->edgeCount = x;
    }

    int getedgeCount() {
      return this->edgeCount;
    }

    Segment getSeg(int x) {
      return seg[x];
    }

  protected:
    Segment seg[10];
    int edgeCount;
};

class Rectangle : public Shape {
  public:

    // Constructor
    Rectangle(Segment * s, int x) : Shape(s, x) {

    }
    float getPerimeter() {
      float p = 0;
      for (int i = 0; i < getedgeCount(); i++) {
        p = p + getSeg(i).getLength();
      }
      return p;
    }

    float getArea() {
      float a = seg[0].getLength();
      float b = seg[0].getLength();
      for(int i = 1 ; i < 4 ; ++ i) {
          if (seg[i].getLength() != a) {
            b = seg[i].getLength();
          }
      }
      return a * b;
    }
};


int main(int argc, char const *argv[]) {
  Point p1(1.6, 7.9);
  Point p2(5.7,8.4);
  Segment s(p1,p2);
  Rectangle r(&s, 2);
  std::cout << r.getPerimeter();
  return 0;
}
