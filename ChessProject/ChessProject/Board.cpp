#include "Board.h"

Board::Board() // default constructor
{
	this->_pieces = new Piece[64];
	this->_width = 8;
	this->_length = 8;
	this->_startingColor = 0; // white
	this->_whiteKing = new King;
	this->_blackKing = new King;
	this->_turnNum = 0;
}

Board::Board(Piece* pieces, int width, int length, int startingColor, King* whiteKing, King* blackKing) // value constructor
{
	this->_pieces = pieces;
	this->_width = width;
	this->_length = length;
	this->_startingColor = startingColor;
	this->_whiteKing = whiteKing;
	this->_blackKing = blackKing;
	this->_turnNum = 0;
}

Board::~Board() // destructor
{
	delete this->_blackKing;
	delete this->_whiteKing;
	delete this->_pieces;
}

// getters
Piece* Board::getPieces() const { return this->_pieces; }
int Board::getWidth() const { return this->_width; }
int Board::getLength() const { return this->_length; }
int Board::getStartingColor() const { return this->_startingColor; }
King* Board::getWhiteKing() const { return this->_whiteKing; }
King* Board::getBlackKing() const { return this->_blackKing; }

//bool Board::isEmpty(Cord c) const
//{
//	int index = c.getX() * c.getY();
//	if (this->_pieces[index].getType() == '#') return true;
//	else return false;
//}

//void Board::update(std::string info)
//{
//	std::string cordStr = info.substr(info.length() - 2);
//	Cord destCord = Cord::stringToCord(cordStr);
//	int index = destCord.getX() * destCord.getY();
//	if (this->_pieces[index].move(destCord) == true) this->_turnNum++;
//	else error();
//}