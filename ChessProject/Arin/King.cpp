#include "King.h"
#include <math.h>
#include <cctype>
#include <iostream>
#include <cstring>

// Constructor for King class
King::King(const Cord& position, const bool isBlack, Board* board, const char type) : Piece(position, isBlack, board, type)
{}

// Method to check if the move is valid for the King piece
int King::isValidMove(Cord dest)
{
    Board* temp = this->getBoard();
    int c = -1;
    int d = 0;
    int x = 0;
    int y = 0;

    // Check if the destination is out of bounds
    if (dest.getX() > 7 || dest.getX() < 0 || dest.getY() > 7 || dest.getY() < 0)
    {
        c = 5;
    }
    // Check if it's the correct turn and the piece is not a placeholder
    else if (temp->_turn == this->getIsBlack() && this->getType() != '#')
    {
        c = 0;
        x = this->getCord().getX() - dest.getX();
        y = this->getCord().getY() - dest.getY();
        d = sqrt(pow(x, 2) + pow(y, 2));

        // Check if the destination is the same as the current position
        if ((this->getCord().getX() == dest.getX()) && (this->getCord().getY() == dest.getY()))
        {
            c = 7;
        }
        // Check if the move is within one square
        else if (d == 1)
        {
            c = 0;
            // Check if the destination is empty
            if (temp->isEmpty(dest))
            {
                c = 0;
            }
            // Check if the destination has an opponent's piece
            else if ((*temp->getPieces()[dest.getY() * 8 + dest.getX()]).getIsBlack() != temp->_turn)
            {
                c = 0;
            }
            else
            {
                c = 3;
            }
        }
        else
        {
            c = 6;
        }
    }
    else
    {
        c = 2;
    }

    return c;
}
