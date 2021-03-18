// http://134.208.3.66/problem/PR109-2Q14

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
      return pow(pow((this -> x - p.x), 2) + pow((this -> y - p.y), 2), 0.5);
    }

  private:
    float x;
    float y;
};
