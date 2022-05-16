#include<iostream>
#include "Vacant.cpp"
#include "King.cpp"
#include "Queen.cpp"
#include "Rook.cpp"
#include "Knight.cpp"
#include "Bishop.cpp"
#include "Pawn.cpp"
//#include "Color.cpp"

using namespace std;

//---Cell BEGINS---
class Cell
{
    Piece piece;
    pair<char,int>position;
    Color color;

public:
    Cell(){}
    //Changed signature of cell constructor

    Cell(pair<char,int>pos, Color color,int code=0)
    {
        this->position = pos;
        this->color = color;

        if(code==0)
            this->piece = Vacant{code,color};
        else if(code==1)
            this->piece = Pawn(code,color);
        else if(code==5)
            this->piece = Bishop(code,color);
        else if(code==10)
            this->piece = Knight(code,color);
        else if(code==20)
            this->piece = Rook(code,color);
        else if(code==50)
            this->piece = Queen(code,color);
        else
            this->piece = King(code,color);
    }

    Piece getPiece()
    {
        return (this->piece);
    }
    Color getColor()
    {
        return color;
    }
    pair<char,int> getPosition()
    {
        return this->position;
    }
    bool setPiece(Piece piece)
    {
        if(piece.getColor()==this->piece.getColor())
            return false;

        this->piece=piece;
        return true;
    }

};
//---Cell ENDS---

