#include<iostream>
#include "Piece.h"

using namespace std;


    Piece:: Piece(){}
    Piece:: Piece(int code, Color color)
    {
        this->code = code;
        this->color = color;
    }
    Color Piece:: getColor()
    {
        return this->color;
    }
    string Piece:: getName()
    {
        return this->name;
    }
    int Piece:: getCode()
    {
        return this->code;
    }
    bool Piece:: movePiece(pair<char,int> , pair<char,int> , bool )
    {
        return true;
    }

