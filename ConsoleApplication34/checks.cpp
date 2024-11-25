#include <iostream>
#include <ctime>
#include <conio.h>
#include <windows.h>

#include "Easter_Eggs.h"
#include "print.h"
#include "Randship.h"
#include "moves.h"

using namespace std;

void check_two(char** ship, int x, int y, int& aUp, int& aLeft, int& aDown, int& aRigth, int a, int b)
{
	char var = '.';
	switch (a)
	{
	case 1:

		(x - b >= 1) ? aUp = x - b : aUp = x;
		(y - b >= 1) ? aLeft = y - b : aLeft = y;
		(x + b <= 10) ? aDown = x + b : aDown = x;
		if (aUp != x && ship[aUp][y] != '7' && ship[aUp][y] != '*') {
			for (int i = aUp; i <= x; i++) { ship[i][y] = var; }
		}
		if (aDown != x && ship[aDown][y] != '7' && ship[aDown][y] != '*') {
			for (int i = aDown; i >= x; i--) { ship[i][y] = var; }
		}
		if (aLeft != y && ship[x][aLeft] != '7' && ship[x][aLeft] != '*') {
			for (int i = aLeft; i <= y; i++) { ship[x][i] = var; }
		}
		break;
	case 2:
		(x - b >= 1) ? aUp = x - b : aUp = x;
		(y - b >= 1) ? aLeft = y - b : aLeft = y;
		(y + b <= 10) ? aRigth = y + b : aRigth = y;
		if (aUp != x && ship[aUp][y] != '7' && ship[aUp][y] != '*') {
			for (int i = aUp; i <= x; i++) { ship[i][y] = var; }
		}
		if (aLeft != y && ship[x][aLeft] != '7' && ship[x][aLeft] != '*') {
			for (int i = aLeft; i <= y; i++) { ship[x][i] = var; }
		}
		if (aRigth != y && ship[x][aRigth] != '7' && ship[x][aRigth] != '*') {
			for (int i = aRigth; i >= y; i--) { ship[x][i] = var; }
		}
		break;
	case 3:
		(x - b >= 1) ? aUp = x - b : aUp = x;
		(y + b <= 10) ? aRigth = y + b : aRigth = y;
		(x + b <= 10) ? aDown = x + b : aDown = x;
		if (aUp != x && ship[aUp][y] != '7' && ship[aUp][y] != '*') {
			for (int i = aUp; i <= x; i++) { ship[i][y] = var; }
		}
		if (aRigth != y && ship[x][aRigth] != '7' && ship[x][aRigth] != '*') {
			for (int i = aRigth; i >= y; i--) { ship[x][i] = var; }
		}
		if (aDown != x && ship[aDown][y] != '7' && ship[aDown][y] != '*') {
			for (int i = aDown; i >= x; i--) { ship[i][y] = var; }
		}
		break;
	case 4:
		(y + b <= 10) ? aRigth = y + b : aRigth = y;
		(x + b <= 10) ? aDown = x + b : aDown = x;
		(y - b >= 1) ? aLeft = y - b : aLeft = y;
		if (aRigth != y && ship[x][aRigth] != '7' && ship[x][aRigth] != '*') {
			for (int i = aRigth; i >= y; i--) { ship[x][i] = var; }
		}
		if (aDown != x && ship[aDown][y] != '7' && ship[aDown][y] != '*') {
			for (int i = aDown; i >= x; i--) { ship[i][y] = var; }
		}
		if (aLeft != y && ship[x][aLeft] != '7' && ship[x][aLeft] != '*') {
			for (int i = aLeft; i <= y; i++) { ship[x][i] = var; }
		}
	default:
		break;
	}
}
void check_search(char** ship, int Row, int Col)
{
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			if (ship[i][j] == '0') { ship[i][j] = '7'; }
		}
	}
}
int check(char** ship, char** ship1, int Row, int Col, int x, int y, char kil, char purpose, int& score, int& cs, int& mr)
{
	int i = 0, t = 0, w = 0;
	while (ship[x - i][y] == kil || ship[x - i][y] == purpose) {
		if (ship[x - i][y] == purpose) return 0;
		t = x - i;
		i++;
	}
	int j = 0;
	while (ship[x + j][y] == kil || ship[x + j][y] == purpose) {
		if (ship[x + j][y] == purpose) return 0;
		j++;

	}
	i = i + j - 1;

	int g = 0;
	while (ship[x][y - g] == kil || ship[x][y - g] == purpose) {
		if (ship[x][y - g] == purpose) return 0;
		w = y - g;
		g++;

	}
	int k = 0;
	while (ship[x][y + k] == kil || ship[x][y + k] == purpose) {
		if (ship[x][y + k] == purpose) return 0;
		k++;
	}
	g = g + k - 1;

	if (g == 1 && i == 1) {
		score = 0, cs = 0, mr = 0;
		ship1[x - 1][y - 1] = '*'; ship1[x - 1][y] = '*'; ship1[x - 1][y + 1] = '*';
		ship1[x][y - 1] = '*'; ship1[x][y + 1] = '*';
		ship1[x + 1][y - 1] = '*'; ship1[x + 1][y] = '*'; ship1[x + 1][y + 1] = '*';
		return 1;
	}
	else if (i > 1)
	{
		score = 0, cs = 0, mr = 0;
		ship1[t - 1][y] = '*';
		t = t - 1;
		for (int a = 0; a <= i + 1; a++)
		{
			ship1[t][y - 1] = '*'; ship1[t][y + 1] = '*';
			t++;
		}
		ship1[t - 1][y] = '*';
		return 1;
	}
	else if (g > 1)
	{
		score = 0, cs = 0, mr = 0;
		ship1[x][w - 1] = '*';
		w = w - 1;
		for (int a = 0; a <= g + 1; a++)
		{
			ship1[x - 1][w] = '*'; ship1[x + 1][w] = '*';
			w++;
		}
		ship1[x][w - 1] = '*';
		return 1;
	}
}
int check_lives(char** ship, char** ship1, int Row, int Col, int x, int y, char kil, char purpose, int countlives)
{
	int i = 0, t = 0, w = 0;
	while (ship[x - i][y] == kil || ship[x - i][y] == purpose) {
		if (ship[x - i][y] == purpose) return 0;
		t = x - i;
		i++;
	}
	int j = 0;
	while (ship[x + j][y] == kil || ship[x + j][y] == purpose) {
		if (ship[x + j][y] == purpose) return 0;
		j++;

	}
	i = i + j - 1;

	int g = 0;
	while (ship[x][y - g] == kil || ship[x][y - g] == purpose) {
		if (ship[x][y - g] == purpose) return 0;
		w = y - g;
		g++;

	}
	int k = 0;
	while (ship[x][y + k] == kil || ship[x][y + k] == purpose) {
		if (ship[x][y + k] == purpose) return 0;
		k++;
	}
	g = g + k - 1;

	if (g == 1 && i == 1) { //вокруг 1-палубного корабля
		ship1[x - 1][y - 1] = '*'; ship1[x - 1][y] = '*'; ship1[x - 1][y + 1] = '*';
		ship1[x][y - 1] = '*'; ship1[x][y + 1] = '*';
		ship1[x + 1][y - 1] = '*'; ship1[x + 1][y] = '*'; ship1[x + 1][y + 1] = '*';
		countlives++;
		return countlives;
	}
	else if (i > 1) //по горинзотали
	{
		ship1[t - 1][y] = '*';
		t = t - 1;
		for (int a = 0; a <= i + 1; a++)
		{
			ship1[t][y - 1] = '*'; ship1[t][y + 1] = '*';
			t++;
			countlives++;
		}
		ship1[t - 1][y] = '*';
		return countlives - 2;
	}
	else if (g > 1) //по вертикали
	{
		ship1[x][w - 1] = '*';
		w = w - 1;
		for (int a = 0; a <= g + 1; a++)
		{
			ship1[x - 1][w] = '*'; ship1[x + 1][w] = '*';
			w++;
			countlives++;
		}
		ship1[x][w - 1] = '*';
		return countlives - 2;
	}
}
void check_star(char** ship, int x, int y, char purpose)
{
	int i = 0, t = 0, w = 0;
	while (ship[x - i][y] == purpose) {
		t = x - i;
		i++;
	}
	int j = 0;
	while (ship[x + j][y] == purpose) {
		j++;
	}
	i = i + j - 1;

	int g = 0;
	while (ship[x][y - g] == purpose) {
		w = y - g;
		g++;
	}
	int k = 0;
	while (ship[x][y + k] == purpose) {
		k++;
	}
	g = g + k - 1;

	if (g == 1 && i == 1) {
		ship[x - 1][y - 1] = '*'; ship[x - 1][y] = '*'; ship[x - 1][y + 1] = '*';
		ship[x][y - 1] = '*'; ship[x][y + 1] = '*';
		ship[x + 1][y - 1] = '*'; ship[x + 1][y] = '*'; ship[x + 1][y + 1] = '*';
	}
	else if (i > 1)
	{
		ship[t - 1][y] = '*';
		t = t - 1;
		for (int a = 0; a <= i + 1; a++)
		{
			ship[t][y - 1] = '*'; ship[t][y + 1] = '*';
			t++;
		}
		ship[t - 1][y] = '*';
	}
	else if (g > 1)
	{
		ship[x][w - 1] = '*';
		w = w - 1;
		for (int a = 0; a <= g + 1; a++)
		{
			ship[x - 1][w] = '*'; ship[x + 1][w] = '*';
			w++;
		}
		ship[x][w - 1] = '*';
	}
}
int check_bag(char** ship, int x, int y, char purpose)
{
	int i = 0;
	while (ship[x - i][y] == purpose) {
		i++;
	}
	int j = 0;
	while (ship[x + j][y] == purpose) {
		j++;
	}
	i = i + j - 1;

	int g = 0;
	while (ship[x][y - g] == purpose) {
		g++;
	}
	int k = 0;
	while (ship[x][y + k] == purpose) {
		k++;
	}
	g = g + k - 1;

	return i + g - 1;

}
void print_map(char** ship, int Row, int Col, int Player)
{
	cout << "Ставит корабли  Игрок №" << Player << endl;
	cout << "   1 2 3 4 5 6 7 8 9 10\n";
	cout << "   _ _ _ _ _ _ _ _ _ _\n";
	for (int i = 1; i < 11; i++)
	{
		cout << (char)('@' + i) << "| ";
		for (int j = 1; j < 11; j++)
		{
			cout << ship[i][j] << " ";
		}
		cout << "|";
		cout << endl;
	}
	cout << "   - - - - - - - - - -\n";
	cout << "\nНажимайте WASD для перемещения корабля\nНажмите Enter  чтобы поставить корабль или отменить постановку\nНажмите E чтобы вращать корабль\nДля потверждения расстановки корабля нажмите Q\n";
}