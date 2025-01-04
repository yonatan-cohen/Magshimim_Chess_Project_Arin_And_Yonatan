#pragma once
#include "Piece.h"

class Knight : public Piece
{
public:
    // Default constructor initializing the Knight piece with type 'N'
    Knight() : Piece('N') {}

    // Parameterized constructor initializing the Knight piece with position, color, board, and type
    Knight(const Cord& position, const bool isBlack, Board* board, const char type);

    // Destructor
    ~Knight() override {}

    // Override method to check if a move to the destination coordinate is valid
    int isValidMove(Cord dest) override;
};
