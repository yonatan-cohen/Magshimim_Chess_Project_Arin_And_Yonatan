#include "King.h"


King::King(Board* board) : Piece(board,'k')
{
}

King::King(const Cord& position, const bool isBlack, Board& board, const char type)
{
}

bool King::isValidMove(Cord dest)
{
	return false;
}
