#include<iostream>
#include "Cell.cpp"
//#include "Piece.cpp"
//#include "Color.cpp"

using namespace std;

//---Move Begins---
class Move{

public:
    pair<char,int> from , to;
    Piece piece;
    Piece killed;
    bool hasCheck;
    //bool makeCheck;
    Piece promoted;
    Move(){}
    Move(pair<char,int> from, pair<char,int> to,Piece piece, Piece killed = Vacant(0,White),Piece promoted = Vacant(0,White), bool hasCheck=false)
    {
        this->from = from;
        this->to = to;
        this->piece = piece;
        this->killed = killed;
        this->hasCheck = hasCheck;
        //this->makeCheck = makeCheck;
        this->promoted = promoted;
    }
};
//---Move Ends---
