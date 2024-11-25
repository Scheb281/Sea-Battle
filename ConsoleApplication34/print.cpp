#include <iostream>
#include <ctime>
#include <conio.h>
#include <windows.h>

#include "Easter_Eggs.h"
#include "Randship.h"
#include "moves.h"
#include "checks.h"

using namespace std;

void print(char** ship2_2, char** ship1_1, int Row, int Col, int a)
{
	cout << "Ходит Игрок №" << a << endl;
	cout << "  Вражеское поле: \t\t\t\t    Свое поле:" << endl;
	cout << "   1 2 3 4 5 6 7 8 9 10\t\t\t\t    1 2 3 4 5 6 7 8 9 10\n";
	cout << "   _ _ _ _ _ _ _ _ _ _\t\t\t\t    _ _ _ _ _ _ _ _ _ _\n";
	for (int i = 1; i < 11; i++)
	{
		cout << (char)('@' + i) << "| ";
		for (int j = 1; j < 11; j++)
		{
			cout << ship2_2[i][j] << " ";
		}
		cout << "|";
		cout << "\t\t\t ";
		cout << (char)('@' + i) << "| ";
		for (int j = 1; j < 11; j++)
		{
			cout << ship1_1[i][j] << " ";
		}
		cout << "|";
		cout << endl;
	}
	cout << "   - - - - - - - - - -\t\t\t\t    - - - - - - - - - -\n";
	cout << "Нажимайте WASD для перемещения\nНажмите Enter для выстрела\nНажмите Backspace для выхода\n";
}
void print_pc(char** ship2_2, char** ship1_1, int Row, int Col, int bang, int t)
{
	system("cls");
	cout << "Ходит Игрок " << endl;
	cout << "  Вражеское поле: \t\t\t\t    Свое поле:" << endl;
	cout << "   1 2 3 4 5 6 7 8 9 10\t\t\t\t    1 2 3 4 5 6 7 8 9 10\n";
	cout << "   _ _ _ _ _ _ _ _ _ _\t\t\t\t    _ _ _ _ _ _ _ _ _ _\n";
	for (int i = 1; i < 11; i++)
	{
		cout << (char)('@' + i) << "| ";
		for (int j = 1; j < 11; j++)
		{
			cout << ship2_2[i][j] << " ";
		}
		cout << "|";
		cout << "\t\t\t ";
		cout << (char)('@' + i) << "| ";
		for (int j = 1; j < 11; j++)
		{
			cout << ship1_1[i][j] << " ";
			if (i == t && j == 10 && bang > 0) {
				cout << " <---- Выстрел";
			}
		}
		cout << "|";
		cout << endl;
	}
	cout << "   - - - - - - - - - -\t\t\t\t    - - - - - - - - - -\n";
	cout << "Нажимайте WASD для перемещения\nНажмите Enter для выстрела\nНажмите Backspace для выхода\n";
}