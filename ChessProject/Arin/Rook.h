#pragma once
#include "Piece.h"
class Rook : public Piece
{
public:
	Rook(const Cord& position, const bool isBlack, Board* board, const char type);
	~Rook() {}
	int isValidMove(Cord dest) override;
};

