// http://134.208.3.66/problem/PR109-2Q9

class bar3d
{
  public:
    int width;
    int height;
    int depth;

    // Constructor
    bar3d(int width, int height, int depth) {
      if(vaild(width) && vaild(height) && vaild(depth)) {
        this -> width = width;
        this -> height = height;
        this -> depth = depth;
      } else {
        this -> width = 0;
        this -> height = 0;
        this -> depth = 0;
      }
    }

    // Constructor
    bar3d() {
      this -> width = 0;
      this -> height = 0;
      this -> depth = 0;
    }

    int getVolume() {
      return this -> width * this -> height * this -> depth;
    }

  private:
    bool vaild(int x) {
      if(x <= 1000 && x >= 0) return true;
      return false;
    }
};
