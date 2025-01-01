#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include "King.h"
#include "Knight.h"
#include "Bishop.h"
#include "Rook.h"
#include "Board.h"
#include "Pawn.h"

int Board::_turnNum = 0;
Board::Board() // default constructor
{
	string sb = "rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR0";
	// i = 1-8 , j = a-e
	int i = 0, j = 0;
	this->_pieces = new Piece*[64];
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			//make each piece it's type
			switch (sb[i * 8 + j])
			{
			case '#':
				//will be replaced by pawn later
				this->_pieces[i*8 + j] = NULL;
				break;
			case 'p':
			case 'P':
				this->_pieces[i * 8 + j] = new Pawn(Cord(j, i), islower(sb[i * 8 + j]), this, sb[i * 8 + j]);
				break;
			case 'r':
			case 'R':
				this->_pieces[i * 8 + j] = new Rook(Cord(j, i), islower(sb[i * 8 + j]), this, sb[i * 8 + j]);
				break;
			case 'n':
			case 'N':
				this->_pieces[i * 8 + j] = new Knight(Cord(j, i), islower(sb[i * 8 + j]), this, sb[i * 8 + j]);
				break;
			case 'b':
			case 'B':
				this->_pieces[i * 8 + j] = new Bishop(Cord(j, i), islower(sb[i * 8 + j]), this, sb[i * 8 + j]);
				break;
			case 'q':
			case 'Q':
				this->_pieces[i * 8 + j] = new King(Cord(j, i), islower(sb[i * 8 + j]), this, sb[i * 8 + j]);
				break;
			case 'k': 
				this->_blackKing = new King(Cord(j, i), islower(sb[i * 8 + j]), this, sb[i * 8 + j]);
				this->_pieces[i * 8 + j] = this->_blackKing;
				break;
			case 'K':
				this->_whiteKing = new King(Cord(j, i), islower(sb[i * 8 + j]), this, sb[i * 8 + j]);
				this->_pieces[i * 8 + j] = this->_whiteKing;
				break;
			default:
				break;
			}
		}
	}

	this->_width = 8;
	this->_length = 8;
	this->_startingColor = 0; // white
	this->_turn = this->_startingColor;
	_turnNum = 0;
}

Board::Board(Piece** pieces, int width, int length, int startingColor, King* whiteKing, King* blackKing) // value constructor
{
	this->_pieces = pieces;
	this->_width = width;
	this->_length = length;
	this->_startingColor = startingColor;
	this->_turn = this->_startingColor;
	this->_whiteKing = whiteKing;
	this->_blackKing = blackKing;
	_turnNum = 0;
}

Board::~Board() // destructor
{
	delete this->_blackKing;
	delete this->_whiteKing;
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
	return ((*this->_pieces[c.getY() * 8 + c.getX()]).getType() == '#');
}

//function returns if line made by 2 cords is empty
bool Board::isEmptyLine(Cord src, Cord dst) const
{
	bool notEmpty = false;
	int x, y, i;
	int ix, iy;
	x = dst.getX() - src.getX();
	y = dst.getY() - src.getY();
	ix = src.getX();
	iy = src.getY();
	if (x < 0)
	{
		ix = dst.getX();
	}
	if (y < 0)
	{
		iy = dst.getY();
	}
	x = abs(x);
	y = abs(y);
	if (x && !y)
	{
		for (i = 1; i < x; i++)
		{
			notEmpty += !(this->isEmpty(Cord(ix + i, iy)));
		}
	}
	else if(y && !x)
	{
		for (i = 1; i < y; i++)
		{
			notEmpty += !(this->isEmpty(Cord(ix, iy + i)));
		}
	}
	else
	{
		for (i = 1; i < x; i++)
		{
			notEmpty += !(this->isEmpty(Cord(ix + i, iy + i)));
		}
	}
	return !notEmpty;
}



// function uses fronend info to update board
int Board::reciveFronendInfo(std::string inputPipeStr)
{
	std::string dstCordstr = inputPipeStr.substr(2, 3);
	std::string srcCordstr = inputPipeStr.substr(0, 2);

	Cord srcCord = Cord::stringToCord(srcCordstr);
	Cord dstCord = Cord::stringToCord(dstCordstr);
	return (*this->_pieces[(srcCord.getY() - 1) * 8 + srcCord.getX()]).move(dstCord);
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
		if (this->_pieces[i] != NULL)
			rString += this->_pieces[i]->getType();
		else
			rString += '#';

	rString += std::to_string(this->_startingColor);
	rString += '\0';
	return rString;
}
