#include "Plateau.h"
#include "Piece.h"
#include <iostream>
#include <stdlib.h>
#include <string>


////////////////////////////////////////////////////////
/// \file Plateau.cpp
/// \brief Classe Plateau Source
/// \author Cl�ment Collet & Loic Steunou
///
/// Code Source de la classe Plateau et de ces m�thodes
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
    Piece* roi=new Piece("Roi",2);
    setPiece(0,0,roi);
    Piece* roi2=new Piece("Roi",1);
    setPiece(3,2,roi2);
    Piece* dame=new Piece("Dame",1);
    setPiece(7,1,dame);
}

void Plateau::berger()
{
    deplacement(6,4,4,4);
    deplacement(1,4,3,4);
    deplacement(7,5,4,2);
    deplacement(0,5,3,2);
    deplacement(7,3,3,7);
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
        cout<<j<<"    ";
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
            else if (piece=="Vide") lettre=' ';
            else if (piece=="Roi") lettre='R';
            else if (piece=="Fou") lettre='F';
            else if (piece=="Cavalier") lettre='C';
            //cout<<"\E[31;1m"<<lettre<<"\E[m";
            //cout<<lettre << coucou clemzy;
            if(carte.at(i*8+j)->getIndiceJoueur()!=0)
                cout<<carte.at(i*8+j)->getIndiceJoueur()<<" ";
            else cout<<"  ";
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

bool Plateau::echec2(int indiceJoueur)
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
                }
        }

    }
    return a;
}

bool Plateau::tourDeJeu(int indiceJoueur)
{
    cout<<endl;
    affichage();
    bool pate=pat(indiceJoueur);
    if (pate)
    {
         return true;
    }
    cout<<endl;
    if (echec(indiceJoueur))    cout<<"Attention, vous etes en situation d'echec !!"<<endl;
    bool sortie=false;
    cout << "Voulez vous jouer votre coup (1), un coup de main sur les coups qui vous sont possibles(2) ou abandonne (3)? "<<endl;
     int rep;
     cin>>rep;
     if (rep==3)
     {
         cout<<"Le joueur "<<indiceJoueur<<" a perdu !"<<endl;
        return true;
    }
    if (rep==2)
    {
        aide(indiceJoueur);
    }
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
        cout<<endl;

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
            cout <<"Si vous jouez cela, vous etes en situation d'echec a la fin de votre tour... "<<endl;
        }
        if (ok==false)
        {
            cout <<"Vous ne pouvez pas amenez cette piece a cette endroit."<<endl;
        }
    }
    deplacement(i,j,ia,ja);
    if ((pio->getType()=="Pion")&&((ia==0)||(ia==7)))
    {
        resurection(indiceJoueur,ia,ja);
    }
    if (indiceJoueur==1)
        return echecMat(2);
    else return echecMat(1);
}

bool Plateau::echecMat(int indiceJoueur)
{
    bool ech=echec2(indiceJoueur);
    int indiceAdversaire;
    if (indiceJoueur==1)
        indiceAdversaire=2;
    else indiceAdversaire=1;
    Piece* pio;
    if (ech)
    {
        for (int k=0; k<64; k++)
        {
            pio=getPiece(k/8,k%8);
            if (pio->getIndiceJoueur()==indiceJoueur)
                for (int i=0; i<64; i++)
                {
                    if (pio->deplacementPossible(*this,k/8,k%8,i/8,i%8))
                    {
                        //cout <<"deplacement possible du "<<pio->getType()<<" en "<<k/8<<" et "<<k%8<<" vers "<<i/8<<" et "<<i%8 <<endl;
                        Plateau temp;
                        temp.copie(*this);
                        temp.deplacement(k/8,k%8,i/8,i%8);
                        ech=ech&&temp.echec2(indiceJoueur);
                        temp.~Plateau();
                    }
                }
        }
    }
    if (ech) cout<<"ECHEC ET MAT ! Le joueur "<<indiceJoueur<<" a perdu !"<<endl;
    return ech;
}

void Plateau::aide(int indiceJoueur)
{
    bool ech;
    int indiceAdversaire;
    if (indiceJoueur==1)
        indiceAdversaire=2;
    else indiceAdversaire=1;
    Piece* pio;
    for (int k=0; k<64; k++)
    {
        pio=getPiece(k/8,k%8);
        if (pio->getIndiceJoueur()==indiceJoueur)
            for (int i=0; i<64; i++)
            {
                if (pio->deplacementPossible(*this,k/8,k%8,i/8,i%8))
                {
                    Plateau temp;
                    temp.copie(*this);
                    temp.deplacement(k/8,k%8,i/8,i%8);
                    ech=temp.echec(indiceJoueur);
                    temp.~Plateau();
                    if (ech==false)
                    {
                        cout <<"deplacement possible du "<<pio->getType()<<" en "<<k/8<<" et "<<k%8<<" vers "<<i/8<<" et "<<i%8 <<endl;
                    }
                }
            }
    }
}

bool Plateau::pat(int indiceJoueur)
{
    bool ech=echec2(indiceJoueur);
    if (ech)
        return false;
    bool sortie=true;
    Piece* pio;
    for (int k=0; k<64; k++)
    {
        pio=getPiece(k/8,k%8);
        if (pio->getIndiceJoueur()==indiceJoueur)
            for (int i=0; i<64; i++)
            {
                if (pio->deplacementPossible(*this,k/8,k%8,i/8,i%8))
                {
                    Plateau temp;
                    temp.copie(*this);
                    temp.deplacement(k/8,k%8,i/8,i%8);
                    ech=temp.echec2(indiceJoueur);
                    temp.~Plateau();
                    if (ech==false)
                    {
                        return false;
                    }
                }
            }
    }
    cout<<"Il y a un situation de pat, match nul !"<<endl;
    return true;
}
