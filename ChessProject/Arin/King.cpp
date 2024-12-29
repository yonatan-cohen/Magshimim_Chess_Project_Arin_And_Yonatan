#include "King.h"
#include <math.h>
#include <cctype>
#include <iostream>
#include <cstring>


King::King(const Cord& position, const bool isBlack, Board* board, const char type) : Piece(position,isBlack,board,type)
{}

int King::isValidMove(Cord dest)
{
	Board* temp = this->getBoard();
	int c = -1;
	int d = 0;
	int x = 0;
	int y = 0;
	if (dest.getX() > 7 || dest.getX() < 0 || dest.getY() > 7 || dest.getY() < 0)
	{
		c = 5;
	}
	else if (temp->_turn == this->getIsBlack() && this->getType() != '#')
	{
		c = 0;
		x = this->getCord().getX() - dest.getX();
		y = this->getCord().getY() - dest.getY();
		d = sqrt(pow(x, 2) + pow(y, 2));
		if (d == 1)
		{
			c = 0;
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
		else if ((this->getCord().getX() == dest.getX()) && (this->getCord().getY() == dest.getY()) )
		{
			c = 7;
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
