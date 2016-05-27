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
    void berger();

    void setPiece(int i, int j,Piece* pion);                 // Place le pointeur pion sur la position (i,j)
    Piece* getPiece(int i, int j);                           // Renvoie le pointeur qui �tait en (i,j)
    void copie(Plateau plat);                                // Copie le Plateau plat dans le Plateau qui appelle cette fonction
    void deplacement (int ia, int ja, int iap, int jap);     // Deplace la pi�ce en (ia,ja) en (iap,jap) et place une pi�ce vide en (ia,ja)

    bool pat(int indiceJoueur);                              // Detecte les pat : NON IMPLEMENTE
    bool echec (int indiceJoueur);                           // Detecte si je joueur indiceJoueur est en echec, renvoie 1 si oui 0 sinon
    bool echec2(int indiceJoueur);
    bool tourDeJeu(int indiceJoueur);                        // G�re un tour de jeu complet pour le joueur indiceJoueur, renvoie vrai si le joueur a abandonn�e
    void resurection(int indiceJoueur,int i,int j);          // G�re la gestion de la resurection lorsque un pion acc�de � la ligne oppos�
    bool echecMat(int indiceJoueur);
    void aide(int indiceJoueur);

    void affichePiecesMortes(int indiceJoueur);              // Affiche les pieces mortes du joueur indiceJoueur
    void affichage();                                        // Affiche la carte

private:
    std::vector<Piece*> carte;                               // C'est la carte, compos�e de pointeurs sur les pi�ces
    std::vector<Piece*> pieceMorteJ1;                        // Liste des pieces mortes du joueur 1
    std::vector<Piece*> pieceMorteJ2;                        // Liste des pieces mortes du joueur 2
};

#endif // PLATEAU_H
