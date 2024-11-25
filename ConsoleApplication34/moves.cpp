#include <iostream>
#include <ctime>
#include <conio.h>
#include <windows.h>

#include "Easter_Eggs.h"
#include "print.h"
#include "Randship.h"
#include "checks.h"

using namespace std;

void up(char** ship, int Row, int Col, int& x, int& y, char& symbol, char& var)
{

	if (x != 11 && (x - 1) != 0) {
		ship[x][y] = var;
		var = ship[x - 1][y];
		x -= 1;
		ship[x][y] = symbol;;
	}
	else if ((x - 1) == 0)
	{
		ship[x][y] = var;
		var = ship[10][y];
		x = 10;
		ship[x][y] = symbol;

	}
	else if (x == 11 && y == 10)
	{
		var = ship[x - 1][y];
		x -= 1;
		ship[x][y] = symbol;
		ship[11][10] = ' ';
	}

}
void left(char** ship, int Row, int Col, int& x, int& y, char& symbol, char& var)
{
	if (x != 11 && (y - 1) != 0) {
		ship[x][y] = var;
		var = ship[x][y - 1];
		y -= 1;
		ship[x][y] = symbol;

	}
	else if ((y - 1) == 0)
	{
		ship[x][y] = var;
		var = ship[x][10];
		y = 10;
		ship[x][y] = symbol;
	}
	else if (x == 11 && y == 10)
	{
		var = ship[x - 1][y];
		x -= 1;
		ship[x][y] = symbol;
		ship[11][10] = ' ';
	}

}
void right(char** ship, int Row, int Col, int& x, int& y, char& symbol, char& var)
{
	if (x != 11 && (y + 1) != 11) {
		ship[x][y] = var;
		var = ship[x][y + 1];
		y += 1;
		ship[x][y] = symbol;

	}
	else if ((y + 1) == 11)
	{
		ship[x][y] = var;
		var = ship[x][1];
		y = 1;
		ship[x][y] = symbol;

	}
	else if (x == 11 && y == 10)
	{
		var = ship[x - 1][y];
		x -= 1;
		ship[x][y] = symbol;
		ship[11][10] = ' ';
	}

}
void down(char** ship, int Row, int Col, int& x, int& y, char& symbol, char& var)
{
	if (x != 11 && (x + 1) != 11) {
		ship[x][y] = var;
		var = ship[x + 1][y];
		x += 1;
		ship[x][y] = symbol;

	}
	else if ((x + 1) == 11)
	{
		ship[x][y] = var;
		var = ship[1][y];
		x = 1;
		ship[x][y] = symbol;

	}
	else if (x == 11 && y == 10)
	{
		var = ship[x - 1][y];
		x -= 1;
		ship[x][y] = symbol;
		ship[11][10] = ' ';

	}
}
