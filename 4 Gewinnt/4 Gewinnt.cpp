/*
Author: Lars Riﬂe <l.risse@tevaris.de>
*/

#include "stdafx.h"
#include <iostream>
using namespace std;

// Customs Includes
#include "Functions.h"
 
int main()
{
	int fieldArray[8][8];
	int winplayer = 0, actor = 1;
	bool boolean = true;
	
	startNewGame(fieldArray);
	
	while (boolean) {
		while (winplayer == 0) {
			int column = 100, field = -1;
			Ausgabe(fieldArray);

			while (column == 100 || field == -1) {
				column = Eingabe(actor);
				if (column == 101) {
					field = 101;
				}
				else if (column == 102) {
					field = 102;
				}
				else if (column != 100) {
					field = nextFree(fieldArray, &column);
				}
			}

			if (field < 8 && field >= 0) {
				Zug(fieldArray, &column, &field, &actor);

				for (int i = 0; i < 8; i++)
				{
					for (int d = 0; d < 8; d++)
					{
						bool win = checkWinPos(fieldArray, i, d, &actor);
						if (win) {
							winplayer = actor;
							break;
						}
					}
				}
			}

			if (actor == 1)
				actor = 2;
			else if (actor == 2)
				actor = 1;
			else
				actor = 1;

			if (field == 101) {
				winplayer = actor;
			}
			else if (field == 102) {
				boolean = false;
				break;
			}

			system("cls");
		}

		if (winplayer == 1 || winplayer == 2) {
			cout << "Spieler " << winplayer << " hat gewonnen.\n";
			resetGame(fieldArray, &winplayer, &actor);
		}
	}

	system("pause");
    return 0;
}