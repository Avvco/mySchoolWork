#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

struct Date {
  int day;
  int month;
  int year;
};

struct Person {
  string name;
  Date birthdate;
};


int main() {
  // init a vector of Person
  vector<Person> employees;
  // read number of employees
  int n;
  cout << "Enter number of employees: ";
  cin >> n;
  // read employees
  for(int i = 0; i < n; i++) {
    Person p;
    cout << "Enter name of employee " << i + 1 << ": ";
    cin >> p.name;
    cout << "Enter birthdate of employee " << i + 1 << " (dd mm yyyy): ";
    cin >> p.birthdate.day >> p.birthdate.month >> p.birthdate.year;
    employees.push_back(p);
  }

  // print employees
  for(int i = 0; i < n; i++) {
    cout << "==========" << endl;
    cout << "Name of employee " << i + 1 << ": " << employees[i].name << endl;
    cout << "Birthdate of employee " << i + 1 << ": " << employees[i].birthdate.day << "/" << employees[i].birthdate.month << "/" << employees[i].birthdate.year << endl;
  }
}