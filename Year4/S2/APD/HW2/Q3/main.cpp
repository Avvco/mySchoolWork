#define _CRT_SECURE_NO_WARNINGS // To avoid error 4996
#include <iostream>
#include "Keyboard.h"

using namespace std;

int main() {
    char name[100];
    int numKeys;
    double price;

    cout << "The first keyboard:\n";
    cout << "Please input the number of keys: ";
    cin >> numKeys;
    cin.ignore(); // Consume newline
    cout << "Please input the name: ";
    cin.getline(name, 100);
    cout << "Please input the price: ";
    cin>> price;
    cin.ignore(); // Consume newline

    Keyboard KBOne(numKeys, name, price);

    cout << "\nThe second keyboard:\n";
    cout << "Please input the number of keys: ";
    cin >> numKeys;
    cin.ignore(); // Consume newline
    cout << "Please input the name: ";
    cin.getline(name, 100);
    cout << "Please input the price: ";
    cin >> price;

    Keyboard KBTwo(numKeys, name, price);

    Keyboard KBThree = KBOne + KBTwo;
    cout << "\n" << KBThree; 

    return 0;
}
