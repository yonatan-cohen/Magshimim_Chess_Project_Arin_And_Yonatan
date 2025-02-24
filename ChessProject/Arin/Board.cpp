#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include "King.h"
#include "Knight.h"
#include "Bishop.h"
#include "Rook.h"
#include "Board.h"
#include "Pawn.h"
#include "Queen.h"

// Initialize static member variable
int Board::_turnNum = 0;

// Default constructor
Board::Board()
{
    // Initial board setup string
    string sb = "rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR0";
    // i = 1-8 , j = a-e
    int i = 0, j = 0;
    this->_pieces = new Piece*[64];
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            // Create each piece based on the character in the setup string
            switch (sb[i * 8 + j])
            {
            case '#':
                this->_pieces[i*8 + j] = new Pawn(this);
                break;
            case 'p':
            case 'P':
                this->_pieces[i * 8 + j] = new Pawn(Cord(j, i), islower(sb[i * 8 + j]), this, sb[i * 8 + j]);
                break;
            case 'r':
            case 'R':
                this->_pieces[i * 8 + j] = new Rook(Cord(j, i), islower(sb[i * 8 + j]), this, sb[i * 8 + j]);
                break;
            case 'n':
            case 'N':
                this->_pieces[i * 8 + j] = new Knight(Cord(j, i), islower(sb[i * 8 + j]), this, sb[i * 8 + j]);
                break;
            case 'b':
            case 'B':
                this->_pieces[i * 8 + j] = new Bishop(Cord(j, i), islower(sb[i * 8 + j]), this, sb[i * 8 + j]);
                break;
            case 'q':
            case 'Q':
                this->_pieces[i * 8 + j] = new Queen(Cord(j, i), islower(sb[i * 8 + j]), this, sb[i * 8 + j]);
                break;
            case 'k': 
                this->_blackKing = new King(Cord(j, i), islower(sb[i * 8 + j]), this, sb[i * 8 + j]);
                this->_pieces[i * 8 + j] = this->_blackKing;
                break;
            case 'K':
                this->_whiteKing = new King(Cord(j, i), islower(sb[i * 8 + j]), this, sb[i * 8 + j]);
                this->_pieces[i * 8 + j] = this->_whiteKing;
                break;
            default:
                break;
            }
        }
    }

    this->_width = 8;
    this->_length = 8;
    this->_startingColor = 0; // white
    this->_turn = this->_startingColor;
    _turnNum = 0;
}

// Parameterized constructor
Board::Board(Piece** pieces, int width, int length, int startingColor, King* whiteKing, King* blackKing)
{
    this->_pieces = pieces;
    this->_width = width;
    this->_length = length;
    this->_startingColor = startingColor;
    this->_turn = this->_startingColor;
    this->_whiteKing = whiteKing;
    this->_blackKing = blackKing;
    _turnNum = 0;
}

// Destructor
Board::~Board()
{
    delete this->_blackKing;
    delete this->_whiteKing;
    delete this->_pieces;
}

// Getters
Piece** Board::getPieces() const { return this->_pieces; }
int Board::getWidth() const { return this->_width; }
int Board::getLength() const { return this->_length; }
int Board::getStartingColor() const { return this->_startingColor; }
King* Board::getWhiteKing() const { return this->_whiteKing; }
King* Board::getBlackKing() const { return this->_blackKing; }

// Function to check if a given coordinate on the board is empty
bool Board::isEmpty(Cord c) const
{
    return ((*this->_pieces[c.getY() * 8 + c.getX()]).getType() == '#');
}

// Function to check if the line between two coordinates is empty
bool Board::isEmptyLine(Cord src, Cord dst) const
{
    bool notEmpty = false;
    int x, y, i;
    int ix, iy;
    /*
    * ax/y - going forward or backward in x/y
    * ax/y = 1 - forward
    * ax/y = -1 - backward
    */
    int ax = 1, ay = 1;

    x = dst.getX() - src.getX();
    y = dst.getY() - src.getY();
    ix = src.getX();
    iy = src.getY();
    if (x < 0)
    {
        ax = -1;
    }
    if (y < 0)
    {
        ay = -1;
    }
    x = abs(x);
    y = abs(y);
    if (x && !y)
    {
        for (i = 1; i < x; i++)
        {
            notEmpty += !(this->isEmpty(Cord(ix + ax*i, iy)));
        }
    }
    else if(y && !x)
    {
        for (i = 1; i < y; i++)
        {
            notEmpty += !(this->isEmpty(Cord(ix, iy + ay*i)));
        }
    }
    else
    {
        for (i = 1; i < x; i++)
        {
            notEmpty += !(this->isEmpty(Cord(ix + ax*i, iy + ay*i)));
        }
    }
    return !notEmpty;
}

// Function to update the board using frontend information
int Board::reciveFronendInfo(std::string inputPipeStr)
{
    std::string dstCordstr = inputPipeStr.substr(2, 3);
    std::string srcCordstr = inputPipeStr.substr(0, 2);

    Cord srcCord = Cord::stringToCord(srcCordstr);
    Cord dstCord = Cord::stringToCord(dstCordstr);
    return (*this->_pieces[srcCord.getY() * 8 + srcCord.getX()]).move(dstCord);
}

// Function to return the string that needs to be sent to frontend
std::string Board::sendFrontendInfo(int code)
{
    std::string rString = "";
    rString += std::to_string(code);
    rString += '\0';
    return rString;
}

// Function to create the string that initializes the frontend
std::string Board::sendBoardToFrontend()
{
    std::string rString = "";

    for (int i = 0; i < 64; i++)
    {
        rString += this->_pieces[i]->getType();
    }
    rString += std::to_string(this->_startingColor);
    rString += '\0';
    return rString;
}
