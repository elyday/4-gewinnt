/*
Author: Lars Riﬂe <l.risse@tevaris.de>
*/
#pragma once
using namespace std;

void startNewGame(int fieldArray[8][8]) {
	for (int i = 0; i < 8; i++)
	{
		for (int d = 0; d < 8; d++)
		{
			fieldArray[i][d] = 0;
		}
	}
}

void Ausgabe(int fieldArray[8][8]) {
	for (int i = 0; i < 8; i++)
	{
		for (int d = 0; d < 8; d++)
		{
			cout << fieldArray[i][d] << " ";
		}
		cout << "\n";
	}
}

void Zug(int fieldArray[8][8], int column, int field, int actor) {
	fieldArray[field][column - 1] = actor;
}

int nextFree(int fieldArray[8][8], int column) {
	for (int i = 7; i > -1; i--) {
		if (fieldArray[i][column - 1] == 0) {
			return i;
		}
	}
	cout << "Die Spalte ist bereits voll, waehle eine andere!\n";
	return -1;
}

int Eingabe(int actor) {
	int column;
	if (actor == 1) {
		cout << "Spieler 1: Waehle eine Spalte (1-8 | 100 zum aufgeben): ";
		cin >> column;
	}
	else {
		cout << "Spieler 2: Waehle eine Spalte (1-8 | 100 zum aufgeben): ";
		cin >> column;
	}


	if (column >= 0 && column < 9) {
		return column;
	}
	else if (column == 100) {
		cout << "Du hast das Programm beendet!" << endl;
		return 101;
	}
	else {
		cout << "Fehlerhafte Eingabe, wiederhole!" << endl;
		return 100;
	}
}

int checkHorizontal(int fieldArray[8][8], int column, int actor) {
	for (int i = 7; i > -1; i--) {
		if ((fieldArray[i][column] == actor && fieldArray[i - 1][column] == actor && fieldArray[i - 2][column] == actor && fieldArray[i - 3][column] == actor) || (fieldArray[i][column] == actor && fieldArray[i + 1][column] == actor && fieldArray[i + 2][column] == actor && fieldArray[i + 3][column] == actor) || (fieldArray[i][column] == actor && fieldArray[i + 1][column] == actor && fieldArray[i - 1][column] == actor && fieldArray[i - 2][column] == actor) || (fieldArray[i][column] == actor && fieldArray[i + 1][column] == actor && fieldArray[i - 1][column] == actor && fieldArray[i + 2][column] == actor)) {
			return 1;
		}
	}
	return 0;
}

int checkPerpendicular(int fieldArray[8][8], int column, int actor) {
	for (int i = 7; i > -1; i--) {
		if ((fieldArray[i][column] == actor && fieldArray[i][column - 1] == actor && fieldArray[i][column - 2] == actor && fieldArray[i][column - 3] == actor) || (fieldArray[i][column] == actor && fieldArray[i][column + 1] == actor && fieldArray[i][column + 2] == actor && fieldArray[i][column + 3] == actor) || (fieldArray[i][column] == actor && fieldArray[i][column + 1] == actor && fieldArray[i][column - 1] == actor && fieldArray[i][column - 2] == actor) || (fieldArray[i][column] == actor && fieldArray[i][column + 1] == actor && fieldArray[i][column - 1] == actor && fieldArray[i][column + 2] == actor)) {
			return 1;
		}
	}
	return 0;
}