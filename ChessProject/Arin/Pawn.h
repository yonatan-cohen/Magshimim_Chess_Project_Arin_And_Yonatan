#pragma once
// Pawn.h
#pragma once
#include "Piece.h"

class Pawn : public Piece
{
public:
    // Constructor that initializes the pawn with a board
    Pawn(Board* board);
    
    // Constructor that initializes the pawn with position, color, board, and type
    Pawn(const Cord& position, const bool isBlack, Board* board, const char type);
    
    // Destructor
    ~Pawn() override {}

    // Method to check if a move to the destination coordinate is valid
    int isValidMove(Cord dest) override;
};