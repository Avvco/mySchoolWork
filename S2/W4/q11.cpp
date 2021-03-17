// http://134.208.3.66/problem/PR109-2Q10

class bar3d
{
  public:
    float width;
    float height;
    float depth;

    // Constructor
    bar3d(float width, float height, float depth) {
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

    float getVolume() {
      return this -> width * this -> height * this -> depth;
    }

    void scale(float x) {
      this -> width = this -> width * x;
      this -> height =  this -> height * x;
      this -> depth = this -> depth * x;
    }

    float addVolume(bar3d obj) {
      return getVolume() + obj.getVolume();
    }

  private:
    bool vaild(float x) {
      if(x <= 1000 && x >= 0) return true;
      return false;
    }
};
