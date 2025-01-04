#include "Piece.h"
#include "King.h"

bool Piece::isPinned(Cord dest)
{
	// we assume piece move is valid
	Board* b = this->getBoard();
	King* king = NULL;
	Cord ogCord = this->getCord();
	this->_position = dest;

	if (p->getIsBlack())
		king = b->getBlackKing();
	else
		king = b->getWhiteKing();

	Piece** pieces = b->getPieces();
	for (int i = 0; i < 64; i++)
	{
		if (pieces[i] != NULL && pieces[i]->getIsBlack() != p->getIsBlack())
		{
            if (pieces[i]->isValidMove(king->getCord()) == 0)
			{
				p->_position = ogCord;
				return true;
			}
		}
	}
	p->_position = ogCord;
	return false;
}


Piece::Piece()
{
	this->_board = nullptr;
	this->_isBlack = false;
	this->_position = Cord();
	this->_type = '#';
}

//Piece::~Piece() {} // destructor

Piece::Piece(const Cord position, const bool isBlack, Board* board, const char type)
{
	this->_position = position;
	this->_isBlack = isBlack;
	this->_board = board;
	this->_type = type;
}

// getters
Cord Piece::getCord() const { return this->_position; }

char Piece::getType() const { return this->_type; }

bool Piece::getIsBlack() const { return this->_isBlack; }

Board* Piece::getBoard() const { return this->_board; }

// function sets new Piece position if the move is valid
int Piece::move(Cord dest)
{
	int code = -1;
	code = this->isValidMove(dest);
	if (code == 0 || code == 1 || code == 8 && this->isPinned(dest))
		code = 4;
		
	if (code == 0 || code == 1 || code == 8)
	{
		Piece* p = this;
		Piece* pd = this->_board->getPieces()[dest.getY() * 8 + dest.getX()];
		this->_board->getPieces()[dest.getY()*8 + dest.getX()] = p;
		this->_board->getPieces()[this->getCord().getY() * 8 + this->getCord().getX()] = pd;
		pd->_type = '#';
		pd->_isBlack = false;
		p->_position = dest;
		this->_board->_turnNum++;
		this->_board->_turn = !this->_board->_turn;
	}
	return code;
}
