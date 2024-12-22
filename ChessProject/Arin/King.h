#pragma once
#include "Piece.h"



class King : public Piece
{
public:
    King() : Piece('K') 
    {}
    King(Board* board);

    King(const Cord& position, const bool isBlack,Board& board,const char type);
    ~King() {}

    bool isValidMove(Cord dest) override;
};

