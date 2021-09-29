// http://134.208.3.66/problem/PR109-2Q17

class Digit
{
  public:

    // Constructor
    Digit() {
      this -> digit = 0;
    }

    // Constructor
    Digit(int digit) {
        if(digit >= 0 && digit <= 9) {
            this -> digit = digit;
        }else {
            this -> digit = 0;
        }
    }
    void setDigit(int digit) {
        if(digit >= 0 && digit <= 9){
            this -> digit = digit;
        }else {
            this -> digit = 0;
        }
    }
    int getDigit() {
       return this -> digit;
    }

  private:
    int digit;
};
