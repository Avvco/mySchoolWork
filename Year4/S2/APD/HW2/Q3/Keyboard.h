#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <iostream>
#include <cstring> // For string manipulation (strcpy)

class Keyboard {
private:
    int NumOfKeys;
    char* Name;
    int MaxLength;
    double Price;

public:
    Keyboard(); // Default constructor
    Keyboard(int _num, const char* _name, double _price); // Parameterized constructor
    Keyboard(const Keyboard& other); // Copy constructor
    ~Keyboard(); // Destructor
    Keyboard& operator=(const Keyboard& other); // Assignment operator

    // Overloaded operators
    friend std::ostream& operator<<(std::ostream& os, const Keyboard& kb);
    Keyboard operator+(const Keyboard& kb);
};

#endif // KEYBOARD_H
