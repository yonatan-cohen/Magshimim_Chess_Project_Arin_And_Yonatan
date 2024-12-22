#include "King.h"
#include <math.h>
#include <cctype>
#include <iostream>
#include <cstring>

King::King(Board* board) : Piece(board,'k')
{
}

King::King(const Cord& position, const bool isBlack, Board* board, const char type) : Piece(position,isBlack,board,type)
{
}

int King::isValidMove(Cord dest)
{
	int c = -1;
	int d = 0;
	int x = 0;
	int y = 0;
	if (this->getBoard()->_turn == this->getIsBlack() && this->getType() != '#')
	{
		c = 0;
		x = this->getCord().getX() - dest.getX();
		y = this->getCord().getY() - dest.getY();
		d = sqrt(pow(x, 2) + pow(y, 2));
		if (d == 1 || (d == 2 && x==1 && y==1))
		{
			c = 0;
			if (this->getBoard()->isEmpty(dest))
			{
				c = 0;
			}
			else if (this->getBoard()->getPieces()[dest.getX()][dest.getY()].getIsBlack() != this->getBoard()->_turn)
			{
				c = 1;
			}
			else
			{
				c = 3;
			}
		}
		else if ((this->getCord().getX() == dest.getX()) && (this->getCord().getY() == dest.getY()) )
		{
			c = 7;
		}
		else
		{
			c = 6;
		}
	}
	else if (dest.getX() > 8 || dest.getY() > 8)
	{
		c = 5;
	}
	else
	{
		c = 2;
	}
	
	return c;
}
