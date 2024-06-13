#ifndef ELECTRIC_CAR_H
#define ELECTRIC_CAR_H

#include "car.h"

class ElectricCar : public Car {
public:
    ElectricCar(); // Default constructor
    ElectricCar(const std::string& model_name, int model_horsepower, const std::string& model_battery_type);

    void horn() const;
    void brake() const;
    std::string get_battery_type() const;
    void set_ec();
    void output_ec() const;

    friend bool operator==(const ElectricCar& car1, const ElectricCar& car2);

private:
    std::string battery_type;
};

#endif // ELECTRIC_CAR_H
