#pragma once
#include "Piece.h"
class Queen : public Piece
{
public:
	Queen(const Cord& position, const bool isBlack, Board* board, const char type);
	~Queen() {}

	int isValidMove(Cord dest) override;
};

