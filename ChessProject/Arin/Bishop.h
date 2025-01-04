#pragma once
#include "Piece.h"

class Bishop : public Piece
{
public:
    // Constructor for Bishop class
    Bishop(const Cord& position, const bool isBlack, Board* board, const char type);
    
    // Destructor for Bishop class
    ~Bishop() {}

    // Method to check if a move is valid for the Bishop
    int isValidMove(Cord dest) override;
};
