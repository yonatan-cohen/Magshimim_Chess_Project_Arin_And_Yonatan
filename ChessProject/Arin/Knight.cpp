#include "Knight.h"
#include "Board.h"

Knight::Knight(const Cord& position, const bool isBlack, Board* board, const char type)
    : Piece(position, isBlack, board, type) {
}

int Knight::isValidMove(Cord dest)
{
    //return code
    int c = -1;

    // Get the current position and the board of the Knight
    Cord src = getCord();
    Board* temp = this->getBoard();

    // Calculate the difference in x and y coordinates
    int dx = abs(dest.getX() - src.getX());
    int dy = abs(dest.getY() - src.getY());

    // Check if the destination is out of the Board
    if (dest.getX() > 7 || dest.getX() < 0 || dest.getY() > 7 || dest.getY() < 0)
    {
        c = 5; // destination outside the Board
    }
    // Check if it is the knight's player's turn
    else if (this->getIsBlack() == this->getBoard()->_turn)
    {
        //Check if the current position and the destination are the same
        if ((src.getX() == dest.getX()) && (src.getY() == dest.getY()))
        {
            c = 7;
        }
        // Check if the move is a valid L-shape move for a Knight
        else if ((dx == 2 && dy == 1) || (dx == 1 && dy == 2))
        {
            // Check if the destination is either empty or contains an opponent's piece
            if (this->getBoard()->isEmpty(dest))
            {
                c =  0; // Valid move
            }
            else if ((*temp->getPieces()[dest.getY() * 8 + dest.getX()]).getIsBlack() != temp->_turn)
            {
                c = 0; // Valid move, Ate an opponent's piece
            }
            else
            {
                c = 3; // Destination has the player's piece
            }
        }
        else
        {
            c = 6;
        }
    }
    else
    {
        c = 2; // Not the player's turn
    }
    return c; // Invalid move
}
