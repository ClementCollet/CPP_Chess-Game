#ifndef PLATEAU_H
#define PLATEAU_H

#include <Piece.h>
#include <vector>
#include <string>

/////////////////////////////////////////////////
/// \file Plateau.h
/// \brief Classe Plateau Header
/// \author Clément Collet & Loic Steunou
///
/// Header de la classe Plateau et de ces méthodes
///
/////////////////////////////////////////////////

using namespace std;
using std::vector;

class Piece;

class Plateau
{
public:
    Plateau();                                               // Constructeur du Plateau qui l'initialise tel qu'il doit l'être en debut de partie
    Plateau(int i);                                          // Constructeur d'un Plateau rempli de pièce "Vide"
    virtual ~Plateau();                                      // Destructeur de Plateau

    void setPiece(int i, int j,Piece* pion);                 // Place le pointeur pion sur la position (i,j)
    Piece* getPiece(int i, int j);                           // Renvoie le pointeur qui était en (i,j)
    void copie(Plateau plat);                                // Copie le Plateau plat dans le Plateau qui appelle cette fonction
    void deplacement (int ia, int ja, int iap, int jap);     // Deplace la pièce en (ia,ja) en (iap,jap) et place une pièce vide en (ia,ja)

    bool pat(int indiceJoueur);                              // Detecte les pat : NON IMPLEMENTE
    bool echec (int indiceJoueur);                           // Detecte si je joueur indiceJoueur est en echec, renvoie 1 si oui 0 sinon
    bool tourDeJeu(int indiceJoueur);                        // Gère un tour de jeu complet pour le joueur indiceJoueur, renvoie vrai si le joueur a abandonnée
    void resurection(int indiceJoueur,int i,int j);          // Gère la gestion de la resurection lorsque un pion accède à la ligne opposé

    void affichePiecesMortes(int indiceJoueur);              // Affiche les pieces mortes du joueur indiceJoueur
    void affichage();                                        // Affiche la carte

private:
    std::vector<Piece*> carte;                               // C'est la carte, composée de pointeurs sur les pièces
    std::vector<Piece*> pieceMorteJ1;                        // Liste des pieces mortes du joueur 1
    std::vector<Piece*> pieceMorteJ2;                        // Liste des pieces mortes du joueur 2
};

#endif // PLATEAU_H
