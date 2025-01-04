#pragma once

#include "Cord.h"
#include "Board.h"

class Board;

class Piece
{
private:
    Cord _position; // Position of the piece on the board
    char _type; // Type of the piece
    bool _isBlack; // Color of the piece (true if black, false if white)
    Board* _board; // Pointer to the board the piece is on

public:
    // Default constructor
    Piece();
    
    // Constructor initializing the piece with a type
    Piece(const char type) : _type(type)
    {
        this->_board = nullptr;
        this->_isBlack = false;
        this->_position = Cord();
    }
    
    // Constructor initializing the piece with a board
    Piece(Board* board) : _board(board)
    {
        this->_isBlack = false;
        this->_position = Cord();
        this->_type = '#';
    }
    
    // Constructor initializing the piece with a board and type
    Piece(Board* board, const char type) : _board(board), _type(type) 
    {
        this->_isBlack = false;
        this->_position = Cord();
    }
    
    // Constructor initializing the piece with position, color, board, and type
    Piece(const Cord position, const bool isBlack, Board* board, const char type);
    
    // Virtual destructor
    virtual ~Piece() {}

    // Getters
    Cord getCord() const;
    char getType() const;
    bool getIsBlack() const;
    Board* getBoard() const;

    // Method to move the piece to a destination coordinate
    int move(Cord dest);
    
    // Method to check if the piece is pinned to a destination coordinate
    bool isPinned(Cord dest);
    
    // Pure virtual method to check if a move to the destination coordinate is valid
    virtual int isValidMove(Cord dest) = 0;
};