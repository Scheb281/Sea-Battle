#include <iostream>
#include <ctime>
#include <conio.h>
#include <windows.h>

#include "Easter_Eggs.h"
#include "print.h"
#include "moves.h"
#include "checks.h"

using namespace std;

void Randship(char** ship, int Row, int Col)
{
	char symbol = '0';
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			if (i == 0 || i == 11 || j == 0 || j == 11) { ship[i][j] = '*'; }
			else ship[i][j] = ' ';
		}
	}
	int x, y, j, a, b, c, d, temp = 0, counter = 0;
	for (int i = 0; i < 4; i++)
	{
		switch (i)
		{
		case 0:
		link:
			x = 1 + rand() % 10;
			y = 1 + rand() % 10;
			(x - 3 >= 1) ? a = 1 : a = 0; //  1 - Корабль в верх 
			(y - 3 >= 1) ? b = 1 : b = 0; //  2 - Корабль влево
			(x + 3 <= 10) ? c = 1 : c = 0; // 3 - Корабль вниз
			(y + 3 <= 10) ? d = 1 : d = 0; // 4 - Корабль вправо
			while (temp == 0) {
				j = rand() % 4;
				switch (j)
				{
				case 0:
					if (a == 1) { temp = 1; } break;
				case 1:
					if (b == 1) { temp = 2; } break;
				case 2:
					if (c == 1) { temp = 3; } break;
				case 3:
					if (d == 1) { temp = 4; } break;
				default:
					break;
				}
			}
			switch (temp)
			{
			case 1:  //  1 - Корабль в верх
				if (ship[x - 3][y] == ' ' && ship[x - 2][y] == ' ' && ship[x - 1][y] == ' ')
				{
					j = x - 3;
					for (j; j <= x; j++) { ship[j][y] = symbol; }
					j = x - 4;
					for (j; j <= x + 1; j++) { ship[j][y + 1] = '*'; ship[j][y - 1] = '*'; }
					ship[x - 4][y] = '*'; ship[x + 1][y] = '*';
				}
				temp = 10;
				break;
			case 2:   //  2 - Корабль влево
				if (ship[x][y - 3] == ' ' && ship[x][y - 2] == ' ' && ship[x][y - 1] == ' ')
				{
					j = y - 3;
					for (j; j <= y; j++) { ship[x][j] = symbol; }
					j = y - 4;
					for (j; j <= y + 1; j++) { ship[x + 1][j] = '*'; ship[x - 1][j] = '*'; }
					ship[x][y - 4] = '*'; ship[x][y + 1] = '*';
				}
				temp = 10;
				break;
			case 3:   // 3 - Корабль вниз
				if (ship[x + 3][y] == ' ' && ship[x + 2][y] == ' ' && ship[x + 1][y] == ' ')
				{
					j = x + 3;
					for (j; j >= x; j--) { ship[j][y] = symbol; }
					j = x + 4;
					for (j; j >= x - 1; j--) { ship[j][y + 1] = '*'; ship[j][y - 1] = '*'; }
					ship[x + 4][y] = '*'; ship[x - 1][y] = '*';
				}
				temp = 10;
				break;
			case 4:   // 4 - Корабль вправо
				if (ship[x][y + 3] == ' ' && ship[x][y + 2] == ' ' && ship[x][y + 1] == ' ')
				{
					j = y + 3;
					for (j; j >= y; j--) { ship[x][j] = symbol; }
					j = y + 4;
					for (j; j >= y - 1; j--) { ship[x + 1][j] = '*'; ship[x - 1][j] = '*'; }
					ship[x][y + 4] = '*'; ship[x][y - 1] = '*';
				}
				temp = 10;
				break;
			default:
				break;
			}
			if (temp != 10)goto link;
			break;
		case 1:
			counter = 2;
		link1:
			temp = 0;
			for (int n = 0; n < counter; n++)
			{
			three:
				x = 1 + rand() % 10;
				y = 1 + rand() % 10;
				if (ship[x][y] != ' ')goto three;
				(x - 2 >= 1) ? a = 1 : a = 0; //  1 - Корабль в верх 
				(y - 2 >= 1) ? b = 1 : b = 0; //  2 - Корабль влево
				(x + 2 <= 10) ? c = 1 : c = 0; // 3 - Корабль вниз
				(y + 2 <= 10) ? d = 1 : d = 0; // 4 - Корабль вправо
				if (a == 0 && b == 0 && c == 0 && d == 0) { goto three; }
				while (temp == 0) {
					j = rand() % 4;
					switch (j)
					{
					case 0:
						if (a == 1) { temp = 1; } break;
					case 1:
						if (b == 1) { temp = 2; } break;
					case 2:
						if (c == 1) { temp = 3; } break;
					case 3:
						if (d == 1) { temp = 4; } break;
					default:
						break;
					}
				}
				switch (temp)
				{
				case 1:   //  1 - Корабль в верх
					if (ship[x - 2][y] == ' ' && ship[x - 1][y] == ' ')
					{
						j = x - 2;
						for (j; j <= x; j++) { ship[j][y] = symbol; }
						j = x - 3;
						for (j; j <= x + 1; j++) { ship[j][y + 1] = '*'; ship[j][y - 1] = '*'; }
						ship[x - 3][y] = '*'; ship[x + 1][y] = '*';
						counter--;
					}
					break;
				case 2:  //  2 - Корабль влево
					if (ship[x][y - 2] == ' ' && ship[x][y - 1] == ' ')
					{
						j = y - 2;
						for (j; j <= y; j++) { ship[x][j] = symbol; }
						j = y - 3;
						for (j; j <= y + 1; j++) { ship[x + 1][j] = '*'; ship[x - 1][j] = '*'; }
						ship[x][y - 3] = '*'; ship[x][y + 1] = '*';
						counter--;
					}
					break;
				case 3:   // 3 - Корабль вниз
					if (ship[x + 2][y] == ' ' && ship[x + 1][y] == ' ')
					{
						j = x + 2;
						for (j; j >= x; j--) { ship[j][y] = symbol; }
						j = x + 3;
						for (j; j >= x - 1; j--) { ship[j][y + 1] = '*'; ship[j][y - 1] = '*'; }
						ship[x + 3][y] = '*'; ship[x - 1][y] = '*';
						counter--;
					}
					break;
				case 4:   // 4 - Корабль вправо
					if (ship[x][y + 2] == ' ' && ship[x][y + 1] == ' ')
					{
						j = y + 2;
						for (j; j >= y; j--) { ship[x][j] = symbol; }
						j = y + 3;
						for (j; j >= y - 1; j--) { ship[x + 1][j] = '*'; ship[x - 1][j] = '*'; }
						ship[x][y + 3] = '*'; ship[x][y - 1] = '*';
						counter--;
					}
					break;
				default:
					break;
				}
			}
			if (counter != 0)goto link1;
			break;
		case 2:
			counter = 3;
		link2:
			temp = 0;
			for (int n = 0; n < counter; n++)
			{
			two:
				x = 1 + rand() % 10;
				y = 1 + rand() % 10;
				if (ship[x][y] != ' ')goto two;
				(x - 2 >= 1) ? a = 1 : a = 0; //  1 - Корабль в верх 
				(y - 2 >= 1) ? b = 1 : b = 0; //  2 - Корабль влево
				(x + 2 <= 10) ? c = 1 : c = 0; // 3 - Корабль вниз
				(y + 2 <= 10) ? d = 1 : d = 0; // 4 - Корабль вправо
				if (a == 0 && b == 0 && c == 0 && d == 0) { goto two; }
				while (temp == 0) {
					j = rand() % 4;
					switch (j)
					{
					case 0:
						if (a == 1) { temp = 1; } break;
					case 1:
						if (b == 1) { temp = 2; } break;
					case 2:
						if (c == 1) { temp = 3; } break;
					case 3:
						if (d == 1) { temp = 4; } break;
					default:
						break;
					}
				}
				switch (temp)
				{
				case 1:   //  1 - Корабль в верх
					if (ship[x - 1][y] == ' ')
					{
						j = x - 1;
						for (j; j <= x; j++) { ship[j][y] = symbol; }
						j = x - 2;
						for (j; j <= x + 1; j++) { ship[j][y + 1] = '*'; ship[j][y - 1] = '*'; }
						ship[x - 2][y] = '*'; ship[x + 1][y] = '*';
						counter--;
					}
					break;
				case 2:  //  2 - Корабль влево
					if (ship[x][y - 1] == ' ')
					{
						j = y - 1;
						for (j; j <= y; j++) { ship[x][j] = symbol; }
						j = y - 2;
						for (j; j <= y + 1; j++) { ship[x + 1][j] = '*'; ship[x - 1][j] = '*'; }
						ship[x][y - 2] = '*'; ship[x][y + 1] = '*';
						counter--;
					}
					break;
				case 3:   // 3 - Корабль вниз
					if (ship[x + 1][y] == ' ')
					{
						j = x + 1;
						for (j; j >= x; j--) { ship[j][y] = symbol; }
						j = x + 2;
						for (j; j >= x - 1; j--) { ship[j][y + 1] = '*'; ship[j][y - 1] = '*'; }
						ship[x + 2][y] = '*'; ship[x - 1][y] = '*';
						counter--;
					}
					break;
				case 4:   // 4 - Корабль вправо
					if (ship[x][y + 1] == ' ')
					{
						j = y + 1;
						for (j; j >= y; j--) { ship[x][j] = symbol; }
						j = y + 2;
						for (j; j >= y - 1; j--) { ship[x + 1][j] = '*'; ship[x - 1][j] = '*'; }
						ship[x][y + 2] = '*'; ship[x][y - 1] = '*';
						counter--;
					}
					break;
				default:
					break;
				}
			}
			if (counter != 0)goto link2;
			break;
		case 3:
			for (int n = 0; n < 4; n++)
			{
			one:
				x = 1 + rand() % 10;
				y = 1 + rand() % 10;
				if (ship[x][y] != ' ')goto one;
				ship[x][y] = symbol;
				ship[x][y - 1] = '*'; ship[x][y + 1] = '*';
				ship[x - 1][y - 1] = '*'; ship[x - 1][y + 1] = '*';
				ship[x + 1][y - 1] = '*'; ship[x + 1][y + 1] = '*';
				ship[x - 1][y] = '*'; ship[x + 1][y] = '*';
			}
			break;
		default:
			break;
		}
	}

}