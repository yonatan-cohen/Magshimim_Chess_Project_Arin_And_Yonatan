#include "Piece.h"
#include "King.h"


bool check(Piece** pieces,King* king, bool isBlack)
{
	int isCheck = -1;
	for (int i = 0; i < 64; i++)
	{
		if (pieces[i] != NULL && pieces[i]->getIsBlack() != isBlack)
		{
			isCheck = pieces[i]->isValidMove(king->getCord());
			if (isCheck == 0)
			{
				return true;
			}
		}
	}
	return false;
}

bool Piece::isPinned(Cord dest)
{
	// we assume piece move is valid
	Board* b = this->getBoard();
	King* king = NULL;
	Cord ogCord = this->getCord();
	
	// move temporarily
	Piece* p = this;
	Piece* pd = b->getPieces()[dest.getY() * 8 + dest.getX()];
	b->getPieces()[dest.getY() * 8 + dest.getX()] = p;
	b->getPieces()[this->getCord().getY() * 8 + this->getCord().getX()] = pd;
	pd->_type = '#';
	pd->_isBlack = false;
	p->_position = dest;
	b->_turnNum++;
	b->_turn = !b->_turn;

	bool rValue = false;

	if (this->getIsBlack())
		king = b->getBlackKing();
	else
		king = b->getWhiteKing();

	Piece** pieces = b->getPieces();

	rValue = check(pieces,king,this->getIsBlack());
	
	// undo move
	p = this;
	pd = b->getPieces()[ogCord.getY() * 8 + ogCord.getX()];
	b->getPieces()[ogCord.getY() * 8 + ogCord.getX()] = p;
	b->getPieces()[this->getCord().getY() * 8 + this->getCord().getX()] = pd;
	pd->_type = '#';
	pd->_isBlack = false;
	p->_position = ogCord;
	b->_turnNum++;
	b->_turn = !b->_turn;
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
	if (code == 0 && this->isPinned(dest))
	{
		code = 4;
	}
	if (code == 0)
	{
		Board* temp = this->getBoard();
		King* king = this->getIsBlack() ? temp->getWhiteKing() : temp->getBlackKing();
		if (check(temp->getPieces(),king,!this->getIsBlack()))
		{
			code = 1;
		}
		Piece* p = this;
		Piece* pd = temp->getPieces()[dest.getY() * 8 + dest.getX()];
		temp->getPieces()[dest.getY()*8 + dest.getX()] = p;
		temp->getPieces()[this->getCord().getY() * 8 + this->getCord().getX()] = pd;
		pd->_type = '#';
		pd->_isBlack = false;
		p->_position = dest;
		temp->_turnNum++;
		temp->_turn = !temp->_turn;
	}
	return code;
}
