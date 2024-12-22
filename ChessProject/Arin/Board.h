#pragma once
#include "Cord.h"
#include "Piece.h"
#include <iostream>
using namespace std;

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
	/*
	* current player turn
	* false for white, true for black
	*/
	bool _turn;
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
	string BoardToStirng() const;

	bool isEmpty(Cord c) const;

	int reciveFronendInfo(std::string inputPipe);
	std::string sendFrontendInfo(int code);
	std::string sendBoardToFrontend();
};