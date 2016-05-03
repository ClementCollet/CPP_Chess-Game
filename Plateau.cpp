#include <iostream>
#include <stdlib.h>
#include <string>

#include "Plateau.h"
#include "Piece.h"

////////////////////////////////////////////////////////
/// \file Plateau.cpp
/// \brief Classe Plateau Source
/// \author Clément Collet & Loic Steunou
///
/// Code Source de la classe Plateau et de ces méthodes
///
////////////////////////////////////////////////////////


Plateau::Plateau()
{
    carte.clear();
    pieceMorteJ1.clear();
    pieceMorteJ2.clear();
    for (int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            if (i==0)
            {
                if (j==4)
                {
                    Piece* king=new Piece("Roi",2);
                    carte.push_back(king);
                }
                else if (j==1)
                {
                    Piece* cav=new Piece("Cavalier",2);
                    carte.push_back(cav);
                }
                else if (j==3)
                {
                    Piece* cav=new Piece("Dame",2);
                    carte.push_back(cav);
                }
                else if (j==0)
                {
                    Piece* cav=new Piece("Tour",2);
                    carte.push_back(cav);
                }
                else if (j==7)
                {
                    Piece* cav=new Piece("Tour",2);
                    carte.push_back(cav);
                }
                else if (j==6)
                {
                    Piece* cav=new Piece("Cavalier",2);
                    carte.push_back(cav);
                }
                else if (j==2)
                {
                    Piece* cav=new Piece("Fou",2);
                    carte.push_back(cav);
                }
                else if (j==5)
                {
                    Piece* cav=new Piece("Fou",2);
                    carte.push_back(cav);
                }
                else
                {
                    Piece* vide=new Piece();
                    carte.push_back(vide);
                }

            }
            else if (i==1)
            {
                Piece* temp=new Piece("Pion",2);
                carte.push_back(temp);
            }
            else if (i==7)
            {
                if (j==4)
                {
                    Piece* king=new Piece("Roi",1);
                    carte.push_back(king);
                }
                else if (j==1)
                {
                    Piece* cav=new Piece("Cavalier",1);
                    carte.push_back(cav);
                }
                else if (j==3)
                {
                    Piece* cav=new Piece("Dame",1);
                    carte.push_back(cav);
                }
                else if (j==6)
                {
                    Piece* cav=new Piece("Cavalier",1);
                    carte.push_back(cav);
                }
                else if (j==2)
                {
                    Piece* cav=new Piece("Fou",1);
                    carte.push_back(cav);
                }
                else if (j==5)
                {
                    Piece* cav=new Piece("Fou",1);
                    carte.push_back(cav);
                }
                else if (j==0)
                {
                    Piece* cav=new Piece("Tour",1);
                    carte.push_back(cav);
                }
                else if (j==7)
                {
                    Piece* cav=new Piece("Tour",1);
                    carte.push_back(cav);
                }
                else
                {
                    Piece* vide=new Piece();
                    carte.push_back(vide);
                }
            }
            else if (i==6)
            {
                Piece* temp=new Piece("Pion",1);
                carte.push_back(temp);
            }
            else
            {
                Piece* vide=new Piece();
                carte.push_back(vide);
            }
        }
    }
}

Plateau::Plateau(int j)
{
    for(int i=0; i<64; i++)
    {
        Piece* vide=new Piece();
        carte.push_back(vide);
    }
}

Plateau::~Plateau()
{
    carte.clear();
    pieceMorteJ1.clear();
    pieceMorteJ2.clear();
}

void Plateau::affichage()
{
    cout<<"   ";
    for( int j =0; j<8; j++)
    {
        cout<<j<<"   ";
    }
    cout<<endl;
    for (int i=0; i<8; i++)
    {
        cout<<i<<"  ";
        for( int j =0; j<8; j++)
        {

            string piece=carte.at(i*8+j)->getType();
            char lettre;
            if (piece=="Tour") lettre='T';
            else if (piece=="Dame") lettre='D';
            else if (piece=="Pion") lettre='P';
            else if (piece=="Vide") lettre='X';
            else if (piece=="Roi") lettre='R';
            else if (piece=="Fou") lettre='F';
            else if (piece=="Cavalier") lettre='C';
            cout<<lettre<<" ";

            cout<< "| ";

        }
        cout <<" "<<endl;
    }
}

void Plateau::setPiece(int i, int j, Piece* pion)
{
    Piece* pio;
    pio=getPiece(i,j);
    if (pio->getIndiceJoueur()==1)
        pieceMorteJ1.push_back(pio);
    else if (pio->getIndiceJoueur()==2)
            pieceMorteJ2.push_back(pio);
        else
            delete carte.at(i*8+j);

    carte.at(i*8+j)=pion;
}

Piece* Plateau::getPiece(int i, int j)
{
    return this->carte.at(i*8+j);
}

void Plateau::copie(Plateau plat)
{
    for (int i=0; i<8; i++)
        for( int j=0; j<8; j++)
        {
            Piece* pio = plat.getPiece(i,j);
            setPiece(i,j,pio);
        }
}

void Plateau::deplacement (int ia, int ja, int iap, int jap)
{
    Piece* nouv=new Piece();
    Piece* temp=getPiece(ia,ja);
    setPiece(iap,jap,temp);
    setPiece(ia,ja,nouv);
}

bool Plateau::echec(int indiceJoueur)
{

    bool a=false;
    Piece* pio;
    int cible;
    if (indiceJoueur==1)
    {
        for (int i=0; i<64; i++)
        {
            pio=carte.at(i);
            if (pio->getType()=="Roi")
                if (pio->getIndiceJoueur()==1)
                {
                    cible=i;
                    break;
                }
        }
        for (int i=0; i<64; i++)
        {
            pio=carte.at(i);
            if (pio->getIndiceJoueur()==2)
                if (pio->deplacementPossible(*this,i/8,i%8,cible/8,cible%8))
                    a=true;
        }
    }
    else if (indiceJoueur==2)
    {
        for (int i=0; i<64; i++)
        {
            pio=carte.at(i);
            if (pio->getType()=="Roi")
                if (pio->getIndiceJoueur()==2)
                {
                    cible=i;
                    break;
                }
        }
        for (int i=0; i<64; i++)
        {
            pio=carte.at(i);
            if (pio->getIndiceJoueur()==1)
                if (pio->deplacementPossible(*this,i/8,i%8,cible/8,cible%8))
                    a=true;
        }

    }
    return a;
}

bool Plateau::tourDeJeu(int indiceJoueur)
{
    affichage();
    cout<<endl;
    cout << "Voulez vous abandonner ? 1 oui ou 0 non "<<endl;
    int rep;
    cin>>rep;
    if (rep==1)
        return true;

    bool ok2 =true;
    bool ok = false;
    bool ok3=false;
    int i,j;
    int ia,ja;
    Piece* pio;
    bool pasBon=false;
    while ((ok2==true) || (ok==false)||(ok3==false))
    {
        if (pasBon) cout<<"Votre coup est innacceptable"<<endl;
        cout<<"Quelle est la position de la piece que vous voulez deplacer ?"<<endl;

        cin>>i;
        cin>>j;

        cout<<"Ou voulez vous allez ?"<<endl;

        cin>>ia;
        cin>>ja;

        pio=getPiece(i,j);
        ok3=(pio->getIndiceJoueur()==indiceJoueur);
        cout<<"1 si piece vous appartient, 0 sinon ---->"<<ok3<<endl;
        ok = pio->deplacementPossible(*this,i,j,ia,ja);
        cout<<"1 si deplacement possible, 0 sinon ---->"<<ok<<endl;
        Plateau temp;
        temp.copie(*this);
        temp.deplacement(i,j,ia,ja);
        ok2=temp.echec(indiceJoueur);
        cout<<"1 si auto mise en echec, 0 sinon ----> "<<ok2<<endl;
        if ((ok2==true) || (ok==false)||(ok3==false))
            pasBon=true;
    }
    deplacement(i,j,ia,ja);
    cout<<" " <<endl;
}
