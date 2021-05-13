#include <string>
using namespace std;

class TimeSpan
{
public:
  TimeSpan() {
    day = 0;
    hour = 0;
    minute = 0;
    second = 0;
  }
  TimeSpan(int d, int hh, int mm, int ss) {
    day = d;
    hour = hh;
    minute = mm;
    second = ss;
  }
  void setDay(int day) {
    this -> day = day;
  }
  void setHour(int hour) {
    this -> hour = hour;
  }
  void setMin(int min) {
    this -> minute = min;
  }
  void setSec(int sec) {
    this -> second = sec;
  }

  int getDay() {
    return day;
  }
  int getHour() {
    return hour;
  }
  int getMin() {
    return minute;
  }
  int getSec() {
    return second;
  }
  int toTotalDays();
  int toTotalHours();
  int toTotalMinutes();
  int toTotalSeconds() {
    return second;
  }
  string toString() {
    return "a";
  }
private:
  int day, hour, minute, second;
};
