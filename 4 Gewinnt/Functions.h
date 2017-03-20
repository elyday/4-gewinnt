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
	char output;
	cout << "|------------------|" << endl;
	for (int i = 0; i < 8; i++)
	{
		cout << "| ";
		for (int d = 0; d < 8; d++)
		{
			if (fieldArray[i][d] == 1)
				output = 'X';
			else if (fieldArray[i][d] == 2)
				output = 'O';
			else
				output = ' ';
			cout << output << " ";
		}
		cout << " |" << endl;
	}
	cout << "|------------------|" << endl;
}

void Zug(int fieldArray[8][8], int *column, int *field, int *actor) {
	fieldArray[*field][*column - 1] = *actor;
}

int nextFree(int fieldArray[8][8], int *column) {
	for (int i = 7; i > -1; i--) {
		if (fieldArray[i][*column - 1] == 0) {
			return i;
		}
	}
	cout << "Die Spalte ist bereits voll, waehle eine andere!\n";
	return -1;
}

int Eingabe(int actor) {
	int column;
	if (actor == 1) {
		cout << "Spieler 1: Waehle eine Spalte (1-8 | 100 zum aufgeben | 101 zum beenden): ";
		cin >> column;
	}
	else {
		cout << "Spieler 2: Waehle eine Spalte (1-8 | 100 zum aufgeben | 101 zum beenden): ";
		cin >> column;
	}


	if (column >= 0 && column < 9) {
		return column;
	}
	else if (column == 100) {
		cout << "Du hast aufgegeben!" << endl;
		return 101;
	}
	else if (column == 101) {
		cout << "Du hast das Programm beendet!" << endl;
		return 102;
	}
	else {
		cout << "Fehlerhafte Eingabe, wiederhole!" << endl;
		return 100;
	}
}

bool checkWinDir(int fieldArray[8][8], int row, int column, int rowinc, int colinc, int *actor) {
	for (int i = 0; i < 4; i++)
	{
	
		if (row < 0 || row > 7 || column < 0 || column >7 || fieldArray[row][column] != *actor) return false;
		row += rowinc;
		column += colinc;
	}
	return true;
}

bool checkWinPos(int fieldArray[8][8], int row, int column, int *actor) {
	if (checkWinDir(fieldArray, row, column, 1, -1, actor)) return true;
	if (checkWinDir(fieldArray, row, column, 1, 1, actor)) return true;
	if (checkWinDir(fieldArray, row, column, -1, -1, actor)) return true;
	if (checkWinDir(fieldArray, row, column, -1, 1, actor)) return true;
	if (checkWinDir(fieldArray, row, column, 0, 1, actor)) return true;
	if (checkWinDir(fieldArray, row, column, 0, -1, actor)) return true;
	if (checkWinDir(fieldArray, row, column, 1, 0, actor)) return true;
	if (checkWinDir(fieldArray, row, column, -1, 0, actor)) return true;
	return false;
}

void resetGame(int fieldArray[8][8], int *winplayer, int *actor) {
	for (int i = 0; i < 8; i++)
	{
		for (int d = 0; d < 8; d++)
		{
			fieldArray[i][d] = 0;
		}
	}
	*winplayer = 0;
	*actor = 1;
}