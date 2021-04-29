// http://134.208.3.66/problem/PR109-2Q22

#include <iostream>
using namespace std;

class Fraction
{
  public:
    // Constructor
    Fraction() {
      this -> numerator = 0;
      this -> denominator = 0;
    }

    Fraction(int numerator, int denominator) {
      this -> numerator = numerator;
      this -> denominator = denominator;
    }

    int getNumerator() {
      return this -> numerator;
    }
    int getDenominator() {
      return this -> denominator;
    }

    void setNumerator(int numerator) {
      this -> numerator = numerator;
    }

    void setDenominator(int denominator) {
      this -> denominator = denominator;
    }

    void display() {
      reduction();
      if(denominator == 1) cout << numerator;
      else cout << "(" << numerator << "/" << denominator << ")";
    }

  private:
    int numerator;
    int denominator;
    void reduction() {
      int a = bigger();
      while(a > 1) {
        if(numerator % a == 0 && denominator % a == 0) {
          numerator = numerator / a;
          denominator = denominator / a;
          a = bigger();
        }
        a--;
      }
    }
    int bigger() {
      if(numerator >= denominator) return numerator;
      return denominator;
    }
};
int main(int argc, char const *argv[]) {
  Fraction a(10264,592);
  a.display();
  return 0;
}
