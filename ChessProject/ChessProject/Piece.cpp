#include "Piece.h"

Piece::~Piece() {} // destructor

// getters
Cord Piece::getCord() const { return this->_position; }

char Piece::getType() const { return this->_type; }

bool Piece::getIsBlack() const { return this->_isBlack; }

Board* Piece::getBoard() const { return this->_board; }

// function sets new Piece position if the move is valid
bool Piece::move(Cord dest)
{
	if (this->isValidMove(dest))
	{
		this->_position = dest;
		return true;
	}
	else return false;
}