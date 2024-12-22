#pragma once

#include <string.h>
#include <iostream>

class Cord
{
private:
	int _x;
	int _y;

public:
	Cord();
	Cord(int x, int y);

	~Cord();
	Cord(const Cord& other);
	Cord& operator=(const Cord& other);

	int getX() const;
	int getY() const;

	static Cord stringToCord(std::string cord_string);
};