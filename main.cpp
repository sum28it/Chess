#include<bits/stdc++.h>
#include "Game.cpp"
//#include "Color.cpp"

using namespace std;


int main()
{
    Game obj;

    bool flag=false;
    char ix,fx;
    int iy,fy;
    while(obj.getGameStatus()==Active)
    {
        flag=false;
        while(!flag)
        {

            fflush(stdin);
            cin>>ix>>iy>>fx>>fy;
            flag=obj.submitMove({ix,iy}, {fx,fy});
            cout<<flag<<'\n';
        }
        cout<<"Move Success\n\n";
    }
    return 0;
}
