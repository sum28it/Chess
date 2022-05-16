#include<iostream>
#include "Piece.h"


using namespace std;

class Knight: public Piece
{
public:
    Knight(){}
    Knight(int code, Color color): Piece(code, color)
    {
        if(color==White)
            name="W-Knight";
        else
            name="B-Knight";
    }

    bool movePiece(pair<char,int> from, pair<char,int> to, bool kills=false)
    {
        //Traditional Knight Move

        if(abs(from.first-to.first)==2 && abs(from.second-to.second)==1)
            return true;

        else if(abs(from.second-to.second)==2 && abs(from.first-to.first)==1)
            return true;

        else
            return false;
    }
};

