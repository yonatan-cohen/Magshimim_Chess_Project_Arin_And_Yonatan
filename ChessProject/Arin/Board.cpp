#include "Board.h"
#include "King.h"
#include <iostream>
#include <string>

int Board::_turnNum = 0;

Board::Board() // default constructor
{
	this->_pieces = new Piece* [64];
	for (int i = 0; i < 64; ++i)
		this->_pieces[i] = nullptr;

	this->_width = 8;
	this->_length = 8;
	this->_startingColor = 0; // white
	this->_whiteKing = new King(this);
	this->_blackKing = new King(this);
	_turnNum = 0;
}

Board::Board(Piece** pieces, int width, int length, int startingColor, King* whiteKing, King* blackKing) // value constructor
{
	this->_pieces = pieces;
	this->_width = width;
	this->_length = length;
	this->_startingColor = startingColor;
	this->_whiteKing = whiteKing;
	this->_blackKing = blackKing;
	_turnNum = 0;
}

Board::~Board() // destructor
{
	//delete this->_blackKing;
	//delete this->_whiteKing;
	delete this->_pieces;
}

// getters
Piece** Board::getPieces() const { return this->_pieces; }
int Board::getWidth() const { return this->_width; }
int Board::getLength() const { return this->_length; }
int Board::getStartingColor() const { return this->_startingColor; }
King* Board::getWhiteKing() const { return this->_whiteKing; }
King* Board::getBlackKing() const { return this->_blackKing; }

// function returns if cord on board is empty
bool Board::isEmpty(Cord c) const
{
	int index = c.getX() * c.getY();
	if (this->_pieces[index]->getType() == '#') return true;
	else return false;
}

// function uses fronend info to update board
int Board::reciveFronendInfo(std::string inputPipeStr)
{
	std::string srcCordstr = inputPipeStr.substr(2, 3);
	std::string dstCordstr = inputPipeStr.substr(0, 1);

	Cord srcCord = Cord::stringToCord(srcCordstr);
	Cord dstCord = Cord::stringToCord(dstCordstr);

	int srcIndex = srcCord.getX() * srcCord.getY();
	return this->_pieces[srcIndex]->move(dstCord);
}

// function returns the string that needs to be sent to frontend
std::string Board::sendFrontendInfo(int code)
{
	std::string rString = "";
	rString += std::to_string(code);
	rString += '\0';
	return rString;
}

// function makes the string that initializes frontend
std::string Board::sendBoardToFrontend()
{
	std::string rString = "";

	for (int i = 0; i < 64; i++)
		rString += this->_pieces[i]->getType();

	rString += std::to_string(this->_startingColor);
	rString += '\0';
	return rString;
}
