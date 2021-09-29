// http://134.208.3.66/problem/PR109-2Q13

#include <iostream>
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

  private:
    float x;
    float y;
};
