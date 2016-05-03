#ifndef PIECE_H
#define PIECE_H
#include "Plateau.h"
#include <string>

/////////////////////////////////////////////////
/// \file piece.h
/// \brief Classe Piece Header
/// \author Clément Collet & Loic Steunou
///
/// Header de la classe Piece et de ces méthodes
///
/////////////////////////////////////////////////

class Plateau;
using std::string;
class Piece
{
public:
    Piece();                            // Initialise une pièce "vide" correspondant à une absence de pièce sur cette case
    Piece(string genre,int indice);     // Initialise une pièce de type "genre" et appartenant au joueur "indice"
    virtual ~Piece();                   // Destructeur de Pièce
    virtual bool deplacementPossible(Plateau plat,int ia,int ja,int iAp,int jAp);    // Renvoie vrai si la pièce en (ia,ja) peut aller en (iAp,jAp), faux sinon
    int getIndiceJoueur();              // Renvoie l'indice du joueur possedant cette pièce
    string getType();                   // Renvoie le type de la pièce en question
    void setType(string mot);           // Permet de changer le type d'une pièce

private:

    int indiceJoueur;                   // 1 Blanc qui commence et 2 Noir
    string type;                        // Définit si la pièce est une "Tour","Dame","Pion","Roi","Fou","Cavalier" ou "Vide"
};

#endif // PIECE_H
