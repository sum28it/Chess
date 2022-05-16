#include<iostream>
#include "Piece.h"


using namespace std;

class Bishop: public Piece
{
public:
    Bishop(){}
    Bishop(int code, Color color): Piece(code, color)
    {
        if(color==White)
            name="W-Bishop";
        else
            name="B-Bishop";
    }

    bool movePiece(pair<char,int> from, pair<char,int> to, bool kills=false)
    {
        //If the Bishop is moving diagonally
        if(abs(from.first-to.first) == abs(from.second-to.second))
            return true;

        else
            return false;
    }
};


