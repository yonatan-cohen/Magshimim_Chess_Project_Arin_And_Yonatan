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
    Piece** _pieces; // 2D array of pieces on the board

    int _width; // width of the board
    int _length; // length of the board
    int _startingColor; // starting color of the pieces

    // pointers to white and black king pieces
    King* _whiteKing;
    King* _blackKing;

public:
    /*
    * current player turn
    * false for white, true for black
    */
    bool _turn;
    static int _turnNum; // static variable to keep track of the turn number

    // Default constructor
    Board();

    // Parameterized constructor
    Board(Piece** pieces, int width, int length, int startingColor, King* whiteKing, King* blackKing);

    // Destructor
    ~Board();

    // Getters
    Piece** getPieces() const;
    int getWidth() const;
    int getLength() const;
    int getStartingColor() const;
    King* getWhiteKing() const;
    King* getBlackKing() const;

    // Check if a given coordinate is empty
    bool isEmpty(Cord c) const;

    // Check if a line between two coordinates is empty
    bool isEmptyLine(Cord src, Cord dest) const;

	// Frontend information handling
    int reciveFronendInfo(std::string inputPipe);
    std::string sendFrontendInfo(int code);
    std::string sendBoardToFrontend();
};