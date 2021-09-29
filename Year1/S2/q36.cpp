#include "q34.cpp"

class Rectangle : public Shape
{
public:
  Rectangle(Segment * seg): Shape(seg, 4){
    for(int i = 0 ; i < 4 ; i++) {
      float arrX[] = {
                      seg[0].getP1().getX(), seg[0].getP2().getX(),
                      seg[1].getP1().getX(), seg[1].getP2().getX(),
                      seg[2].getP1().getX(), seg[2].getP2().getX(),
                      seg[3].getP1().getX(), seg[3].getP2().getX()
                    };
      float arrY[] = {
                      seg[0].getP1().getY(), seg[0].getP2().getY(),
                      seg[1].getP1().getY(), seg[1].getP2().getY(),
                      seg[2].getP1().getY(), seg[2].getP2().getY(),
                      seg[3].getP1().getY(), seg[3].getP2().getY()
                    };
      topY = findMax(arrY, 1);
      bottomY = findMax(arrY, -1);
      rightX = findMax(arrX, 1);
      leftX = findMax(arrX, -1);
    }
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
  };
  bool isCollision(const Rectangle rec) { //return true if two rectangle is overlap return false if not.
    if (leftX < rec.getRightX() && rightX > rec.getLeftX() &&
    topY > rec.getButtomY() && bottomY < rec.getTopY()) return true;
     return false;
  }

  int getTopY() const {
    return topY;
  }
  int getLeftX() const {
    return leftX;
  }
  int getRightX() const {
    return rightX;
  }
  int getButtomY() const {
    return bottomY;
  }

  private:
    int topY;
    int leftX;
    int rightX;
    int bottomY;

    int findMax(float arr[], int mode) {
      int val = arr[0];
      switch (mode) {
        case 1: //biggest
          for(int i = 0 ; i < 8 ; i++) {
            if(arr[i] > val) val = arr[i];
          }
          break;
        case -1: //smallest
          for(int i = 0 ; i < 8 ; i++) {
            if(arr[i] < val) val = arr[i];
          }
          break;
      }
      return val;
    }
};

/*
int main() {
  Point p1(0, 0), p2(10, 0), p3(10, 0), p4(10, 10), p5(10, 10), p6(0, 10), p7(0, 10), p8(0, 0);
  Point p9(5, 5), p10(15, 5), p11(15, 5), p12(15, 15), p13(15, 15), p14(5, 15), p15(5, 15), p16(5, 5);
  Segment s[4] = {Segment(p1, p2), Segment(p3, p4), Segment(p5, p6), Segment(p7, p8)};
  Segment s2[4] = {Segment(p9, p10), Segment(p11, p12), Segment(p13, p14), Segment(p15, p16)};
  Point p17(0, 0), p18(10, 0), p19(10, 0), p20(10, 10), p21(10, 10), p22(0, 10), p23(0, 10), p24(0, 0);
  Point p25(15, 15), p26(15, 20), p27(15, 20), p28(20, 20), p29(20, 20), p30(20, 15), p31(20, 15), p32(15, 15);
  Segment s3[4] = {Segment(p17, p18), Segment(p19, p20), Segment(p21, p22), Segment(p23, p24)};
  Segment s4[4] = {Segment(p25, p26), Segment(p27, p28), Segment(p29, p30), Segment(p31, p32)};
  Rectangle r1(s), r2(s2), r3(s3), r4(s4);
  std::cout<<r1.isCollision(s2)<<std::endl;
  std::cout<<r3.isCollision(s4)<<std::endl;
  return 0;
} 1, 0
*/
