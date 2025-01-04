#pragma once
#include "Piece.h"

class Queen : public Piece
{
public:
    // Constructor initializing the Queen piece with position, color, board, and type
    Queen(const Cord& position, const bool isBlack, Board* board, const char type);
    // Destructor
    ~Queen() {}

    // Override method to check if a move to the destination coordinate is valid
    int isValidMove(Cord dest) override;
};