#pragma once

#include "Cord.h"
#include "Board.h"

class Board;
class King;

class Piece
{
private:
	Cord _position;
	char _type;
	bool _isBlack;
	Board* _board;

public:
	virtual ~Piece();

	Cord getCord() const;
	char getType() const;
	bool getIsBlack() const;
	Board* getBoard() const;

	bool move(Cord dest);
	virtual bool isValidMove(Cord dest) = 0;
};