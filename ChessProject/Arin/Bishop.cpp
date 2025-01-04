#include "Bishop.h"

// Constructor for Bishop class
Bishop::Bishop(const Cord& position, const bool isBlack, Board* board, const char type) :
	Piece(position, isBlack, board, type)
{	}

// Method to check if a move is valid for the Bishop
int Bishop::isValidMove(Cord dest)
{
	int c = -1; // Initialize return code

	Board* temp = this->getBoard(); // Get the board
	int x = 0;
	int y = 0;

	// Check if destination is out of bounds
	if (dest.getX() > 7 || dest.getX() < 0 || dest.getY() > 7 || dest.getY() < 0)
	{
		c = 5; // Invalid move: out of bounds
	}
	// Check if it's the correct turn and the piece is not a placeholder
	else if (temp->_turn == this->getIsBlack() && this->getType() != '#')
	{
		x = this->getCord().getX() - dest.getX();
		y = this->getCord().getY() - dest.getY();
		
		// Check if the source and destination are the same
		if ((this->getCord().getX() == dest.getX()) && (this->getCord().getY() == dest.getY()))
		{
			c = 7; // Invalid move: same source and destination
		}
		// Check if the move is diagonal
		else if (abs(x) == abs(y))
		{
			// Check if the path is clear
			if (temp->isEmptyLine(this->getCord(), dest))
			{
				// Check if the destination is empty
				if (temp->isEmpty(dest))
				{
					c = 0; // Valid move
				}
				// Check if the destination has an opponent's piece
				else if ((*temp->getPieces()[dest.getY() * 8 + dest.getX()]).getIsBlack() != temp->_turn)
				{
					c = 0; // Valid move: capturing opponent's piece
				}
				else
				{
					c = 3; // Invalid move: destination occupied by own piece
				}
			}
			else
			{
				c = 6; // Invalid move: path is not clear
			}
		}
		else
		{
			c = 6; // Invalid move: not a diagonal move
		}
	}
	else
	{
		c = 2; // Invalid move: not the correct turn or piece is a placeholder
	}
	return c; // Return the result code
}
