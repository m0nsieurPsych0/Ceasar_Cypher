#include <iostream>
#include <iomanip>
#include <conio.h>
#include "console(v1.8).h"

bool AnotherOperation();
void ClearBuffer();



void ClearBuffer()
{
	if (cin.fail()) cin.clear();			
	cin.ignore(cin.rdbuf()->in_avail());	
	while (_kbhit()) _getch();
}

bool AnotherOperation()
{
	char input;

	cout << "\n\n\tDo you want to do an another rotation? 'Y' or 'N' ";
		do 
		{
			ClearBuffer();
			input = _getch();
		} while (input != 'y' && input != 'n');
		
		if (input == 'y')
			return true;
		else
			return false;
}

using namespace std;

void main()
{
	/*Constantes*/
	string AlphabetUP = "ABCDEFGHIJKLMNOPQRSTUVWXYZ", AlphabetLOW = "abcdefghijklmnopqrstuvwxyz", Text, Version = "Ver: 2.0", 
		Title = R"(
		   ___                                   ___                _                 
		  / __\  ___   __ _  ___   __ _  _ __   / __\ _   _  _ __  | |__    ___  _ __ 
		 / /    / _ \ / _` |/ __| / _` || '__| / /   | | | || '_ \ | '_ \  / _ \| '__|
		/ /___ |  __/| (_| |\__ \| (_| || |   / /___ | |_| || |_) || | | ||  __/| |   
		\____/  \___| \__,_||___/ \__,_||_|   \____/  \__, || .__/ |_| |_| \___||_|   
		                                              |___/ |_|                       
	  _____________________________________________________________________________________
)";

	/*Variables*/
	unsigned int Rot, x, y;

	/***************************Début du Programme*************************/
	cvmSetColor(VERT);
	cout << Title << endl;
	cvmSetColor(ROUGE);
	cout << setw(100) << Version << endl << endl;
	cvmResetColor();

	x = wherex();
	y = wherey();
	do
	{
		gotoxy(x, y);
		clreoscr();

		cout << "\tText to encrypt : ";
		getline(cin, Text);

		cout << "\n\tNumber of rotations : ";
		cin >> Rot;

		cout << "\n\tResult	: ";

	
	
		for (int j = 0; j < Text.size(); j++)
		{
			for (int i = 0; i < 26 ; i++)
			{
				
				if (AlphabetLOW[i] == Text[j])
				{
					cout << AlphabetLOW[(i + Rot) % 26];
					break;
				}
				else if (AlphabetUP[i] == Text[j])
				{
					cout << AlphabetUP[(i + Rot) % 26];
					break;
				}
				else if (i == 25)
				{
					cout << Text[j];
				}
			}

		}
		
	} while (AnotherOperation());
	
}//main

