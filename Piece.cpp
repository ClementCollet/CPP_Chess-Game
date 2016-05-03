#include "Piece.h"
#include "Plateau.h"
#include<cmath>
#include <iostream>

////////////////////////////////////////////////////////
/// \file piece.cpp
/// \brief Classe Piece Source
/// \author Clément Collet & Loic Steunou
///
/// Code Source de la classe Piece et de ces méthodes
///
////////////////////////////////////////////////////////

Piece::Piece()
{
    indiceJoueur=0;
    type="Vide";
}

Piece::Piece(string genre,int indice)
{
    indiceJoueur=indice;
    type=genre;
}

Piece::~Piece()
{
    //dtor
}

int Piece::getIndiceJoueur()
{
    return indiceJoueur;
}

string Piece::getType()
{
    return type;
}

void Piece::setType(string mot)
{
    type=mot;
}

bool Piece::deplacementPossible(Plateau plat,int ia,int ja,int iAp,int jAp)
{
    bool a=false;
    if (type=="Pion")
    {
        bool dedans = ((iAp<8)&&(iAp>=0)&&(jAp<8)&&(iAp>=0));
        if (!dedans)
            return false;
        bool ok =((abs(ia-iAp)+abs(ja-jAp))<=2);
        if (!ok)
            return false;
        bool copain=(plat.getPiece(iAp,jAp)->getIndiceJoueur()==indiceJoueur);
        if (copain)
        {
            return false;
        }

        bool deplacement1=false;
        bool deplacement2=false;
        bool deplacement3=false;

        if (indiceJoueur==2)
        {
            deplacement1=((ja==jAp)&&((iAp-ia)==1)); // coup normal
            deplacement2=((ja==jAp)&&((iAp-ia)==2)&&(ia==1)); // coup double du début
            deplacement3=((abs(ja-jAp)==1)&&((iAp-ia)==1) && (plat.getPiece(iAp,jAp)->getIndiceJoueur()==1)); // deplacement diag + pièce mangée
        }
        else
        {
            deplacement1=((ja==jAp)&&((ia-iAp)==1)); // coup normal
            deplacement2=((ja==jAp)&&((ia-iAp)==2)&&(ia==6)); // coup double du début
            deplacement3=((abs(ja-jAp)==1)&&((ia-iAp)==1) && (plat.getPiece(iAp,jAp)->getIndiceJoueur()==2)); // deplacement diag + pièce mangée
        }
        if (deplacement1 || deplacement2 || deplacement3)
        {
            a=true;
        }
        else
        {
            return false;
        }
    }
    else if (type=="Roi")
    {
        bool dedans = ((iAp<8)&&(iAp>=0)&&(jAp<8)&&(iAp>=0));
        if (dedans == false)
        {
            return false;
        }
        bool ok = ((abs(ia-iAp)<=1)&&(abs(ja-jAp)<=1));
        if (ok==false)
            return false;
        bool copain = ((plat.getPiece(iAp,jAp)->getIndiceJoueur()!=0)&&(plat.getPiece(iAp,jAp)->getIndiceJoueur()==indiceJoueur));
        if (copain)
            return false;
        if (plat.getPiece(iAp,jAp)->getIndiceJoueur()==indiceJoueur)
            return false;
        else
        {
            return true;
        }
    }
    else if (type=="Cavalier")
    {
        bool dedans = ((iAp<8)&&(iAp>=0)&&(jAp<8)&&(iAp>=0));
        if (!dedans)
            return false;
        bool copain = (plat.getPiece(iAp,jAp)->getIndiceJoueur()==indiceJoueur);
        if (copain)
            return false;;

        bool ok1 =(abs(ia-iAp)<=2);
        bool ok2 =(abs(ia-iAp)>=1);
        bool ok3 =(abs(ja-jAp)<=2);
        bool ok4 =(abs(ja-jAp)>=1);
        bool ok5 =(abs(ja-jAp)+abs(ia-iAp)==3);

        if (ok5 && ok4 && ok3 && ok2 && ok1)
        {
            a=true;
        }
        else
        {
            return false;
        }
    }
    else if (type=="Fou")
    {
        bool dedans = ((iAp<8)&&(iAp>=0)&&(jAp<8)&&(iAp>=0));
        if (!dedans)
            return false;
        bool copain = (plat.getPiece(iAp,jAp)->getIndiceJoueur()==indiceJoueur);
        if (copain)
            return false;
        bool memediag = (((ia+ja)%2)==((iAp+jAp)%2));
        if (memediag==false)
            return false;
        bool dist=(abs(ia-iAp)==abs(ja-jAp));
        if (dist==false)
            return false;
        bool b=false;
        int dep=abs(jAp-ja);

        if ((ia<iAp)&&(ja<jAp))
            for (int i=1; i<dep; i++)
            {
                b=(b || (plat.getPiece(ia+i,ja+i)->getIndiceJoueur()!=0));
            }
        if ((ia>iAp)&&(ja<jAp))
            for (int i=1; i<dep; i++)
            {
                b=(b || (plat.getPiece(ia-i,ja+i)->getIndiceJoueur()!=0));
            }
        if ((ia<iAp)&&(ja>jAp))
            for (int i=1; i<dep; i++)
            {
                b=(b || (plat.getPiece(ia+i,ja-i)->getIndiceJoueur()!=0));
            }
        if ((ia>iAp)&&(ja>jAp))
            for (int i=1; i<dep; i++)
            {
                b=(b || (plat.getPiece(ia-i,ja-i)->getIndiceJoueur()!=0));
            }
        if (b==true)
            return false;
        a=true;
    }
    else if (type=="Tour")
    {
        bool dedans = ((iAp<8)&&(iAp>=0)&&(jAp<8)&&(iAp>=0));
        if (!dedans)
            return false;
        bool copain = (plat.getPiece(iAp,jAp)->getIndiceJoueur()==indiceJoueur);
        if (copain)
            return false;
        bool memeColonne = (ja==jAp);
        bool memeLigne = (ia==iAp);
        if ((memeLigne==false)&&(memeColonne==false))
            return false;
        bool b=false;
        int dep=abs(jAp-ja);

        if ((ia==iAp)&&(ja<jAp))
            for (int i=1; i<dep; i++)
            {
                b=(b || (plat.getPiece(ia,ja+i)->getIndiceJoueur()!=0));
            }
        if ((ia==iAp)&&(ja>jAp))
            for (int i=1; i<dep; i++)
            {
                b=(b || (plat.getPiece(ia,ja-i)->getIndiceJoueur()!=0));
            }
        if ((ia<iAp)&&(ja==jAp))
            for (int i=1; i<dep; i++)
            {
                b=(b || (plat.getPiece(ia+i,ja)->getIndiceJoueur()!=0));
            }
        if ((ia>iAp)&&(ja==jAp))
            for (int i=1; i<dep; i++)
            {
                b=(b || (plat.getPiece(ia-i,ja)->getIndiceJoueur()!=0));
            }
        if (b==true)
            return false;
        a=true;
    }
    else if (type=="Dame")
    {
        bool dedans = ((iAp<8)&&(iAp>=0)&&(jAp<8)&&(iAp>=0));
        if (!dedans)
            return false;
        bool copain = (plat.getPiece(iAp,jAp)->getIndiceJoueur()==indiceJoueur);
        if (copain)
            return false;
        bool memediag = (((ia+ja)%2)==((iAp+jAp)%2));
        if (memediag==false)
        {
            bool memeColonne = (ja==jAp);
            bool memeLigne = (ia==iAp);
            if ((memeLigne==false)&&(memeColonne==false))
                return false;
            bool b=false;
            int dep=abs(jAp-ja);

            if ((ia==iAp)&&(ja<jAp))
                for (int i=1; i<dep; i++)
                {
                    b=(b || (plat.getPiece(ia,ja+i)->getIndiceJoueur()!=0));
                }
            if ((ia==iAp)&&(ja>jAp))
                for (int i=1; i<dep; i++)
                {
                    b=(b || (plat.getPiece(ia,ja-i)->getIndiceJoueur()!=0));
                }
            if ((ia<iAp)&&(ja==jAp))
                for (int i=1; i<dep; i++)
                {
                    b=(b || (plat.getPiece(ia+i,ja)->getIndiceJoueur()!=0));
                }
            if ((ia>iAp)&&(ja==jAp))
                for (int i=1; i<dep; i++)
                {
                    b=(b || (plat.getPiece(ia-i,ja)->getIndiceJoueur()!=0));
                }
            if (b==true)
                return false;
            a=true;
        }
        else
        {
            bool dist=(abs(ia-iAp)==abs(ja-jAp));
            if (dist==false)
                return false;
            bool b=false;
            int dep=abs(jAp-ja);

            if ((ia<iAp)&&(ja<jAp))
                for (int i=1; i<dep; i++)
                {
                    b=(b || (plat.getPiece(ia+i,ja+i)->getIndiceJoueur()!=0));
                }
            if ((ia>iAp)&&(ja<jAp))
                for (int i=1; i<dep; i++)
                {
                    b=(b || (plat.getPiece(ia-i,ja+i)->getIndiceJoueur()!=0));
                }
            if ((ia<iAp)&&(ja>jAp))
                for (int i=1; i<dep; i++)
                {
                    b=(b || (plat.getPiece(ia+i,ja-i)->getIndiceJoueur()!=0));
                }
            if ((ia>iAp)&&(ja>jAp))
                for (int i=1; i<dep; i++)
                {
                    b=(b || (plat.getPiece(ia-i,ja-i)->getIndiceJoueur()!=0));
                }
            if (b==true)
                return false;
            a=true;
        }

    }
    return a;
}
