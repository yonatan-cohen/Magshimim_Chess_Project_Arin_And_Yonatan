#pragma once
#include "Piece.h"
#include "King.h"
#include "Cord.h"

class Piece;
class King;

class Board
{
private:
	Piece** _pieces;

	int _width;
	int _length;
	int _startingColor;

	King* _whiteKing;
	King* _blackKing;

public:
	static int _turnNum;

	Board();
	Board(Piece** pieces, int width, int length, int startingColor, King* whiteKing, King* blackKing);
	~Board();

	Piece** getPieces() const;
	int getWidth() const;
	int getLength() const;
	int getStartingColor() const;
	King* getWhiteKing() const;
	King* getBlackKing() const;

	bool isEmpty(Cord c) const;
	void update(std::string info);

	//fix later
	//std::string reciveFronendInfo(Pipe& inputPipe);
	//void sendFrontendInfo(Pipe& inputPipe);
};