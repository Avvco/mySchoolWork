// http://134.208.3.66/problem/PR109-2Q19
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>

using namespace std;

class ListNode {
  public:
    ListNode *next;
    ListNode *prev;
    ListNode(int _value) {
    this -> value = value;
    this -> next = NULL;
    this -> prev = NULL;
  }

  int getValue() {
    return this -> value;
  }

  private:
    int value;
};

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
      this -> number = number;
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

    char * getNumber() {
      return this -> number;
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

    IntNumber * add(IntNumber * intNumber) {
      ListNode * a = NULL;
      ListNode * b = NULL;
      ListNode * sumNode = NULL;
      //cout << "atol" << atol(number) << " " << atol(intNumber -> getNumber());
      for(int i = strlen(number) - 1 ; i >= 0 ; i--) {
        int tmp = number[i] - '0';
        if(!a) {
          a = new ListNode(tmp);
        } else {

        }
      }

      long long int sum = atoll(number) + atoll(intNumber -> getNumber());
      //cout <<sum<<endl;
      string _sum = to_string(sum);
      char * __sum = &_sum[0];
      return new IntNumber(__sum);
    }

  private:
    Digit digit[10000];
    int counter;
    char * number;
    bool plus = false;
    bool minus = false;
    bool start = false;
};
int main()
{
  char num1[10000], num2[10000];
  cin>>num1>>num2;
  IntNumber *number1 = new IntNumber(num1);
  IntNumber *number2 = new IntNumber(num2);
  number1->display();
  cout<<endl;
  number2->display();
  cout<<endl;
  number1->add(number2)->display();
  cout<<endl;
  number2->add(number1)->display();
  return 0;
}
