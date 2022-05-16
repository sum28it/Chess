#include<iostream>
#include "Piece.cpp"


using namespace std;

class Rook: public Piece
{
public:
    Rook(int code, Color color): Piece(code, color)
    {
        if(color==White)
            name="W-Rook";
        else
            name="B-Rook";
    }

    bool movePiece(pair<char,int> from, pair<char,int> to, bool kills=false)
    {
        //If the Rook is moving horizontally or vertically
        if(from.first==to.first || from.second==to.second)
            return true;

        else
            return false;
    }
};

