#include<iostream>
#include "Color.h"

using namespace std;

//---Player Begins---
class Player
{
private:
    string name;
    Color color;
public:
    Player(){}
    Player(const string &name, Color color)
    {
        this->name = name;
        this->color = color;
    }
    string getName()
    {
        return this->name;
    }
    Color getColor()
    {
        return color;
    }
};
//---Player Ends---
