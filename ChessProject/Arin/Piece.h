#pragma once

#include "Cord.h"
#include "Board.h"


class Board;

class Piece
{
private:
	Cord _position;
	char _type;
	bool _isBlack;
	Board* _board;

public:
	Piece();
	Piece(const char type) : _type(type)
	{
		this->_board = nullptr;
		this->_isBlack = false;
		this->_position = Cord();
	}
	Piece(Board* board) : _board(board)
	{
		this->_isBlack = false;
		this->_position = Cord();
		this->_type = '#';
	}
	Piece(Board* board, const char type) : _board(board), _type(type) 
	{
		this->_isBlack = false;
		this->_position = Cord();
	}
	Piece(const Cord position, const bool isBlack, Board* board, const char type);
	virtual ~Piece() {}

	Cord getCord() const;
	char getType() const;
	bool getIsBlack() const;
	Board* getBoard() const;

	int move(Cord dest);
	virtual int isValidMove(Cord dest) = 0;
};