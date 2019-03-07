#include <iostream>
#include <iomanip>
#include <windows.h>
#include <string>

#include "console(v1.8).h"

using namespace std;

#define _getch()  (char) _getwch()
#define _getche() (char) _getwche()
#pragma warning ( disable : 4326 )


void clrscr(void)
{
	CONSOLE_SCREEN_BUFFER_INFO	csbiInfo;
	HANDLE	hConsoleOut;
	COORD	Home = { 0,0 };
	DWORD	dummy;

	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);

	FillConsoleOutputCharacter(hConsoleOut, ' ', csbiInfo.dwSize.X * csbiInfo.dwSize.Y, Home, &dummy);
	csbiInfo.dwCursorPosition.X = 0;
	csbiInfo.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
}

/**************************************************************************************/

void clreol(void)
{
	CONSOLE_SCREEN_BUFFER_INFO  csbiInfo;
	HANDLE	hConsoleOut;
	COORD	Home, pos;
	DWORD	dummy;
	int columns;

	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);

	columns = csbiInfo.srWindow.Right - csbiInfo.srWindow.Left + 1;

	Home = csbiInfo.dwCursorPosition;
	pos.X = columns - csbiInfo.dwCursorPosition.X;

	FillConsoleOutputCharacter(hConsoleOut, ' ', pos.X, Home, &dummy);
}

/**************************************************************************************/

void clreoscr(void)
{
	CONSOLE_SCREEN_BUFFER_INFO	csbiInfo;
	HANDLE	hConsoleOut;
	COORD	Home;
	DWORD	dummy;

	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);

	Home = csbiInfo.dwCursorPosition;
	FillConsoleOutputCharacter(hConsoleOut, ' ', csbiInfo.dwSize.X * csbiInfo.dwSize.Y, Home, &dummy);
}

/**************************************************************************************/

void gotoxy(int x, int y)
{
	CONSOLE_SCREEN_BUFFER_INFO	csbiInfo;
	HANDLE	hConsoleOut;

	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);

	csbiInfo.dwCursorPosition.X = x;
	csbiInfo.dwCursorPosition.Y = y;
	SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
}

/**************************************************************************************/

int wherex(void)
{
	CONSOLE_SCREEN_BUFFER_INFO  csbiInfo;
	HANDLE	hConsoleOut;
	int X;

	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);

	X = csbiInfo.dwCursorPosition.X;

	//FillConsoleOutputCharacter(hConsoleOut,' ',pos.X,Home,&dummy);

	return X;
}

/**************************************************************************************/

int wherey(void)
{
	CONSOLE_SCREEN_BUFFER_INFO  csbiInfo;
	HANDLE	hConsoleOut;
	int Y;

	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);

	Y = csbiInfo.dwCursorPosition.Y;

	return Y;
}

/**************************************************************************************/

void cvmSetColor(cvmColor c)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void cvmResetColor() { cvmSetColor(BLANC); }


// Le deuxième argument est le temps de défilement des lettres en milliseconde.
// Mettre 0 pour aucun défilement ralenti.

void cvmCenterTxt(string texte, unsigned int Temps, cvmColor couleur)
{
	cvmSetColor(couleur);
	cout << setw ( ( 120 - texte.size() ) / 2 ) << left << "";

	for ( unsigned int i = 0 ; i < texte.size() ; i++ )	//Défiler
	{
		cout << texte[i];
		Sleep(Temps);
	}
}

// Le deuxième argument est le temps de défilement des lettres en milliseconde.

void cvmDefilTxt(string texte, unsigned int Temps, cvmColor couleur)
{
	cvmSetColor(couleur);
	for (unsigned int i(0); i<texte.size(); i++) //Défiler
	{
		cout << texte[i];
		Sleep(Temps);
	}
}