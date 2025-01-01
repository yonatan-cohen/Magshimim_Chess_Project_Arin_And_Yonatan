#pragma once
// Pawn.h
#pragma once
#include "Piece.h"

class Pawn : public Piece
{
public:
    Pawn(const Cord& position, const bool isBlack, Board* board, const char type);
    ~Pawn() override {}

    int isValidMove(Cord dest) override;
};
