#include "electric_car.h"
#include <iostream>

ElectricCar::ElectricCar() : Car(), battery_type("") {}

ElectricCar::ElectricCar(const std::string& model_name, int model_horsepower, const std::string& model_battery_type)
    : Car(model_name, model_horsepower), battery_type(model_battery_type) {}

void ElectricCar::horn() const {
    std::cout << "BiBi from an electric car!" << std::endl;
}

void ElectricCar::brake() const {
    std::cout << "Stop from an electric car!" << std::endl;
}

std::string ElectricCar::get_battery_type() const {
    return battery_type;
}

void ElectricCar::set_ec() {
    set();
    std::cout << "Please input the battery type of the car:" << std::endl;
    getline(std::cin, battery_type);
}

void ElectricCar::output_ec() const {
    std::cout << "The model, horsepower, and battery type of the car are " 
              << get_model() << ", " << get_horsepower() << ", and " 
              << battery_type << "." << std::endl;
}

bool operator==(const ElectricCar& car1, const ElectricCar& car2) {
    return (car1.get_model() == car2.get_model()) && (car1.get_horsepower() == car2.get_horsepower()) && (car1.battery_type == car2.battery_type);
}
