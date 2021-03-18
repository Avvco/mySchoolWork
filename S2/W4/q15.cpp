// http://134.208.3.66/problem/PR109-2Q15

#include <iostream>
#include <cmath>
class Point {
  public:
    // Constructor
    Point() {
      this -> x = 0;
      this -> y = 0;
    }

    // Constructor
    Point(float x, float y) {
      this -> x = x;
      this -> y = y;
    }

    float getX() {
      return this -> x;
    }

    void setX(float x) {
      this -> x = x;
    }

    float getY() {
      return this -> y;
    }

    void setY(float y) {
      this -> y = y;
    }

    void printPoint() {
      std::cout << "(" << this -> x << ", " << this -> y << ")";
    }

    float getDistance(Point p) {
      return mypow(mypow((this -> x - p.x), 2) + mypow((this -> y - p.y), 2), 0.5);
    }

    float mypow(float init, float exp) {
      float fin = init;
      if(exp == 0.5) return sqrt(init);
      for(float i = 0 ; i < exp - 1 ; i++) {
        fin = fin * init;
      }
      return fin;
    }

  private:
    float x;
    float y;
};


class Segment {
  public:

    // Constructor
    Segment() {
      this -> point1.setX(0);
      this -> point1.setY(0);
      this -> point2.setX(0);
      this -> point2.setY(0);
    }

    // Constructor
    Segment(Point p1, Point p2) {
      this -> point1 = p1;
      this -> point2 = p2;
    }


    float getLength() {
      return point1.mypow(point1.mypow((point1.getX() - point2.getX()), 2) + point1.mypow((point1.getY() - point2.getY()), 2), 0.5);
    }

  private:
    Point point1;
    Point point2;
};

int main(int argc, char const *argv[]) {
  Point p1(1.6, 7.9);
  Point p2(5.7,8.4);
  Segment s(p1,p2);
  std::cout<<s.getLength();

  return 0;
}
