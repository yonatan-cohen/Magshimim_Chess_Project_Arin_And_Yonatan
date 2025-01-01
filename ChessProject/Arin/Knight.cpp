#include "Knight.h"
#include "Board.h"

Knight::Knight(const Cord& position, const bool isBlack, Board* board, const char type)
    : Piece(position, isBlack, board, type) {
}

int Knight::isValidMove(Cord dest)
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
            return 0; // Valid move
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
						return 0; // Valid move
                    }
                    else
                    {
                        return 1; // Destination occupied by same color piece
                    }
                }
            }
        }
    }

    return 2; // Invalid move
}
