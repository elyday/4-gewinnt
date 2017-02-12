/*
Author: Lars Riﬂe <l.risse@tevaris.de>
*/

#include "stdafx.h"
#include <iostream>

// Customs Includes
#include "Functions.h"
using namespace std;
 
int main()
{
	int fieldArray[8][8];
	int winplayer = 0, actor = 1;
	
	startNewGame(fieldArray);
	
	while (winplayer == 0) {
		int column = 100, field = -1;
		Ausgabe(fieldArray);

		while (column == 100 || field == -1) {
			column = Eingabe(actor);
			if (column != 100) {
				field = nextFree(fieldArray, column);
			}
		}

		Zug(fieldArray, column, field, actor);
		int win = checkHorizontal(fieldArray, column - 1, actor);
		if (win == 1) {
			winplayer = actor;
		}
		else {
			int win = checkPerpendicular(fieldArray, column - 1, actor);
			if (win == 1)
				winplayer = actor;
		}

		if (actor == 1)
			actor = 2;
		else if (actor == 2)
			actor = 1;
		else
			actor = 1;

		int m = system("cls");
	}
	
	Ausgabe(fieldArray);
	cout << "Spieler " << winplayer << " hat gewonnen.\n";

	int mm = system("pause");
    return 0;
}