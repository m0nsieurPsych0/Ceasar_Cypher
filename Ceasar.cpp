#include <iostream>
//#include <conio.h>
#include <iomanip>

#include "console(v1.8).h"



using namespace std;

void main()
{
	/*Constantes*/
	string Alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ", Text, Version = "Ver: 1.3", 
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
	unsigned int Rot;

	/***************************Début du Programme*************************/
	cvmSetColor(VERT);
	cout << Title << endl;
	cvmSetColor(ROUGE);
	cout << setw(100) << Version << endl << endl;
	cvmResetColor();

	cout << "\tText to encrypt : ";
	cin >> Text;

	cout << "\n\tNumber of rotations : ";
	cin >> Rot;

	cout << "\n\tResult	: ";

	for (int j = 0; j < Text.size(); j++)
	{
		for (int i = 0; i < Alphabet.size(); i++)
		{
			
			if(islower(Text[j]))
			{
				Text[j] = toupper(Text[j]);
			}
			if (Alphabet[i] == Text[j])
			{
				cout << Alphabet[(i + Rot) % 26];
			}
			
		}
	}
	
	_getch();
}

