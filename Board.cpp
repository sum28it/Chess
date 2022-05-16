#include<iostream>
//#include "Cell.cpp"
#include "Move.cpp"
//#include "Color.cpp"

using namespace std;

//---Board Begins---
class Board
{


    //Orientation of the Board

    //  1   2   3   4   5   6   7   8
    //H
    //G
    //F
    //E
    //D
    //C
    //B
    //A


    //Checks if the given horizontal move is move
    bool horizontalMove(pair<char,int>from, pair<char,int>to)
    {
        int right = max(from.second,to.second);
        int left = min(from.second,to.second);

        for(int i=left+1;i<right;i++)
        {
            //If the path of transition is obstructed by some piece, return false
            if(board[to.first-'A'][i].getPiece().getCode()!=0)
                return false;
        }


        return true;
    }
    //Checks if the given vertical move is move
    bool verticalMove(pair<char,int>from, pair<char,int>to)
    {
        int top = max(from.first,to.first);
        int bottom = min(from.first,to.first);

        for(int i=bottom+1;i<top;i++)
        {
            //If the path of transition is obstructed by some piece, return false
            if(board[i][to.second].getPiece().getCode()!=0)
                return false;
        }


        return true;
    }
    //Checks if the given diagonal move is move
    bool diagonalMove(pair<char,int>from, pair<char,int>to)
    {
        int x=-1,y=-1;

        if(from.first<to.first)
            x=1;
        if(from.second<to.second)
            y=1;

        char ch=from.first;
        int col=from.second;

        for(;ch<to.first;ch+=x,col+=y)
        {
            if(board[ch-'A'][col].getPiece().getCode()!=0)
                return false;
        }


        return true;
    }
public:
    Cell **board;

    Board()
    {
        board = new Cell* [8];
        for(int i=0;i<8;i++)
            board[i]= new Cell[8];
        resetBoard();
    }

    //Affected by changing the signature of the Cell constructor
    void resetBoard()
    {
        //Place pawns on the board
        Piece p;
        for(int i=0;i<8;i++)
        {
            board[1][i]=Cell({'B',i},White,1 );
            board[6][i]=Cell({'G',i},Black,1 );
        }

        //Place vacant positions on the board
        for(int i=2;i<6;i++)
        {
            for(int j=0;j<8;j++)
                board[i][j]= Cell({'A'+i,j},NoColor,0 );
        }

        //Place Rooks on the board
        board[0][0]=  Cell({'A',0},White,20 );
        board[0][7]=  Cell({'A',7},White,20 );

        board[7][0]=  Cell({'H',0},Black,20 );
        board[7][7]=  Cell({'H',7},Black,20 );

        //Place Knights on the board
        board[0][1]=  Cell({'A',1},White,10 );
        board[0][6]=  Cell({'A',6},White,10 );

        board[7][1]=  Cell({'H',1},Black,10 );
        board[7][6]=  Cell({'H',6},Black,10 );

        //Place Bishops on the board
        board[0][2]=  Cell({'A',2},White,5 );
        board[0][5]=  Cell({'A',5},White,5 );

        board[7][2]=  Cell({'H',2},Black,5 );
        board[7][5]=  Cell({'H',5},Black,5 );

        //Place Queens on the board
        board[0][4]=  Cell({'H',4},White,50 );
        board[7][3]=  Cell({'H',3},Black,50 );

        //Place Kings on the board
        board[0][3]=  Cell({'H',3},White,100 );
        board[7][4]=  Cell({'H',4},Black,100 );
    }


    bool makeMove(pair<char,int>from, pair<char,int>to, bool isKnight=false)
    {
        if(isKnight)
        {
            Piece p = board[from.first-'A'][from.second-1].getPiece();
            board[to.first-'A'][to.second-1].setPiece(p);
            board[from.first-'A'][from.second-1].setPiece(Vacant(0,NoColor));
            showBoard();
            return true;
        }

        bool flag=false;

        if(from.first==to.first)
            flag = horizontalMove(from,to);

        else if(from.second==to.second)
            flag = verticalMove(from,to);

        else
            flag = diagonalMove(from,to);

        if(flag)
        {
            //Get the piece from it's initial cell
            Piece p = board[from.first-'A'][from.second-1].getPiece();

            //Place the piece at it's final cell
            board[to.first-'A'][to.second-1].setPiece(p);

            //Set the piece at initial cell to be Vacant
            board[from.first-'A'][from.second-1].setPiece(Vacant(0,NoColor));
            showBoard();

        }
        return flag;
    }

    void showBoard()
    {
        for(int i=7;i>=0;i--)
        {
            cout<<(char)('A'+i)<<'\t';
            for(int j=0;j<8;j++)
            {
                cout<<board[i][j].getPiece().getName()<<'\t';
            }
            cout<<"\n\n";
        }
    }

    bool isSafe(pair<char,int>pos, Color color )
    {
        Piece p;

        for(int i=0;i<8;i++)
        {
            for(int j=0;j<8;j++)
            {
                p = board[i][j].getPiece();
                if(p.getColor()==color)
                {
                    //If the piece can move to the target cell
                    if(p.movePiece({i+'A',j}, pos, true))
                    {
                        //If the piece is knight, then it can not be obstructed
                        if(p.getCode==10)
                            return false;

                        else if(i==pos.first-'A')
                            if(horizontalMove({i+'A'},pos))
                                return false;

                        else if(j==pos.second)
                            if(verticalMove({i+'A'},pos))
                                return false;
                        else
                            if(diagonalMove({i+'A'},pos,true))
                                return false;

                    }
                }
            }
        }

        return true;
    }


};
//---Board ENDS---
