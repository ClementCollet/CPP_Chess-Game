#include <iostream>
#include "Plateau.h"
#include "Piece.h"

/////////////////////////////////////////////////
/// \file main.coo
/// \brief code du main
/// \author Clément Collet & Loic Steunou
///
///  main
///
/////////////////////////////////////////////////


using namespace std;

int main()
{
    Plateau* board=new Plateau();
    bool a=false;
    int i=1;
    while (!a)
    {
        cout<<"Au tour du Joueur "<<i<<endl;
        cout<<endl;
        a=board->tourDeJeu(i);
        if (i==1) i=2;
        else if (i==2) i=1;
    }
    cout<<"Le joueur "<<i<<" a gagne !!";
    return 0;
}
