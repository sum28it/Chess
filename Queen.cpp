#include<iostream>
#include "Piece.h"


using namespace std;

class Queen: public Piece
{
public:
    Queen(){}
    Queen(int code, Color color): Piece(code, color)
    {
        if(color==White)
            name="W-Queen";
        else
            name="B-Queen";
    }

    bool movePiece(pair<char,int> from, pair<char,int> to, bool kills=false)
    {

        //If the queen is moving horizontally or vertically
        if(from.first==to.first || from.second==to.second)
            return true;

        //If the queen is moving diagonally
        else if(abs(from.first-to.first) == abs(from.second-to.second))
            return true;

        else
            return false;
    }
};

