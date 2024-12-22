#include "King.h"
#include "Board.h"
int main()
{
	Board* b =new Board();
	King* k = new King(b);
	return 0;
}