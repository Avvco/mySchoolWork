#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Person {
  double height;
  double weight;
  double bmi;
};


void computeBMI(Person *personBMIs, int size) {
  for(int i = 0; i < size; i++) {
    personBMIs[i].bmi = personBMIs[i].weight / (personBMIs[i].height * personBMIs[i].height);
    personBMIs[i].bmi = (int)(personBMIs[i].bmi * 1000) / 1000.0;
    cout << "The BMI is: " << personBMIs[i].bmi << endl;
  }
}

int main() {
  // read file from height and weight
  ifstream _heightFile("height");
  ifstream heightFile("height");
  ifstream weightFile("weight");

  int counter = 0;
  string _line;
  while (getline(_heightFile, _line)) {
    counter++;
  }

  Person *personBMIs = new Person[counter];


  string line;
  int index = 0;
  while (getline(heightFile, line)) {
    // read height from height.txt
    double height = stod(line);
    // read weight from weight.txt
    getline(weightFile, line);
    double weight = stod(line);
    Person p;
    p.height = height;
    p.weight = weight;
    personBMIs[index] = p;
    index++;
  }
  computeBMI(personBMIs, counter);
  free(personBMIs);
}