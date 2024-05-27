#include <iostream>
#include <string>

using namespace std;

class MotorcycleType {
private:
    string Model;
    int Displacement;

public:
    // Default constructor
    MotorcycleType() : Model(""), Displacement(-1) {}

    // Set member variables
    void Set(const string& _M, int _D) {
        Model = _M;
        Displacement = _D;
    }

    // Output member variables
    void Output() const {
        cout << "Model: " << Model << endl;
        cout << "Displacement: " << Displacement << "cc" << endl;
    }

    // Overload << operator for output
    friend ostream& operator<<(ostream& os, const MotorcycleType& mt) {
        os << "Model: " << mt.Model << endl;
        os << "Displacement: " << mt.Displacement << "cc" << endl;
        return os;
    }

    // Overload >> operator for input
    friend istream& operator>>(istream& is, MotorcycleType& mt) {
        cout << "Enter Model (can include spaces): ";
        getline(is, mt.Model); // Use getline to allow spaces in model

        cout << "Enter Displacement (cc): ";
        is >> mt.Displacement;
        return is;
    }
};

int main() {
    MotorcycleType MT; // Declare a MotorcycleType object

    // Get input from the user
    cin >> MT; // Use overloaded >> operator

    // Output the motorcycle information
    cout << "\nMotorcycle Information:\n";
    cout << MT; // Use overloaded << operator

    return 0;
}
