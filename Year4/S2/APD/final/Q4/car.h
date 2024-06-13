#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string>

class Car {
public:
    Car(); // Default constructor
    Car(const std::string& model_name, int model_horsepower);

    void horn() const;
    void brake() const;
    void set();
    void output() const;

    std::string get_model() const;
    int get_horsepower() const;

    friend std::istream& operator>>(std::istream& is, Car& car);
    friend std::ostream& operator<<(std::ostream& os, const Car& car);
    friend bool operator==(const Car& car1, const Car& car2);

private:
    std::string model;
    int horsepower;
};

#endif // CAR_H
