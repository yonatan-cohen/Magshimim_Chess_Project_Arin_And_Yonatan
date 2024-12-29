#pragma once
#include "Piece.h"
class Bishop : public Piece
{
public:
	Bishop(const Cord& position, const bool isBlack, Board* board, const char type);
	~Bishop() {}

	int isValidMove(Cord dest) override;
};

