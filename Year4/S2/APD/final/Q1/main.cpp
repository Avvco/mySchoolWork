#include <iostream>
#include <string>

using namespace std;

class Car {
private:
    string model;
    int horsepower;

public:
    // Member function to set model and horsepower
    void set() {
        cout << "Please input the model and horsepower of the car: " << endl;
        getline(cin, model); // Use getline to handle spaces in the model name
        cin >> horsepower;
        cin.ignore(); // Clear the newline character from the buffer
    }

    // Constant member function to output model and horsepower
    void output() const {
        cout << "The model and horsepower of the car are " 
             << model << " and " << horsepower << "." << endl;
    }

    // Constant member function to simulate horn sound
    void horn() const {
        cout << "BiBi!" << endl;
    }

    // Constant member function to simulate braking
    void brake() const {
        cout << "Stop!" << endl;
    }
};

int main() {
    Car myCar; // Declare a Car object

    myCar.set();    // Get user input for model and horsepower
    myCar.output(); // Display the model and horsepower
    myCar.horn();   // Simulate horn sound
    myCar.brake();  // Simulate braking

    return 0;
}
