#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>

using namespace std;
class Date
{
public:
  Date()
  {
    year = 1;
    month = 1;
    day = 1;
  }
  Date(int y, int m, int d)
  {
    year = y;
    month = m;
    day = d;
  }
  virtual string toString() { // "mm, dd, yyyy"
    ostringstream _s;
    _s << setw(2) << setfill('0') << month << ", "
    << setw(2) << setfill('0') << day << ", "
    << setw(4) << setfill('0') << year;
    string s(_s.str());
    return s;
  }

  void setDay(int d) {
    this -> day = d;
  }
  void setMonth(int m) {
    this -> month = m;
  }
  void setYear(int y) {
    this -> year = y;
  }
  int getDay() const {
    return day;
  }
  int getMonth() const {
    return month;
  }
  int getYear() const {
    return year;
  }
  void addDays(int d) { // adds the specified number of days to this instance
    day = day + d;
    while (day > getDays(month)) {
      day = day - getDays(month);
      addMonths(1);
    }

  }
  void addMonths(int m) { // adds the specified number of months to this instance
    month = month + m;
    while (month > 12) {
      month = month - 12;
      addYears(1);
    }
  }
  void addYears(int y) { // adds the specified number of years to this instance
    year = year + y;
  }
  static bool isLeapYear(const Date &d) {
    return (d.year % 4 == 0 && d.year % 100 != 0) || d.year % 400 == 0;
  }
private:
  int days[13] = {0, 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int year, month, day;

  int getDays(int month) {
    return month == 2 ? isLeapYear(*this) ? 29 : 28 : days[month];
  }
};

/*
int main() {
  int n;
  Date d(2021, 1, 1);
  cin>>n;
  d.addDays(n);
  cout<<d.toString()<<endl;
  cin>>n;
  d.addMonths(n);
  cout<<d.toString()<<endl;
  cin>>n;
  d.addYears(n);
  cout<<d.toString()<<endl;
  return 0;
}
*/
