rm -rf *.o
rm -rf main
g++ -c car.cpp -o car.o
g++ -c electric_car.cpp -o electric_car.o
g++ main.cpp car.o electric_car.o -o main
./main
rm -rf *.o
rm -rf main