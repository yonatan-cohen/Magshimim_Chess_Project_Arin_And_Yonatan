#pragma once
#include "Piece.h"
#include "Board.h"

class Board;

class King : public Piece
{
public:
    King();

    King(Cord position, bool isBlack, Board* board);

    bool isValidMove(Cord dest) override;
};