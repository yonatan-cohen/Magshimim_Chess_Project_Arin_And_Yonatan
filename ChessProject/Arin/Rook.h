#pragma once
#include "Piece.h"

class Rook : public Piece
{
public:
    // Parameterized constructor initializing the Rook piece with position, color, board, and type
    Rook(const Cord& position, const bool isBlack, Board* board, const char type);
    // Destructor
    ~Rook() {}
    // Override method to check if a move to the destination coordinate is valid
    int isValidMove(Cord dest) override;
};
