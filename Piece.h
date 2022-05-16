#ifndef PIECE_H
#define PIECE_H


#include<iostream>
#include "Color.h"

using namespace std;

class Piece
{
protected:

    int code;

    Color color;
    string name;

public:
    Piece();
    Piece(int code, Color color);
    Color getColor();
    string getName();
    int getCode();
    virtual bool movePiece(pair<char,int> , pair<char,int> , bool);
};

#endif // PIECE_H
