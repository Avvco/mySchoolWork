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
    
  private:
    bool vaild(int x) {
      if(x <= 1000 && x >= 0) return true;
      return false;
    }
};
