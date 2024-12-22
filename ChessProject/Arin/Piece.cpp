#include "Piece.h"


//Piece::Piece()
//{
//	this->_board = nullptr;
//	this->_isBlack = false;
//	this->_position = Cord();
//	this->_type = '#';
//}

//Piece::~Piece() {} // destructor

Piece::Piece(const Cord position, const bool isBlack, Board* board, const char type)
{
	this->_position = position;
	this->_isBlack = isBlack;
	this->_board = board;
	this->_type = type;
}

// getters
Cord Piece::getCord() const { return this->_position; }

char Piece::getType() const { return this->_type; }

bool Piece::getIsBlack() const { return this->_isBlack; }

Board* Piece::getBoard() const { return this->_board; }

// function sets new Piece position if the move is valid
int Piece::move(Cord dest)
{
	int code = -1;
	code = this->isValidMove(dest);
	if (code == 0 || code == 1 || code == 8)
	{
		Piece* p = &this->_board->getPieces()[dest.getY()][dest.getX()];
		this->_board->getPieces()[dest.getY()][dest.getX()] = *this;
		this->_board->getPieces()[this->getCord().getY()][this->getCord().getX()]._type = '#';
		this->_board->getPieces()[dest.getY()][dest.getX()]._position = dest;
		this->_board->_turnNum++;
		this->_board->_turn = !this->_board->_turn;
	}
	return code;
}