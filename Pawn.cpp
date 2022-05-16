#include<iostream>
#include "Piece.h"

using namespace std;

class Pawn: public Piece
{
public:
    Pawn(){}
    Pawn(int code, Color color): Piece(code, color)
    {
        if(color==White)
            name="W-Pawn";
        else
            name="B-Pawn";
    }

    bool movePiece(pair<char,int> from, pair<char,int> to, bool kills=false)
    {
        //If pawn is killing a piece, it must move one step diagonally forward
        if(kills)
        {
            if(color==White)
                return to.first==from.first+1 && abs(to.second-from.second)==1;

            else
                return to.first==from.first-1 && abs(to.second-from.second)==1;
        }

        //Else the pawn must only move one step forward
        else
        {
            if(color==White)
                return to.first==from.first+1;

            else
                return to.first==from.first-1;
        }
    }
};

