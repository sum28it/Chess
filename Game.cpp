#include<iostream>
#include<vector>
#include "Board.cpp"
#include "Player.cpp"


using namespace std;

enum GameStatus{
    Active,WhiteWon,BlackWon,
};

//---Game Begins---
class Game{
    Board *board;
    Player white, black;
    Color currentPlayer;
    Move currentMove;
    vector<Move>moves;
    GameStatus gameStatus;
    pair<char,int> whiteKingPos, blackKingPos;

    //Prints information about the game
    void gameInfo()
    {
        cout<<"Chess v1.0\n\n";
    }

    void changeTurn()
    {
        this->currentPlayer=(this->currentPlayer==White?Black:White);
    }

    //Checks first condition
    bool isMoveWithinBoard(pair<char,int>from, pair<char,int>to)
    {
        if(from.first<'A' || from.first>'H' || to.first<'A' || to.first>'H')
            return false;

        if(from.second<1 || from.second>8 || to.second<1 || to.second>8)
            return false;

        return true;
    }

    //Checks second condition
    bool isValidPiece(pair<char,int>from, pair<char,int>to)
    {
        //If initial position does not contain a piece owned by current player
        if(this->board->board[from.first-'A'][from.second-1].getPiece().getColor()!=currentPlayer)
            return false;

        //If final position contain a piece owned by current player
        if(this->board->board[to.first-'A'][to.second-1].getPiece().getColor()==currentPlayer)
            return false;

        return true;
    }



public:

    Game()
    {

        this->currentPlayer=White;
        this->board = new Board();
        this->gameStatus = Active;

        whitekingPos = {'A', 3};
        blackKingPos = {'B', 4};

        gameInfo();
        this->board->showBoard();
    }

    bool submitMove(pair<char,int>from, pair<char,int>to)
    {
        if(!isMoveWithinBoard(from,to))
            return false;


        //Check is the initial and final positions contain valid pieces
        if(!isValidPiece(from,to))
            return false;

        Piece initial = this->board->board[from.first-'A'][from.second-1].getPiece();
        Piece killed = this->board->board[to.first-'A'][to.second-1].getPiece();

        currentMove = Move(from,to,initial,killed);

        //IF the move is valid for the piece at initial position
        if(!this->board->board[from.first-'A'][from.second-1].getPiece().movePiece(from,to,killed.getCode()!=0))
            return false;

        //IF the piece can be moved from the initial position to the final position
        if(this->board->makeMove(from,to,initial.getCode()==10))
        {
            changeTurn();

            if(currentPlayer==Black && isSafe(blackKingPos,White))
                return true;
            else if(currentPlayer==White && isSafe(whiteKingPos,Black))
                return true;
            else
                //revert();
        }



        return false;
    }

    GameStatus getGameStatus()
    {
        return this->gameStatus;

    }


};
//---Game Ends---
