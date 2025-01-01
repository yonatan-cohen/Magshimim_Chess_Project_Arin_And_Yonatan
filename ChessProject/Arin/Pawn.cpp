// Pawn.cpp
#include "Pawn.h"
#include "Board.h"

Pawn::Pawn(const Cord& position, const bool isBlack, Board* board, const char type)
    : Piece(position, isBlack, board, type) {
}

int Pawn::isValidMove(Cord dest)
{
    // Get the current position of the Pawn
    Cord src = getCord();

    // Calculate the difference in x and y coordinates
    int dx = dest.getX() - src.getX();
    int dy = dest.getY() - src.getY();

    // Check if the move is valid for a Pawn
    if (getIsBlack())
    {
        // Black pawns move down the board
        if (dx == 0 && dy == 1 && getBoard()->isEmpty(dest))
        {
            return 0; // Valid move
        }
        else if (dx == 0 && dy == 2 && src.getY() == 1 && getBoard()->isEmpty(dest) && getBoard()->isEmpty(Cord(src.getX(), src.getY() + 1)))
        {
            return 0; // Valid move
        }
        else if (abs(dx) == 1 && dy == 1 && !getBoard()->isEmpty(dest) && getBoard()->getPieces()[dest.getY() * 8 + dest.getX()]->getIsBlack() != getIsBlack())
        {
            return 0; // Valid move
        }
    }
    else
    {
        // White pawns move up the board
        if (dx == 0 && dy == -1 && getBoard()->isEmpty(dest))
        {
            return 0; // Valid move
        }
        else if (dx == 0 && dy == -2 && src.getY() == 6 && getBoard()->isEmpty(dest) && getBoard()->isEmpty(Cord(src.getX(), src.getY() - 1)))
        {
            return 0; // Valid move
        }
        else if (abs(dx) == 1 && dy == -1 && !getBoard()->isEmpty(dest) && getBoard()->getPieces()[dest.getY() * 8 + dest.getX()]->getIsBlack() != getIsBlack())
        {
            return 0; // Valid move
        }
    }

    return 2; // Valid move
}
