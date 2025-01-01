#include "Knight.h"
#include "Board.h"

Knight::Knight(const Cord& position, const bool isBlack, Board* board, const char type) :Piece(position, isBlack, board, type) {}

bool Knight::isValidMove(Cord dest, int& code)
{
    // Get the current position of the Knight
    Cord src = getCord();

    // Calculate the difference in x and y coordinates
    int dx = abs(dest.getX() - src.getX());
    int dy = abs(dest.getY() - src.getY());

    // Check if the move is a valid L-shape move for a Knight
    if ((dx == 2 && dy == 1) || (dx == 1 && dy == 2))
    {
        // Check if the destination is either empty or contains an opponent's piece
        if (this->getBoard()->isEmpty(dest)) 
       {
            code = 0; // Valid move
            return true;
        }
        else
        {
            // Iterate through the pieces to find the piece at the destination
            Piece** pieces = this->getBoard()->getPieces();
            for (int i = 0; i < this->getBoard()->getWidth() * this->getBoard()->getLength(); ++i)
            {
                Piece* piece = pieces[i];
                if (piece != nullptr && piece->getCord().getX() == dest.getX() && piece->getCord().getY() == dest.getY())
                {
                    if (piece->getIsBlack() != getIsBlack())
                    {
                        code = 0; // Valid move
                        return true;
                    }
                    else
                    {
                        code = 1; // Destination occupied by same color piece
                        return false;
                    }
                }
            }
        }
    }

    code = 2; // Invalid move
    return false;
}

