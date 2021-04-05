// http://134.208.3.66/problem/PR109-2Q24
// https://www.geeksforgeeks.org/overloading-stream-insertion-operators-c/

#include <iostream>
using namespace std;

class Fraction
{
  public:
    // Constructor
    Fraction() {
      this -> numerator = 0;
      this -> denominator = 1;
    }

    Fraction(int numerator, int denominator) {
      this -> numerator = numerator;
      this -> denominator = denominator;
    }

    int getNumerator() const {
      return this -> numerator;
    }
    int getDenominator() const {
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

    Fraction &operator+(const Fraction &f) const {
      Fraction *_f = new Fraction();
		  _f -> setDenominator(this -> denominator * f.getDenominator());
		  _f -> setNumerator(this -> numerator * f.getDenominator() + f.getNumerator() * this -> getDenominator());
		  return *_f;
    }

    Fraction &operator-(const Fraction &f) const {
      Fraction *_f = new Fraction();
		  _f -> setDenominator(this -> denominator * f.getDenominator());
		  _f -> setNumerator(this -> numerator * f.getDenominator() - f.getNumerator() * this -> getDenominator());
		  return *_f;
    }

    Fraction &operator*(const Fraction &f) const {
      Fraction *_f = new Fraction();
		  _f -> setDenominator(this -> denominator * f.getDenominator());
		  _f -> setNumerator(this -> numerator * f.getNumerator());
		  return *_f;
    }

    Fraction &operator/(const Fraction &f) const {
      Fraction *_f = new Fraction();
		  _f -> setDenominator(this -> denominator * f.getNumerator());
		  _f -> setNumerator(this -> numerator * f.getDenominator());
		  return *_f;
    }

    Fraction &operator=(const Fraction &f)  {
      setDenominator(f.getDenominator());
		  setNumerator(f.getNumerator());
		  return *this;
    }
    friend ostream & operator << (ostream &out, Fraction f);

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

ostream &operator<<(ostream & o, Fraction f) {
  f.reduction();
  if(f.denominator == 1) o << "(" << f.numerator << ")";
  else o << "(" << f.numerator << "/" << f.denominator << ")";
  return o;
}

int main(int argc, char const *argv[]) {
  return 0;
}
