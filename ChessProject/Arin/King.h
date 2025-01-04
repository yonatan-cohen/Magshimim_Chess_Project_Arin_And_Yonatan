#pragma once
#include "Piece.h"

class King : public Piece
{
public:
    // Default constructor initializing the King piece with type 'K'
    King() : Piece('K') 
    {}

    // Parameterized constructor initializing the King piece with position, color, board, and type
    King(const Cord& position, const bool isBlack, Board* board, const char type);

    // Destructor
    ~King() {}

    // Override method to check if a move to the destination coordinate is valid
    int isValidMove(Cord dest) override;
};
