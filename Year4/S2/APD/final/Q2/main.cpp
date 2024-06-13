#include <iostream>
#include <string>

using namespace std;

class Car {
private:
    string model;
    int horsepower;

public:
    // Default constructor
    Car() : model(""), horsepower(-1) {}

    // Constructor with parameters
    Car(string model_name, int model_horsepower) 
        : model(model_name), horsepower(model_horsepower) {}

    // Constant member functions for horn and brake (unchanged)
    void horn() const {
        cout << "BiBi!" << endl;
    }

    void brake() const {
        cout << "Stop!" << endl;
    }

    // Friend functions for overloading operators
    friend istream& operator>>(istream& is, Car& car) {
        cout << "Please input the model and horsepower of the car: " << endl;
        getline(is, car.model);
        is >> car.horsepower;
        is.ignore(); // Clear newline
        return is;
    }

    friend ostream& operator<<(ostream& os, const Car& car) {
        os << "The model and horsepower of the car are " 
           << car.model << " and " << car.horsepower << "." << endl;
        return os;
    }

    friend bool operator==(const Car& car1, const Car& car2) {
        return (car1.model == car2.model && car1.horsepower == car2.horsepower);
    }
};

int main() {
    Car car1("Ford Kuga", 250); // Car with initial values
    Car car2;                  // Car with default values

    cin >> car2; // Input for the second car

    cout << "The data of the two cars:" << endl;
    cout << car1;
    cout << car2;

    if (car1 == car2) {
        cout << "Identical!" << endl;
    } else {
        cout << "Different!" << endl;
    }

    return 0;
}
