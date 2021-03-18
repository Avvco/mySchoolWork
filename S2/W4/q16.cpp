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
      calA();
      calB();
      calC();
    }

    // Constructor
    Segment(Point p1, Point p2) {
      this -> point1 = p1;
      this -> point2 = p2;
      calA();
      calB();
      calC();
    }

    int getA() {
      return a;
    }
    int getB() {
      return b;
    }
    int getC() {
      return c;
    }
    Point getpt1() {
      return point1;
    }

    Point getpt2() {
      return point2;
    }

    float getLength() {
      return point1.mypow(point1.mypow((point1.getX() - point2.getX()), 2) + point1.mypow((point1.getY() - point2.getY()), 2), 0.5);
    }

    Point *getIntersect(Segment s) {
      Point * pt = new Point();
      // start pt or end pt connected
      if(connected(point1, s.getpt1())) {
        pt -> setX(point1.getX());
        pt -> setY(point1.getY());
        return pt;
      }else if(connected(point1, s.getpt2())) {
        pt -> setX(point1.getX());
        pt -> setY(point1.getY());
        return pt;
      }else if(connected(point2, s.getpt1())) {
        pt -> setX(point2.getX());
        pt -> setY(point2.getY());
        return pt;
      }else if(connected(point2, s.getpt2())) {
        pt -> setX(point2.getX());
        pt -> setY(point2.getY());
        return pt;
      }

      double d = this -> a * s.getB() - s.getA() * this -> b;
      std::cout << d << " ";
      std::cout << this -> a << " " << s.getB() << " " << s.getA() << " " << this -> b;
      if(a == 0 && d == 0) {
        if(inside(point1.getY(), point2.getY(), s.getpt1().getY())) {
          pt -> setX(point1.getX());
          pt -> setY((((-1) * s.getA() * point1.getX() - s.getC())) / s.getB());
          return pt;
        }
      }

      if(s.getA() == 0 && d == 0) {
        if(inside(s.getpt1().getY(), s.getpt2().getY(), point1.getY())) {
          pt -> setX(s.getpt1().getX());
          pt -> setY(((-1) * a * s.getpt1().getX() - c) / b);
          return pt;
        }
      }



      if(d == 0) return NULL;
      float interX = (this -> b * s.getC() - s.getB() * this -> c) / d;
      float interY = (this -> c * s.getA() - s.getC() * this -> a) / d;

      if(inside(this -> point1.getX(), this -> point2.getX(), interX) && inside(this -> point1.getY(), this -> point2.getY(), interY)
        && inside(s.getpt1().getX(), s.getpt2().getX(), interX) && inside(s.getpt1().getY(), s.getpt2().getY(), interY)) {
        pt -> setX(interX);
        pt -> setY(interY);
        return pt;
      }
      return NULL;
    }

  private:
    Point point1;
    Point point2;
    int a;
    int b;
    int c;

    void calA() {
      this -> a = point1.getY() - point2.getY();
    }
    void calB() {
      this -> b = point2.getX() - point1.getX();
    }
    void calC() {
      this -> c =  point1.getX() * point2.getY() - point2.getX() * point1.getY();
    }
    bool inside(float x1, float x2, float p) {
      if(x1 >= p && p >= x2) return true;
      if(x2 >= p && p >= x1) return true;
      return false;
    }
    bool connected(Point p1, Point p2) {
      if(p1.getX() == p2.getX() && p1.getY() == p2.getY()) return true;
      return false;
    }
};

int main(int argc, char const *argv[]) {
  Point p1(0, 0);
  Point p2(2,0);
  Point p3(1, 1);
  Point p4(1, -1);
  Segment s1(p1,p2);
  Segment s2(p3,p4);
  Point * pt1 = s1.getIntersect(s2);
  std::cout << "XXXXX ";
  std::cout<<pt1 -> getX() << " " << pt1 -> getY();

  return 0;
}
