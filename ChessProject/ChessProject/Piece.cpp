#include "Piece.h"

Piece::~Piece() {} // destructor

// getters
Cord Piece::getCord() const { return this->_position; }

char Piece::getType() const { return this->_type; }

bool Piece::getIsBlack() const { return this->_isBlack; }

Board* Piece::getBoard() const { return this->_board; }

// function sets new Piece position if the move is valid
int Piece::move(Cord dest)
{
	int code = -1;
	if (this->isValidMove(dest, code))
	{
		this->_position = dest;
		this->_board->_turnNum++;
	}
	return code;
}