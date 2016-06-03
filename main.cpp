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
    board->berger();
    bool a=false;
    int i=1;
    //board->berger();
    while (!a)
    {
        cout<<"Au tour du Joueur "<<i<<endl;
        a=board->tourDeJeu(i);
        if (i==1) i=2;
        else if (i==2) i=1;
    }
    return 1;
}
