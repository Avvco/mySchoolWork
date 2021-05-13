#include "q38.cpp"
#include "q40.cpp"

class DateTime : public Date
{
public:
  DateTime() : Date()
  {
    hour = 0;
    minute = 0;
    second = 0;
  }
  DateTime(int y, int m, int d, int hh = 0, int mm = 0, int ss = 0) : Date(y, m, d)
  {
    hour = hh;
    minute = mm;
    second = ss;
  }
  virtual string toString() { // "mm/dd/yyyy HH:MM:SS"
    ostringstream _s;
    _s << setw(2) << setfill('0') << getMonth() << "/"
    << setw(2) << setfill('0') << getDay() << "/"
    << setw(4) << setfill('0') << getYear() << " "
    << setw(2) << setfill('0') << hour << ":"
    << setw(2) << setfill('0') << minute << ":"
    << setw(2) << setfill('0') << second;

    return _s.str();
  }

  void setHour(int h) {
    this -> hour = h;
  }
  void setMinute(int m) {
    this -> minute = m;
  }
  void setSecond(int s) {
    this -> second = s;
  }
  int getHour() const {
    return hour;
  }
  int getMinute() const {
    return minute;
  }
  int getSecond() const {
    return second;
  }
  void addHours(int h) { // adds the specified number of hours to this instance
    hour = hour + h;
    while (hour >= 24) {
      hour = hour - 24;
      Date::addDays(1);
    }
  }
  void addMinutes(int m) { // adds the specified number of minutes to this instance
    minute = minute + m;
    while (minute >= 60) {
      minute = minute - 60;
      addHours(1);
    }
  }
  void addSeconds(int s) { // adds the specified number of seconds to this instance
    second = second + s;
    while (second >= 60) {
      second = second - 60;
      addMinutes(1);
    }
  }


  TimeSpan operator-(const DateTime &dt) const { // return a TimeSpan object represents a time interval
    DateTime d = (*this);
    TimeSpan *_ts = new TimeSpan();
    int elapsedSec = 0;
    while(true){
      if(d.getYear() == dt.getYear() && d.getMonth() == dt.getMonth() && d.getDay() == dt.getDay() &&
          d.getHour() == dt.getHour() && d.getMinute() == dt.getMinute() && d.getSecond() == dt.getSecond()) {
            break;
      }
      //cout << d.getYear() << " " << d.getMonth() << " " << d.getDay() << " " << d.getHour() <<  " " << d.getMinute() << " " << d.getSecond() <<endl;
      elapsedSec++;
      d.addSeconds(1);
    }
    _ts->setSec(elapsedSec);

    return *_ts;
  }
private:
  int hour, minute, second;
};

// for Q40
int main() {
  int y, m, d, hh, mm, ss;
  cin>>y>>m>>d>>hh>>mm>>ss;
  DateTime d1(y, m, d, hh, mm, ss);
  cin>>y>>m>>d>>hh>>mm>>ss;
  DateTime d2(y, m, d, hh, mm, ss);
  cout<<(d1 - d2).toTotalSeconds();
  return 0;
}

// ==========

/* for Q39
int main() {
  int n;
  DateTime d(2021, 1, 1);
  cin>>n;
  d.addHours(n);
  cout<<d.toString()<<endl;
  cin>>n;
  d.addMinutes(n);
  cout<<d.toString()<<endl;
  cin>>n;
  d.addSeconds(n);
  cout<<d.toString()<<endl;
  return 0;
}
*/
