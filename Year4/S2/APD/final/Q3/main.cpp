#include <iostream>
#include <string>
#include <cstring>

using namespace std;

namespace CarName {
    class Car {
    private:
        string model;
        int horsepower;
        char* nickname;
        int max_size;

    public:
        // Default constructor
        Car() : model(""), horsepower(-1), max_size(32) {
            nickname = new char[max_size + 1];
            strcpy(nickname, "");
        }

        // Constructor with model and horsepower
        Car(string model_name, int model_horsepower) : model(model_name), horsepower(model_horsepower), max_size(32) {
            nickname = new char[max_size + 1];
            strcpy(nickname, "");
        }

        // Constructor with model, horsepower, and nickname
        Car(string model_name, int model_horsepower, string model_nickname) 
            : model(model_name), horsepower(model_horsepower) {
            max_size = model_nickname.length();
            nickname = new char[max_size + 1];
            strcpy(nickname, model_nickname.c_str());
        }

        // Copy constructor
        Car(const Car& other) {
            model = other.model;
            horsepower = other.horsepower;
            max_size = other.max_size;
            nickname = new char[max_size + 1];
            strcpy(nickname, other.nickname);
        }

        // Destructor
        ~Car() {
            delete[] nickname;
        }

        // Overloaded assignment operator
        Car& operator=(const Car& other) {
            if (this != &other) {
                delete[] nickname; 
                model = other.model;
                horsepower = other.horsepower;
                max_size = other.max_size;
                nickname = new char[max_size + 1];
                strcpy(nickname, other.nickname);
            }
            return *this;
        }

        // Constant member functions for horn and brake
        void horn() const {
            cout << "BiBi!" << endl;
        }

        void brake() const {
            cout << "Stop!" << endl;
        }

        // Friend functions for overloading operators
        friend istream& operator>>(istream& is, Car& car) {
            cout << "Please input the model, horsepower, and nickname of the car: " << endl;
            getline(is, car.model);
            is >> car.horsepower;
            is.ignore(); // Clear newline
            is.getline(car.nickname, car.max_size);
            return is;
        }

        friend ostream& operator<<(ostream& os, const Car& car) {
            os << "The model, horsepower, and nickname of the car are " 
               << car.model << ", " << car.horsepower << ", and " << car.nickname << "." << endl;
            return os;
        }

        friend bool operator==(const Car& car1, const Car& car2) {
            return (car1.model == car2.model && 
                    car1.horsepower == car2.horsepower &&
                    strcmp(car1.nickname, car2.nickname) == 0);
        }
    };
}

using namespace CarName;

int main() {
    Car car1("Ford Kuga", 250, "Kugy");
    Car car2;

    cin >> car2;

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
