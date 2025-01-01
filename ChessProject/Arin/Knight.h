#pragma once
#include "Piece.h"

class Knight : public Piece
{
public:
    Knight(const Cord& position, const bool isBlack, Board* board, const char type);
    ~Knight() override {}

    int isValidMove(Cord dest) override;
};
