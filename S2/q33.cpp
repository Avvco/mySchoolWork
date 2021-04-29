#include "q15.cpp"
#include <cmath>
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

  private:
    Segment seg[10];
    int edgeCount;
};

class Triangle : public Shape {
  public:
    Triangle(Segment * s, int x) : Shape(s, x) {}
    float getPerimeter() {
      float p = 0;
      for (int i = 0; i < getedgeCount(); i++) {
        p = p + getSeg(i).getLength();
      }
      return p;
    }

    float getArea() {
      float s1 = getSeg(0).getLength();
      float s2 = getSeg(1).getLength();
      float s3 = getSeg(2).getLength();
      float s = (s1 + s2 + s3) / 2;
      return pow(s * (s - s1) * (s - s2) * (s - s3), 0.5);
    }
};


int main(int argc, char const *argv[]) {
  Point p1(1.6, 7.9);
  Point p2(5.7,8.4);
  Segment s(p1,p2);
  Triangle t(&s, 2);
  std::cout << t.getPerimeter();
  return 0;
}
