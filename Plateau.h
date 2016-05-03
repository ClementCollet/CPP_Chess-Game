#ifndef PLATEAU_H
#define PLATEAU_H

#include <Piece.h>
#include <vector>
#include <string>

/////////////////////////////////////////////////
/// \file Plateau.h
/// \brief Classe Plateau Header
/// \author Cl�ment Collet & Loic Steunou
///
/// Header de la classe Plateau et de ces m�thodes
///
/////////////////////////////////////////////////

using namespace std;
using std::vector;

class Piece;

class Plateau
{
public:

    Plateau();                                               // Constructeur du Plateau qui l'initialise tel qu'il doit l'�tre en debut de partie
    Plateau(int i);                                          // Constructeur d'un Plateau rempli de pi�ce "Vide"
    virtual ~Plateau();                                      // Destructeur de Plateau

    void setPiece(int i, int j,Piece* pion);                 // Place le pointeur pion sur la position (i,j)
    Piece* getPiece(int i, int j);                           // Renvoie le pointeur qui �tait en (i,j)
    void copie(Plateau plat);                                // Copie le Plateau plat dans le Plateau qui appelle cette fonction

    void deplacement (int ia, int ja, int iap, int jap);     // Deplace la pi�ce en (ia,ja) en (iap,jap) et place une pi�ce vide en (ia,ja)

    bool pat(int indiceJoueur);
    bool echec (int indiceJoueur);
    bool tourDeJeu(int indiceJoueur);

    void afficherPieceMorte(int indiceJoueur);
    void affichage();

protected:

private:
    std::vector<Piece*> carte;
    std::vector<Piece*> pieceMorteJ1;
    std::vector<Piece*> pieceMorteJ2;

};

#endif // PLATEAU_H
