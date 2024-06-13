#include <iostream>
#include "electric_car.h"

int main() {
    ElectricCar car1("Tesla Model Y", 256, "LFP");
    ElectricCar car2;
    car2.set_ec();

    car1.output_ec();
    car2.output_ec();

    if (car1 == car2) {
        std::cout << "Identical!" << std::endl;
    } else {
        std::cout << "Different!" << std::endl;
    }

    return 0;
}
