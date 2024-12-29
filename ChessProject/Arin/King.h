#pragma once
#include "Piece.h"



class King : public Piece
{
public:
    King() : Piece('K') 
    {}
    King(const Cord& position, const bool isBlack,Board* board,const char type);
    ~King() {}

    int isValidMove(Cord dest) override;
};

