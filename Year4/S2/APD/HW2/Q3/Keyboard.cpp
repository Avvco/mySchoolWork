#include "Keyboard.h"

Keyboard::Keyboard() : NumOfKeys(0), MaxLength(32), Price(-1.0) {
    Name = new char[MaxLength + 1];
    Name[0] = '\0'; // Initialize to empty string
}

Keyboard::Keyboard(int _num, const char* _name, double _price) : NumOfKeys(_num), Price(_price) {
    MaxLength = strlen(_name);
    Name = new char[MaxLength + 1];
    strcpy(Name, _name);
}

Keyboard::Keyboard(const Keyboard& other) {
    NumOfKeys = other.NumOfKeys;
    MaxLength = other.MaxLength;
    Price = other.Price;
    Name = new char[MaxLength + 1];
    strcpy(Name, other.Name);
}

Keyboard::~Keyboard() {
    delete[] Name;
}

Keyboard& Keyboard::operator=(const Keyboard& other) {
    if (this != &other) {
        delete[] Name;

        NumOfKeys = other.NumOfKeys;
        MaxLength = other.MaxLength;
        Price = other.Price;
        Name = new char[MaxLength + 1];
        strcpy(Name, other.Name);
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Keyboard& kb) {
    os << "The number of Keys is: " << kb.NumOfKeys << std::endl;
    os << "The name is: " << kb.Name << std::endl;
    os << "The price is: " << kb.Price << std::endl;
    return os;
}

Keyboard Keyboard::operator+(const Keyboard& kb) {
    Keyboard temp;
    temp.MaxLength = MaxLength + kb.MaxLength;
    temp.Name = new char[temp.MaxLength + 1];

    strcpy(temp.Name, Name);
    strcat(temp.Name, kb.Name); // Concatenate names

    temp.NumOfKeys = NumOfKeys + kb.NumOfKeys;
    temp.Price = Price + kb.Price;
    return temp;
}
