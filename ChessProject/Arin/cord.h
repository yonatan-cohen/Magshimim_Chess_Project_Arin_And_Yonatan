#pragma once

#include <string.h>
#include <iostream>

class Cord
{
private:
    // coordinate
    int _x;
    int _y;

public:
    // Default constructor
    Cord();

    // Parameterized constructor
    Cord(int x, int y);

    // Destructor
    ~Cord();

    // Copy constructor
    Cord(const Cord& other);

    // Assignment operator
    Cord& operator=(const Cord& other);

    // Getters
    int getX() const;
    int getY() const;

    // Static method to convert string to Cord object
    static Cord stringToCord(std::string cord_string);
};