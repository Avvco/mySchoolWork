// http://134.208.3.66/problem/PR109-2Q18
#include <iostream>
#include <cstring>
#include <string>

using namespace std;
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
class IntNumber
{
  public:
    // Constructor
    IntNumber() {

    }
    // Constructor
    IntNumber(char* number) {
      string _number(number);
      counter = 0;
      for(size_t i = 0 ; i < _number.size() ; i++) {
        //cout << _number[i] <<" ";
        if(_number[0] == '+' && !plus) {
          plus = true;
          i++;
        } else if(_number[0] == '-' && !minus) {
          minus = true;
          i++;
        }
        if(isalpha(_number[i])) break;

        if(_number[i] > '0' && _number[i] <= '9') start = true;

        if(_number[i] >= '0' && _number[i] <= '9' && start) {
          digit[counter].setDigit(_number[i] - '0');
          counter++;
        }
      }
    }

    void display() {
      if(counter == 0) {
        cout << "0";
        return;
      }
      if(plus);
      if(minus) cout << "-";
      for (int i = 0; i < counter; i++) {
        cout << digit[i].getDigit();
      }
    }

  private:
    Digit digit[10000];
    int counter;
    bool plus = false;
    bool minus = false;
    bool start = false;
};
int main()
{
  char num[10000];
  cin>>num;
  IntNumber *number = new IntNumber(num);
  number -> display();
  return 0;
}
