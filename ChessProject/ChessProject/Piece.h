#pragma once

#include "Cord.h"

class Piece
{
private:
	Cord* _position;
	char _type;
	bool isBlack;
	Board* _board;

public:
	Piece();
	Piece(Cord* pos, char type, bool isBlack, Board board);
	Piece(const Piece& other);

	~Piece();
	Piece& operator=(const Piece& other);

	Cord* getCord() const;
	char getType() const;
	bool getIsBlack() const;
	Board* getBoard() const;

	bool move(Cord dest);
	virtual bool isValidMove(Cord dest) = 0;
};