#include "Cord.h"
#include <iostream>
#include <string.h>

// helper function for stringToCord
int getGeometricValue(char letter)
{
    letter = std::toupper(letter);
    if (letter >= 'A' && letter <= 'Z') { return letter - 'A' + 1; }
    return -1;
}

Cord::Cord() // default constructor
{
    this->_x = 0;
    this->_y = 0;
}

Cord::Cord(int x, int y) // value constructor
{
    this->_x = x;
    this->_y = y;
}

Cord::~Cord() {} // destructor

Cord::Cord(const Cord& other) // copy constructor
{
    this->_x = other._x;
    this->_y = other._y;
}

Cord& Cord::operator=(const Cord& other) // essignment operator
{
    if (this != &other)
    {
        _x = other._x;
        _y = other._y;
    }
    return *this;
}

// getters
int Cord::getX() const { return _x; }

int Cord::getY() const { return _y; }

Cord Cord::stringToCord(std::string cord_string) // converts string to cord
{
    if (cord_string.length() != 2)
        return Cord();
    
    int x = getGeometricValue(cord_string[0]);
    int y = (cord_string[1] - '0');

    if (x < 0 || x > 7 || y < 0 || y > 7) return Cord(-1,-1);

    else return Cord(x, y);
}