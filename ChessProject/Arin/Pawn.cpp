// Pawn.cpp
#include "Pawn.h"
#include "Board.h"

Pawn::Pawn(Board* board) : Piece(board)
{
}

Pawn::Pawn(const Cord& position, const bool isBlack, Board* board, const char type)
    : Piece(position, isBlack, board, type) {
}

int Pawn::isValidMove(Cord dest)
{
	//the code for the move
	int c = -1;
    // Get the current position of the Pawn
    Cord src = getCord();
	//save the current board
	Board* temp = this->getBoard();

    // Calculate the difference in x and y coordinates
    int dx = dest.getX() - src.getX();
    int dy = dest.getY() - src.getY();
	dy = abs(dy);

	//bool for pawn starting move
	bool firstMove = (src.getY() == 6 && !this->getIsBlack()) || (src.getY() == 1 && this->getIsBlack());

    /*
	Check if the move is valid for a Pawn
	*/ 
	//check if the dest is not on the board
	if (dest.getX() > 7 || dest.getX() < 0 || dest.getY() > 7 || dest.getY() < 0)
	{
		c = 5;
	}
	//if the pawn is the player's pawn
	else if (temp->_turn == this->getIsBlack() && this->getType() != '#')
	{
		//if the pawn can move there
		if (!dx && (dy == 1 || dy == 2 && firstMove ))
		{
			// checks for pieces in front
			if (temp->isEmptyLine(src, dest))
			{
				// if the dest has no piece
				if (temp->isEmpty(dest))
				{

					c = 0;
				}
				//there is the player piece in dest
				else
				{
					c = 3;
				}
			}
			//the pawn can't move there
			else
			{
				c = 6;
			}
		}
		// if the pawn eats another piece
        else if (temp->getPieces()[dest.getY() * 8 + dest.getX()]->getIsBlack() != temp->_turn &&
        (dest.getX() - 1 == src.getX() || dest.getX() + 1 == src.getX()) && dy == 1)
		{
			c = 1;
		}
		// the dest and src are the same
		else if ((src.getX() == dest.getX()) && (src.getY() == dest.getY()))
		{
			c = 7;
		}
		//the pawn can't move there
		else
		{
			c = 6;
		}
	}
	//the pawn doesn't belong to the player
	else
	{
		c = 2;
	}
	return c;
}
