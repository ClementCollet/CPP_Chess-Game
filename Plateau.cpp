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
    Piece* pion=new Piece("Pion",1);
    setPiece(1,0,pion);
    Piece* pion3=new Piece("Pion",1);
    setPiece(1,5,pion3);
    Piece* roi=new Piece("Roi",1);
    setPiece(7,4,roi);
    Piece* roi2=new Piece("Roi",2);
    setPiece(0,4,roi2);
    Piece* tour=new Piece("Tour",1);
    setPiece(3,2,tour);
    Piece* pion2=new Piece("Pion",2);
    setPiece(2,3,pion2);
    Piece* fou=new Piece("Fou",1);
    setPiece(3,5,fou);
    Piece* dame=new Piece("Dame",2);
    setPiece(2,5,dame);
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
    carte.at(i*8+j)=pion;
}

void Plateau::affichePiecesMortes(int indiceJoueur)
{
    if (indiceJoueur==1)
        for(int k=0; k<pieceMorteJ1.size(); k++)
            cout<<"En "<<k<<", il y a un(e) "<<pieceMorteJ1.at(k)->getType()<<endl;
    else if (indiceJoueur==2)
        for(int k=0; k<pieceMorteJ2.size(); k++)
            cout<<"En "<<k<<", il y a un(e) "<<pieceMorteJ2.at(k)->getType()<<endl;
}

void Plateau::resurection(int indiceJoueur,int i,int j)
{
    if (indiceJoueur==1)
    {
        cout<<"Voici la liste de vos pieces mortes"<<endl;
        affichePiecesMortes(1);
        cout<<"Quelle piece voulez vous sauver ?"<<endl;
        int rep;
        cin>>rep;
        setPiece(i,j,pieceMorteJ1.at(rep));
        pieceMorteJ1.erase(pieceMorteJ1.begin()+rep);
    }
    else if (indiceJoueur==2)
    {
        cout<<"Voici la liste de vos pieces mortes"<<endl;
        affichePiecesMortes(2);
        cout<<"Quelle piece voulez vous sauver ?"<<endl;
        int rep;
        cin>>rep;
        setPiece(i,j,pieceMorteJ2.at(i));
        pieceMorteJ2.erase(pieceMorteJ2.begin()+i);
    }
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
    Piece* old=getPiece(iap,jap);
    if (old->getIndiceJoueur()==1)
        pieceMorteJ1.push_back(old);
    else if (old->getIndiceJoueur()==2)
        pieceMorteJ2.push_back(old);
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
                {
                    a=true;
                    cout<<"Le ou la "<<pio->getType()<<" en i="<<i/8<<" j="<<i%8<<" met en echec le roi en i="<<cible/8<<" j="<<cible%8<<endl;
                }
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
                {
                    a=true;
                    cout<<"Le ou la "<<pio->getType()<<" en i="<<i/8<<" j="<<i%8<<" met en echec le roi en i="<<cible/8<<" j="<<cible%8<<endl;
                }
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
    else rep = false;
    bool ok2 =true;
    bool ok = false;
    bool ok3=false;
    int i,j;
    int ia,ja;
    Piece* pio;
    while ((ok2==true) || (ok==false)||(ok3==false))
    {
        cout<<"Quelle est la position de la piece que vous voulez deplacer ?"<<endl;

        cin>>i;
        cin>>j;

        cout<<"Ou voulez vous allez ?"<<endl;

        cin>>ia;
        cin>>ja;

        pio=getPiece(i,j);
        ok3=(pio->getIndiceJoueur()==indiceJoueur);
        ok = pio->deplacementPossible(*this,i,j,ia,ja);
        Plateau temp;
        temp.copie(*this);
        temp.deplacement(i,j,ia,ja);
        ok2=temp.echec(indiceJoueur);
        if (ok3==false)
        {
            cout <<"Vous etes joueur "<<indiceJoueur<<" et vous essayer de deplacer une piece du joueur "<<pio->getIndiceJoueur()<<endl;
        }
        if (ok2==true)
        {
            cout <<"Si vous jouez cela, vous êtes en situation d'echec à la fin de votre tour... "<<endl;
        }
        if (ok==false)
        {
            cout <<"Vous ne pouvez pas amenez cette piece à cette endroit."<<endl;
        }
    }
    deplacement(i,j,ia,ja);
    if ((pio->getType()=="Pion")&&((ia==0)||(ia==7)))
    {
        resurection(indiceJoueur,ia,ja);
    }
    return rep;
}
