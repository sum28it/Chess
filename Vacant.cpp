#include<iostream>
#include "Piece.h"


using namespace std;

class Vacant: public Piece
{
public:
    Vacant(){}
    Vacant(int code, Color color): Piece(code, color)
    {
        name="";
    }

    bool movePiece(string from, string to, bool kills=false)
    {
        return true;
    }
};

