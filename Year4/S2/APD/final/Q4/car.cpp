#include "car.h"

Car::Car() : model(""), horsepower(-1) {}

Car::Car(const std::string& model_name, int model_horsepower)
    : model(model_name), horsepower(model_horsepower) {}

void Car::horn() const {
    std::cout << "BiBi!" << std::endl;
}

void Car::brake() const {
    std::cout << "Stop!" << std::endl;
}

void Car::set() {
    std::cout << "Please input the model and horsepower of the car: " << std::endl;
    getline(std::cin, model);
    std::cin >> horsepower;
    std::cin.ignore(); // Clear newline
}

void Car::output() const {
    std::cout << "The model and horsepower of the car are " << model << ", " << horsepower << "." << std::endl;
}

std::string Car::get_model() const {
    return model;
}

int Car::get_horsepower() const {
    return horsepower;
}

std::istream& operator>>(std::istream& is, Car& car) {
    std::cout << "Please input the model and horsepower of the car: " << std::endl;
    is >> car.model >> car.horsepower;
    return is;
}

std::ostream& operator<<(std::ostream& os, const Car& car) {
    os << "The model and horsepower of the car are " << car.model << ", " << car.horsepower << "." << std::endl;
    return os;
}

bool operator==(const Car& car1, const Car& car2) {
    return (car1.model == car2.model) && (car1.horsepower == car2.horsepower);
}
