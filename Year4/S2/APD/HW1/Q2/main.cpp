#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Person {
  double height;
  double weight;
  double bmi;
};


void computeBMI(vector<Person> personBMIs) {
  for(Person p : personBMIs) {
    p.bmi = p.weight / (p.height * p.height);
    p.bmi = (int)(p.bmi * 1000) / 1000.0;
    cout << "The BMI is: " << p.bmi << endl;
  }

}

int main() {
  // read file from height and weight
  ifstream heightFile("height");
  ifstream weightFile("weight");

  vector<Person> personBMIs;
  //read it line by line until the end of file
  string line;
  while (getline(heightFile, line)) {
    // read height from height
    double height = stod(line);
    // read weight from weight
    getline(weightFile, line);
    double weight = stod(line);
    Person p;
    p.height = height;
    p.weight = weight;
    
    personBMIs.push_back(p);
  }
  computeBMI(personBMIs);
}