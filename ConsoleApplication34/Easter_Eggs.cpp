#include <iostream>
#include <windows.h>
#include <ctime>
#include <conio.h>

#include "print.h"
#include "Randship.h"
#include "moves.h"
#include "checks.h"

using namespace std;

int Easter_Egg(char** ship, int Row, int Col, char var, int& egg)
{
	if (ship[1][1] != var && ship[10][1] != var && ship[10][10] != var && ship[1][10] != var && egg == 1)
	{
		system("cls");
		cout << "\n\n\t\t\t\tHELLO WORLD" << endl;
		egg = 0;
		while (true)
		{
			if (_kbhit())
			{
				return 0;
			}
		}
	}
}

int Easter_Egg_2(char** ship, char** ship2, int Row, int Col, int& egg, char purpose)
{
	int counter = 0;
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			if (ship[i][j] == purpose && ship2[i][j] == purpose && egg == 1)
			{
				counter++;
			}
		}
	}
	if (counter == 20)
	{
		system("cls");
		cout << "\t\t\t\tПасхалка 2" << endl;
		egg = 0;
		while (true)
		{
			if (_kbhit())
			{
				return 0;
			}
		}
	}
}