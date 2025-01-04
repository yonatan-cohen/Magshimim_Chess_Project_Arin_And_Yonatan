#include "Piece.h"
#include "King.h"

bool Piece::isPinned(Cord dest)
{
	// we assume piece move is valid
	Board* b = this->getBoard();
	King* king = NULL;
	Cord ogCord = this->getCord();
	
	// move temporarily
	Piece* p = this;
	Piece* pd = this->_board->getPieces()[dest.getY() * 8 + dest.getX()];
	this->_board->getPieces()[dest.getY() * 8 + dest.getX()] = p;
	this->_board->getPieces()[this->getCord().getY() * 8 + this->getCord().getX()] = pd;
	pd->_type = '#';
	pd->_isBlack = false;
	p->_position = dest;
	this->_board->_turnNum++;
	this->_board->_turn = !this->_board->_turn;

	int ischeck = -1;
	bool rValue = false;

	if (this->getIsBlack())
		king = b->getBlackKing();
	else
		king = b->getWhiteKing();

	Piece** pieces = b->getPieces();
	for (int i = 0; i < 64; i++)
	{
		if (pieces[i] != NULL && pieces[i]->getIsBlack() != this->getIsBlack())
		{
			if (pieces[i]->getType() == 'R' || pieces[i]->getType() == 'r')
				int x = 0;
			ischeck = pieces[i]->isValidMove(king->getCord());
            if (ischeck == 0 || ischeck == 1 || ischeck == 8)
			{
				rValue = true;
			}
		}
	}
	
	// undo move
	p = this;
	pd = this->_board->getPieces()[ogCord.getY() * 8 + ogCord.getX()];
	this->_board->getPieces()[ogCord.getY() * 8 + ogCord.getX()] = p;
	this->_board->getPieces()[this->getCord().getY() * 8 + this->getCord().getX()] = pd;
	pd->_type = '#';
	pd->_isBlack = false;
	p->_position = ogCord;
	this->_board->_turnNum++;
	this->_board->_turn = !this->_board->_turn;
	return rValue;
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
	if ((code == 0 || code == 1 || code == 8) && this->isPinned(dest))
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
