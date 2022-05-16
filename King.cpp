#include<iostream>
#include "Piece.h"
//#include "Color.h"

using namespace std;

class King: public Piece
{
public:
    King(){}
    King(int code, Color color): Piece(code, color)
    {
        if(color==White)
            name="W-King";
        else
            name="B-King";
    }

    bool movePiece(pair<char,int> from, pair<char,int> to, bool kills=false)
    {
        //A King can only move one step in any of the eight directions

        if(abs(from.first-to.first)>1 || abs(from.second-to.second)>1)
            return false;
        else
            return true;
    }
};
