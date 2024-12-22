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
	Piece()
	{
		this->_board = nullptr;
		this->_isBlack = false;
		this->_position = Cord();
		this->_type = '#';
	}
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
	};
	virtual ~Piece() {}

	Cord getCord() const;
	char getType() const;
	bool getIsBlack() const;
	Board* getBoard() const;

	int move(Cord dest);
	virtual bool isValidMove(Cord dest) = 0;
};