// http://134.208.3.66/problem/PR109-2Q19
#include <iostream>
#include <cstring>
#include <cstdlib>
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

struct dNode {
  Digit digit;
  dNode * next;
  dNode * prev;
  dNode(Digit digit) {
    this -> digit = digit;
    this -> next = NULL;
    this -> prev = NULL;
  }
};

struct sdNode {
  dNode * node;
  int size;
  bool minus;
};

class IntNumber
{
  public:
    // Constructor
    IntNumber() {

    }
    // Constructor
    IntNumber(char* number) {
      dNode * current = NULL;
      dNode * ctail = NULL;
      this -> number = number;
      string _number(number);
      dNodeCounter = 0;
      for(size_t i = 0 ; i < _number.size() ; i++) {
        if(_number[0] == '+' && !plus) {
          plus = true;
          i++;
        } else if(_number[0] == '-' && !minus) {
          minus = true;
          i++;
        }
        if(isalpha(_number[i])) break;

        if(_number[i] > '0' && _number[i] <= '9') start = true;

        if(_number[i] >= '0' && _number[i] <= '9' && start) {  // all reversed
          if(!current) {
            current = new dNode(Digit(_number[i] - '0'));
            this -> head = current;
            this -> tail = current;
            ctail = this -> tail;
          } else {
            current = new dNode(Digit(_number[i] - '0'));
            this -> head -> next = current;
            this -> head = this -> head -> next;
            this -> head -> prev = ctail;
            ctail = this -> head;
          }
          dNodeCounter++;
        }
      }
    }

    char * getNumber() {
      return this -> number;
    }
    int getDnodeCounter() {
      return this -> dNodeCounter;
    }

    bool getMinus() {
      return this -> minus;
    }
    dNode * getHead() {
      return this -> head;
    }
    dNode * getTail() {
      return this -> tail;
    }

    void display() {
      if(dNodeCounter == 0) {
        cout << "0";
        return;
      }
      if(plus);
      if(minus) cout << "-";
      dNode * node = this -> tail;
      while(node) {
        cout << node -> digit.getDigit();
        node = node -> next;
      }
    }

    IntNumber * add(IntNumber * intNumber) {
      sdNode * firstHead = new sdNode(); //longer or biger one
      sdNode * secondHead = new sdNode();

      if(getDnodeCounter() > intNumber -> getDnodeCounter()) {
        firstHead -> node = getHead();
        firstHead -> minus = getMinus();
        secondHead -> node = intNumber -> getHead();
        secondHead -> minus = intNumber -> getMinus();
      } else if(getDnodeCounter() < intNumber -> getDnodeCounter()) {
        firstHead -> node = intNumber -> getHead();
        firstHead -> minus = intNumber -> getMinus();
        secondHead -> node = getHead();
        secondHead -> minus = getMinus();
      } else {
        dNode * firstTail = getTail();
        dNode * secondTail = intNumber -> getTail();
        //bool equal = true;
        while(firstTail) {
          if(firstTail -> digit.getDigit() > secondTail -> digit.getDigit()) {
            firstHead -> node = getHead();
            firstHead -> minus = getMinus();
            secondHead -> node = intNumber -> getHead();
            secondHead -> minus = intNumber -> getMinus();
            //equal = false;
            break;
          } else if(firstTail -> digit.getDigit() < secondTail -> digit.getDigit()) {
            firstHead -> node = intNumber -> getHead();
            firstHead -> minus = intNumber -> getMinus();
            secondHead -> node = getHead();
            secondHead -> minus = getMinus();
            //equal = false;
            break;
          }
          firstTail = firstTail -> next;
          secondTail = secondTail -> next;
        }
      }


      sdNode * answer = calculate(firstHead, secondHead);
      dNode * _answer = answer -> node;
      dNode * last = _answer;
      int counter = 0;
      while(last) {
        last = last -> next;
        counter++;
      }
      last = _answer;
      char ansNum[counter];
      counter = 0;
      while(last) {
        ansNum[counter] = last -> digit.getDigit() + '0';
        counter++;
        last = last -> prev;
      }
      IntNumber * ans = new IntNumber(&ansNum[0]);
      ans -> minus = answer -> minus;
      return ans;
    }

  private:
    dNode * head;
    dNode * tail;

    int dNodeCounter;
    char * number;
    bool plus = false;
    bool minus = false;
    bool start = false;

    sdNode * calculate(sdNode * f, sdNode * s) {
      sdNode * answer = new sdNode();
      if(!f -> minus && s -> minus)  { // + -
        answer -> node = calculation(f -> node, s -> node, '-');
        answer -> minus = false;
      } else if(f -> minus && !s -> minus) { //- +
        answer -> node = calculation(f -> node, s -> node, '-');
        answer -> minus = true;
      } else if(!f -> minus && !s -> minus) { // + +
        answer -> node = calculation(f -> node, s -> node, '+');
        answer -> minus = false;
      } else if(f -> minus && s -> minus) { // - -
        answer -> node = calculation(f -> node, s -> node, '+');
        answer -> minus = true;
      }
      return answer;
    }

    dNode * calculation(dNode * f, dNode * s, char sign) {
      //dNode * tail;
      dNode * head;
      dNode * last;
      switch(sign) {
        case '+' : {
          int next = 0;
          while(f) {
            int now;
            if(s) now = f -> digit.getDigit() + s -> digit.getDigit();
            else now = f -> digit.getDigit() + 0;
            now = now + next;
            next = 0;
            while(now >= 10) {
              now = now - 10;
              next = next + 1;
            }
            dNode * current = new dNode(now);
            if(!head) {
              head = current;
              last = head;
            } else {
              head -> next = current;
              head = head -> next;
              head -> prev = last;
              last = head;
            }
            f = f -> prev;
            if(s) s = s -> prev;
          }
          if(next != 0) {
            while(next > 0) {
              dNode * current = new dNode(next % 10);
              next = next / 10;

              if(!head) {
                head = current;
                last = head;
              } else {
                head -> next = current;
                head = head -> next;
                head -> prev = last;
                last = head;
              }

            }
          }
        }
          break;


        case '-' : {
          int next = 0;
          while(f) {
            int now;

            if(s) {
              now = f -> digit.getDigit() + next - s -> digit.getDigit();
              next = 0;
              if(now < 0) {
                next = next - 1;
                now = f -> digit.getDigit() + 10 - s -> digit.getDigit();
              }
            }

            dNode * current = new dNode(now);

            if(!head) {
              head = current;
              last = head;
            } else {
              head -> next = current;
              head = head -> next;
              head -> prev = last;
              last = head;
            }
            f = f -> prev;
            if(s) s = s -> prev;
          }
        }
          break;
      }
      return head;
    }
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
