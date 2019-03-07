#pragma once

#include <string>

using namespace std;


#define _getch()  (char) _getwch()
#define _getche() (char) _getwche()
#pragma warning ( disable : 4326 )


// POUR LE NETTOYAGE DE LA FENÊTRE CONSOLE

void clrscr();   // efface toute la fenêtre et remet le curseur au début
void clreol();   // efface la ligne courante à partir du curseur sans le déplacer
void clreoscr(); // efface la fenêtre à partir du curseur sans le déplacer

// POUR LE POSITIONNEMENT DU CURSEUR DE LA FENÊTRE CONSOLE

int wherex(); // retourne la colonne courante du curseur
int wherey(); // retourne la ligne courante du curseur

void gotoxy(int x,int y); // place le curseur à la colonne x et à la ligne y  ( l'origine = gotoxy(0,0); )

// POUR LA COLORATION DES CARACTÈRES DE LA FENÊTRE CONSOLE

enum cvmColor // énumération des couleurs possibles
{
	NOIR  = 0x00,
	BLANC = 0x07,
	BLEU  = 0x09,
	VERT  = 0x0a,
	CYAN  = 0x0b,	
	ROUGE = 0x0c,
	ROSE  = 0x0d,
	JAUNE = 0x0e
};

void cvmSetColor(cvmColor c); // change la couleur courante
void cvmResetColor(); // change la couleur courante en BLANC


// POUR AFFICHER DU TEXTE DE LA FENÊTRE CONSOLE

void cvmCenterTxt(string texte, unsigned int Temps = 0, cvmColor couleur = BLANC);
void cvmDefilTxt(string texte, unsigned int Temps = 0, cvmColor couleur = BLANC);