#include <iostream>
#include <ctime>
#include <conio.h>
#include <windows.h>

#include "Easter_Eggs.h"
#include "print.h"
#include "Randship.h"
#include "moves.h"
#include "checks.h"

using namespace std;

int arrangement(char** ship, int Row, int Col, int Player)
{
	char var = '.', symbol = '+', purpose = '0', star = '*';
	int aUp, aLeft, aRigth, aDown, step = 1, c_bag = 0;
	int reading;

	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			if (i == 0 || i == 11 || j == 0 || j == 11) { ship[i][j] = '*'; }
			else ship[i][j] = var;
		}
	}

	int x = 11, y = 10, boat = 4, counter = 0;
	int x1 = 0, y1 = 0;
	x = 11; y = 10; ship[x][y] = symbol;
	system("cls");
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
	cout << "   - - - - - - - - - +\n";
	cout << "\nНажимайте WASD для перемещения корабля\nНажмите Enter  чтобы поставить корабль или отменить постановку\nНажмите E чтобы вращать корабль\nДля потверждения расстановки корабля нажмите Q\n";
	while (boat != 0) {

		if (_kbhit())
		{
			reading = _getch();
			switch (reading)
			{
			case 230:
			case 119:  // В верх
				up(ship, Row, Col, x, y, symbol, var);
				system("cls");
				print_map(ship, Row, Col, Player);
				break;

			case 228:
			case 97:  // Влево
				left(ship, Row, Col, x, y, symbol, var);
				system("cls");
				print_map(ship, Row, Col, Player);
				break;

			case 162:
			case 100: //  Вправо
				right(ship, Row, Col, x, y, symbol, var);
				system("cls");
				print_map(ship, Row, Col, Player);
				break;

			case 235:
			case 115: // Вниз
				down(ship, Row, Col, x, y, symbol, var);
				system("cls");
				print_map(ship, Row, Col, Player);
				break;


			case 13:
				switch (boat)
				{
				case 4:
					step = 1;
					(x - 3 >= 1) ? aUp = x - 3 : aUp = x; //  1 - Корабль в верх 
					(y - 3 >= 1) ? aLeft = y - 3 : aLeft = y; //  2 - Корабль влево
					(x + 3 <= 10) ? aDown = x + 3 : aDown = x; // 3 - Корабль вниз
					(y + 3 <= 10) ? aRigth = y + 3 : aRigth = y; // 4 - Корабль вправо
					if (aUp != x) { for (int i = aUp; i <= x; i++) { ship[i][y] = purpose; }var = purpose; }
					system("cls");
					print_map(ship, Row, Col, Player);
					while (reading != '1') {
						if (_kbhit())
						{
							reading = _getch();
							switch (reading)
							{
							case 227:
							case 101:
								switch (step)
								{
								case 1:
									if (aRigth != y) {
										check_two(ship, x, y, aUp, aLeft, aDown, aRigth, 1, 3);
										for (int i = aRigth; i >= y; i--) { ship[x][i] = purpose; } var = purpose;
										system("cls");
										print_map(ship, Row, Col, Player);
									}
									else { goto movd; }
									step = 2;
									break;
								case 2:
								movd:
									if (aDown != x) {
										check_two(ship, x, y, aUp, aLeft, aDown, aRigth, 2, 3);
										for (int i = aDown; i >= x; i--) { ship[i][y] = purpose; }
										var = purpose;
										system("cls");
										print_map(ship, Row, Col, Player);
									}
									else { goto movl; }
									step = 3;
									break;
								case 3:
								movl:
									if (aLeft != y) {
										check_two(ship, x, y, aUp, aLeft, aDown, aRigth, 3, 3);
										for (int i = aLeft; i <= y; i++) { ship[x][i] = purpose; } var = purpose;
										system("cls");
										print_map(ship, Row, Col, Player);
									}
									else { goto movup; }
									step = 4;
									break;
								case 4:
								movup:
									if (aUp != x) {
										check_two(ship, x, y, aUp, aLeft, aDown, aRigth, 4, 3);
										for (int i = aUp; i <= x; i++) { ship[i][y] = purpose; }
										var = purpose;
										system("cls");
										print_map(ship, Row, Col, Player);
									}
									else if (aUp == x && aLeft == y && aDown == x && aRigth == y) { step = 5; }
									step = 1;
									break;
								default:
									break;
								}
								break;
							case 169:
							case 113:
								c_bag = check_bag(ship, x, y, purpose);
								if (c_bag == 4) {
									check_star(ship, x, y, purpose);
									system("cls");
									print_map(ship, Row, Col, Player);
									boat--;
									check_search(ship, Row, Col);
									var = '7';
									reading = '1';
								}
								break;


							case 13:
								var = '.';
								check_two(ship, x, y, aUp, aLeft, aDown, aRigth, 1, 3);
								check_two(ship, x, y, aUp, aLeft, aDown, aRigth, 4, 3);
								ship[x][y] = symbol;
								system("cls");
								print_map(ship, Row, Col, Player);
								reading = '1';
								break;
							case 8:
								return 1;
								break;
							default:
								break;
							}
						}
					}
					counter = 2;
					break;
				case 3:
					step = 1;
					if (var == '*' || var == '7') { break; }
					(x - 2 >= 1) ? aUp = x - 2 : aUp = x; //  1 - Корабль в верх 
					(y - 2 >= 1) ? aLeft = y - 2 : aLeft = y; //  2 - Корабль влево
					(x + 2 <= 10) ? aDown = x + 2 : aDown = x; // 3 - Корабль вниз
					(y + 2 <= 10) ? aRigth = y + 2 : aRigth = y; // 4 - Корабль вправо
					if (aUp != x) {
						if (ship[x - 2][y] == '.' && ship[x - 1][y] == '.' && var == '.')
						{
							for (int i = aUp; i <= x; i++)
							{
								ship[i][y] = purpose;
							}
							var = purpose;
						}
					}
					system("cls");
					print_map(ship, Row, Col, Player);
					while (reading != '1') {
						if (_kbhit())
						{
							reading = _getch();
							switch (reading)
							{
							case 8:
								return 1;
								break;
							case 227:
							case 101:
								switch (step)
								{
								case 1:
									if (aRigth != y) {
										if (ship[x][aRigth - 1] == '.' && ship[x][aRigth] == '.') {
											check_two(ship, x, y, aUp, aLeft, aDown, aRigth, 1, 2);
											for (int i = aRigth; i >= y; i--) { ship[x][i] = purpose; } var = purpose;
											system("cls");
											print_map(ship, Row, Col, Player);
										}
									}
									else { goto movD; }
									step = 2;
									break;
								case 2:
								movD:
									if (aDown != x) {
										if (ship[aDown - 1][y] == '.' && ship[aDown][y] == '.') {
											check_two(ship, x, y, aUp, aLeft, aDown, aRigth, 2, 2);
											for (int i = aDown; i >= x; i--) { ship[i][y] = purpose; }
											var = purpose;
											system("cls");
											print_map(ship, Row, Col, Player);
										}
									}
									else { goto movL; }
									step = 3;
									break;
								case 3:
								movL:
									if (aLeft != y) {

										if (ship[x][aLeft + 1] == '.' && ship[x][aLeft] == '.') {
											check_two(ship, x, y, aUp, aLeft, aDown, aRigth, 3, 2);
											for (int i = aLeft; i <= y; i++) { ship[x][i] = purpose; } var = purpose;
											system("cls");
											print_map(ship, Row, Col, Player);
										}
									}
									else { goto movUP; }
									step = 4;
									break;
								case 4:
								movUP:
									if (aUp != x) {
										if (ship[aUp + 1][y] == '.' && ship[aUp][y] == '.') {
											check_two(ship, x, y, aUp, aLeft, aDown, aRigth, 4, 2);
											for (int i = aUp; i <= x; i++) { ship[i][y] = purpose; }
											var = purpose;
											system("cls");
											print_map(ship, Row, Col, Player);
										}
									}
									else if (aUp == x && aLeft == y && aDown == x && aRigth == y) { step = 5; }
									step = 1;
									break;
								default:
									break;
								}
								break;
							case 169:
							case 113:
								c_bag = check_bag(ship, x, y, purpose);
								if (c_bag == 3) {
									check_star(ship, x, y, purpose);
									check_search(ship, Row, Col);
									var = '7';
									system("cls");
									print_map(ship, Row, Col, Player);
									counter--;
									if (counter == 0) { boat--; counter = 3; }
									reading = '1';
								}
								break;


							case 13:
								var = '.';
								check_two(ship, x, y, aUp, aLeft, aDown, aRigth, 1, 2);
								check_two(ship, x, y, aUp, aLeft, aDown, aRigth, 4, 2);
								ship[x][y] = symbol;
								system("cls");
								print_map(ship, Row, Col, Player);
								reading = '1';
								break;
							default:
								break;
							}
						}
					}
					break;
				case 2:
					step = 1;
					if (var == '*' || var == '7') { break; }
					(x - 1 >= 1) ? aUp = x - 1 : aUp = x; //  1 - Корабль в верх 
					(y - 1 >= 1) ? aLeft = y - 1 : aLeft = y; //  2 - Корабль влево
					(x + 1 <= 10) ? aDown = x + 1 : aDown = x; // 3 - Корабль вниз
					(y + 1 <= 10) ? aRigth = y + 1 : aRigth = y; // 4 - Корабль вправо
					if (aUp != x) {
						if (ship[x - 1][y] == '.' && var == '.')
						{
							for (int i = aUp; i <= x; i++)
							{
								ship[i][y] = purpose;
							}
							var = purpose;
						}
					}
					system("cls");
					print_map(ship, Row, Col, Player);
					while (reading != '1') {
						if (_kbhit())
						{
							reading = _getch();
							switch (reading)
							{
							case 227:
							case 101:
								switch (step)
								{
								case 1:
									if (aRigth != y) {
										if (ship[x][aRigth] == '.') {
											check_two(ship, x, y, aUp, aLeft, aDown, aRigth, 1, 1);
											for (int i = aRigth; i >= y; i--) { ship[x][i] = purpose; } var = purpose;
											system("cls");
											print_map(ship, Row, Col, Player);
										}
									}
									else { goto movD1; }
									step = 2;
									break;
								case 2:
								movD1:
									if (aDown != x) {
										if (ship[aDown][y] == '.') {
											check_two(ship, x, y, aUp, aLeft, aDown, aRigth, 2, 1);
											for (int i = aDown; i >= x; i--) { ship[i][y] = purpose; }
											var = purpose;
											system("cls");
											print_map(ship, Row, Col, Player);
										}
									}
									else { goto movL1; }
									step = 3;
									break;
								case 3:
								movL1:
									if (aLeft != y) {

										if (ship[x][aLeft] == '.') {
											check_two(ship, x, y, aUp, aLeft, aDown, aRigth, 3, 1);
											for (int i = aLeft; i <= y; i++) { ship[x][i] = purpose; } var = purpose;
											system("cls");
											print_map(ship, Row, Col, Player);
										}
									}
									else { goto movUP1; }
									step = 4;
									break;
								case 4:
								movUP1:
									if (aUp != x) {
										if (ship[aUp][y] == '.') {
											check_two(ship, x, y, aUp, aLeft, aDown, aRigth, 4, 1);
											for (int i = aUp; i <= x; i++) { ship[i][y] = purpose; }
											var = purpose;
											system("cls");
											print_map(ship, Row, Col, Player);
										}
									}
									else if (aUp == x && aLeft == y && aDown == x && aRigth == y) { step = 5; }
									step = 1;
									break;
								default:
									break;
								}
								break;
							case 169:
							case 113:
								c_bag = check_bag(ship, x, y, purpose);
								if (c_bag == 2) {
									check_star(ship, x, y, purpose);
									check_search(ship, Row, Col);
									var = '7';
									system("cls");
									print_map(ship, Row, Col, Player);
									counter--;
									if (counter == 0) { boat--; counter = 4; }
									reading = '1';
								}
								break;


							case 13:
								var = '.';
								check_two(ship, x, y, aUp, aLeft, aDown, aRigth, 1, 1);
								check_two(ship, x, y, aUp, aLeft, aDown, aRigth, 4, 1);
								ship[x][y] = symbol;
								system("cls");
								print_map(ship, Row, Col, Player);
								reading = '1';
								break;
							case 8:
								return 1;
								break;
							default:
								break;
							}
						}
					}
					break;
				case 1:
					if (var != '.') { break; }
					ship[x][y] = purpose;
					system("cls");
					print_map(ship, Row, Col, Player);
					while (reading != '1')
					{
						if (_kbhit())
						{
							reading = _getch();
							switch (reading)
							{
							case 8:
								return 1;
								break;
							case 169:
							case 113:
								check_star(ship, x, y, purpose);
								check_search(ship, Row, Col);
								system("cls");
								print_map(ship, Row, Col, Player);
								counter--;
								var = '7';
								if (counter == 0) { boat--; counter = 4; }
								reading = '1';
								break;


							case 13:
								var = '.';
								check_two(ship, x, y, aUp, aLeft, aDown, aRigth, 1, 0);
								check_two(ship, x, y, aUp, aLeft, aDown, aRigth, 4, 0);
								ship[x][y] = symbol;
								system("cls");
								print_map(ship, Row, Col, Player);
								reading = '1';
								break;
							default:
								break;
							}
						}
					}

					break;
				default:
					break;
				}
				break;
			case 8:
				return 1;
				break;
			default:
				break;
			}
		}

	}
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			if (ship[i][j] == '7') { ship[i][j] = purpose; }
			else {
				ship[i][j] = '*';
			}
		}
	}
	return 0;
};