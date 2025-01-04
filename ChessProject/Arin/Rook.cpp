#include "Rook.h"

Rook::Rook(const Cord& position, const bool isBlack, Board* board, const char type) : Piece(position, isBlack, board, type)
{}

int Rook::isValidMove(Cord dest)
{
	int c = -1;

	Board* temp = this->getBoard();
	int x = 0;
	int y = 0;

	if (dest.getX() > 7 || dest.getX() < 0 || dest.getY() > 7 || dest.getY() < 0)
	{
		c = 5;
	}
	else if (temp->_turn == this->getIsBlack() && this->getType() != '#')
	{
		x = this->getCord().getX() - dest.getX();
		y = this->getCord().getY() - dest.getY();
		if ((this->getCord().getX() == dest.getX()) && (this->getCord().getY() == dest.getY()))
		{
			c = 7;
		}
		else if (!x || !y)
		{
			if (temp->isEmptyLine(this->getCord(), dest))
			{
				if (temp->isEmpty(dest))
				{

					c = 0;
				}
				else if ((*temp->getPieces()[dest.getY() * 8 + dest.getX()]).getIsBlack() != temp->_turn)
				{
					c = 1;
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
			c = 6;
		}
	}
	else
	{
		c = 2;
	}
	return c;
}
