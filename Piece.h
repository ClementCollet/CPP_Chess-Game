#ifndef PIECE_H
#define PIECE_H
#include "Plateau.h"
#include <string>

/////////////////////////////////////////////////
/// \file piece.h
/// \brief Classe Piece Header
/// \author Cl�ment Collet & Loic Steunou
///
/// Header de la classe Piece et de ces m�thodes
///
/////////////////////////////////////////////////

class Plateau;
using std::string;
class Piece
{
public:
    Piece();                            // Initialise une pi�ce "vide" correspondant � une absence de pi�ce sur cette case
    Piece(string genre,int indice);     // Initialise une pi�ce de type "genre" et appartenant au joueur "indice"
    virtual ~Piece();                   // Destructeur de Pi�ce
    virtual bool deplacementPossible(Plateau plat,int ia,int ja,int iAp,int jAp);    // Renvoie vrai si la pi�ce en (ia,ja) peut aller en (iAp,jAp), faux sinon
    int getIndiceJoueur();              // Renvoie l'indice du joueur possedant cette pi�ce
    string getType();                   // Renvoie le type de la pi�ce en question
    void setType(string mot);           // Permet de changer le type d'une pi�ce

private:

    int indiceJoueur;                   // 1 Blanc qui commence et 2 Noir
    string type;                        // D�finit si la pi�ce est une "Tour","Dame","Pion","Roi","Fou","Cavalier" ou "Vide"
};

#endif // PIECE_H
