#include <iostream>
#include <ctime>
#include <conio.h>
#include <windows.h>

#include "Easter_Eggs.h"
#include "print.h"
#include "Randship.h"
#include "moves.h"
#include "checks.h"
#include "arrangement.h"

using namespace std;

int count3_1 = 4;
int count3_2 = 3;
int count3_3 = 2;
int count3_4 = 1;

int Easter_Egg(char** ship, int Row, int Col, char var, int& egg);
int Easter_Egg_2(char** ship, char** ship2, int Row, int Col, int& egg, char purpose);

void PCShoot(char** ship, char purpose, char kil, int Row, int Col, int& counter, int& t, int& h, int& bang, char** ship2_2, int x, int y, int& score, int& p, int& zr, int t1, int h1, int& mr, int& cs) {
	if (ship[t][h] == purpose) {
		bang++;
		ship[t][h] = kil;
		counter++;
		p++;
		if (score < 2) {
			score++;
		}
		int countlives = 0;
		check(ship, ship, Row, Col, t, h, kil, purpose, score, cs, mr);
		int lives = check_lives(ship, ship, Row, Col, t, h, kil, purpose, countlives);
		switch (lives) {
		case 1:
			count3_1--;
			break;
		case 2:
			count3_2--;
			break;
		case 3:
			count3_3--;
			break;
		case 4:
			count3_4--;
		default:
			break;
		}
		system("cls");
		cout << "ходит игрок " << endl;
		cout << "  вражеское поле: \t\t\t\t    свое поле:" << endl;
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
				cout << ship[i][j] << " ";
				if (i == t && j == 10 && bang >= 1) {
					cout << " <---- выстрел";
				}
			}
			cout << "|";
			cout << endl;
		}
		cout << "   - - - - - - - - - " << ship2_2[x][y] << "\t\t\t\t    - - - - - - - - - -\n";
		cout << "нажимайте wasd для перемещения\nнажмите enter для выстрела\nнажмите backspace для выхода\n";
	}
	else if (ship[t][h] == ' ') {
		ship[t][h] = '+';
		if (cs == 2) {
			mr++;
		}
		zr++, p++, bang++, t = t1, h = h1;
	}

}
void Logic_PC2(char** ship, char purpose, char kil, int Row, int Col, int& counter, int& t, int& h, int& bang, char** ship2_2, int x, int y, int& score, int& dir, int& dir2, int& cs, int& mr) {
	srand(time(NULL));
	int t1 = t, h1 = h;
	for (int zr = 0; zr < 1;) {
		int p = 0;
		switch (score) {
		case 0:
			if (ship[t][h] == purpose) {
				bang++;
				ship[t][h] = kil;
				counter++;
				score++;
				if (counter == 20)
				{
					zr++;
				}
				int countlives = 0;
				check(ship, ship, Row, Col, t, h, kil, purpose, score, cs, mr);
				int lives = check_lives(ship, ship, Row, Col, t, h, kil, purpose, countlives);
				switch (lives) {
				case 1:
					count3_1--;
					break;
				case 2:
					count3_2--;
					break;
				case 3:
					count3_3--;
					break;
				case 4:
					count3_4--;
				default:
					break;
				}
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
						cout << ship[i][j] << " ";
						if (i == t && j == 10 && bang == 1) {
							cout << " <---- Выстрел";
						}
					}
					cout << "|";
					cout << endl;
				}
				cout << "   - - - - - - - - - " << ship2_2[x][y] << "\t\t\t\t    - - - - - - - - - -\n";
				cout << "Нажимайте WASD для перемещения\nНажмите Enter для выстрела\nНажмите Backspace для выхода\n";
				Sleep(1000);
			}
			else if (ship[t][h] == ' ') {
				ship[t][h] = '+';
				zr++;
				bang++;
			}
			else {
				t = 1 + rand() % 10;
				h = 1 + rand() % 10;
			}
			break;
		case 1:
			t1 = t, h1 = h;
			if (cs == 0) {
				cs++;
			}
			while (p == 0) {
				int random = rand() % 4;
				if (random == 0 & t - 1 != 0) {
					if (ship[t - 1][h] == purpose || ship[t - 1][h] == ' ') {
						PCShoot(ship, purpose, kil, Row, Col, counter, t -= 1, h, bang, ship2_2, x, y, score, p, zr, t1, h1, cs, mr);
						dir2 = 0;
					}
				}
				else if (random == 1 & t + 1 != 10) {
					if (ship[t + 1][h] == purpose || ship[t + 1][h] == ' ') {
						PCShoot(ship, purpose, kil, Row, Col, counter, t += 1, h, bang, ship2_2, x, y, score, p, zr, t1, h1, cs, mr);
						dir2 = 1;
					}
				}
				else if (random == 2 & h + 1 != 10) {
					if (ship[t][h + 1] == purpose || ship[t][h + 1] == ' ') {
						PCShoot(ship, purpose, kil, Row, Col, counter, t, h += 1, bang, ship2_2, x, y, score, p, zr, t1, h1, cs, mr);
						dir2 = 2;
					}
				}
				else if (random == 3 & h - 1 != 0) {
					if (ship[t][h - 1] == purpose || ship[t][h - 1] == ' ') {
						PCShoot(ship, purpose, kil, Row, Col, counter, t, h -= 1, bang, ship2_2, x, y, score, p, zr, t1, h1, cs, mr);
						dir2 = 3;
					}
				}
			}
			if (ship[t - 1][h] == kil || ship[t + 1][h] == kil) {
				dir = 1;
			}
			else if (ship[t][h - 1] == kil || ship[t][h + 1] == kil) {
				dir = 2;
			}
			break;
		case 2:
			if (cs == 1) {
				cs++;
			}
			switch (dir)
			{
			case 1:
				if (dir2 == 0) {
					if (ship[t - 1][h] == purpose || ship[t - 1][h] == ' ') {
						PCShoot(ship, purpose, kil, Row, Col, counter, t -= 1, h, bang, ship2_2, x, y, score, p, zr, t1, h1, cs, mr);
					}
					else {
						if (mr == 1) {
							t = t1, h = h1;
						}
						PCShoot(ship, purpose, kil, Row, Col, counter, t += 1, h, bang, ship2_2, x, y, score, p, zr, t1, h1, cs, mr);
					}
				}
				else if (dir2 == 1) {
					if (ship[t + 1][h] == purpose || ship[t + 1][h] == ' ') {
						PCShoot(ship, purpose, kil, Row, Col, counter, t += 1, h, bang, ship2_2, x, y, score, p, zr, t1, h1, cs, mr);
					}
					else {
						if (mr == 1) {
							t = t1, h = h1;
						}
						PCShoot(ship, purpose, kil, Row, Col, counter, t -= 1, h, bang, ship2_2, x, y, score, p, zr, t1, h1, cs, mr);
					}
				}
			case 2:
				if (dir2 == 2) {
					if (ship[t][h + 1] == purpose || ship[t][h + 1] == ' ') {
						PCShoot(ship, purpose, kil, Row, Col, counter, t, h += 1, bang, ship2_2, x, y, score, p, zr, t1, h1, cs, mr);
					}
					else {
						if (mr == 1) {
							t = t1, h = h1;
						}
						PCShoot(ship, purpose, kil, Row, Col, counter, t, h -= 1, bang, ship2_2, x, y, score, p, zr, t1, h1, cs, mr);
					}
				}
				else if (dir2 == 3) {
					if (ship[t][h - 1] == purpose || ship[t][h - 1] == ' ') {
						PCShoot(ship, purpose, kil, Row, Col, counter, t, h -= 1, bang, ship2_2, x, y, score, p, zr, t1, h1, cs, mr);
					}
					else {
						if (mr == 1) {
							t = t1, h = h1;
						}
						PCShoot(ship, purpose, kil, Row, Col, counter, t, h += 1, bang, ship2_2, x, y, score, p, zr, t1, h1, cs, mr);
					}
				}
			default:
				break;
			}
		default:
			break;
		}
	}
}
void Logic_PC(char** ship, char purpose, char kil, int Row, int Col, int& counter, int& t, int& h, int& bang, char** ship2_2, int x, int y, int score, int dir, int dir2, int cs, int mr) {
	for (int i = 0; i < 1;) {
		if (ship[t][h] == purpose) {
			bang++;
			ship[t][h] = kil;
			counter++;
			if (counter == 20)
			{
				i++;
			}
			int countlives = 0;
			check(ship, ship, Row, Col, t, h, kil, purpose, score, cs, mr);
			int lives = check_lives(ship, ship, Row, Col, t, h, kil, purpose, countlives);
			switch (lives) {
			case 1:
				count3_1--;
				break;
			case 2:
				count3_2--;
				break;
			case 3:
				count3_3--;
				break;
			case 4:
				count3_4--;
			default:
				break;
			}
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
					cout << ship[i][j] << " ";
					if (i == t && j == 10 && bang == 1) {
						cout << " <---- Выстрел";
					}
				}
				cout << "|";
				cout << endl;
			}
			cout << "   - - - - - - - - - " << ship2_2[x][y] << "\t\t\t\t    - - - - - - - - - -\n";
			cout << "Нажимайте WASD для перемещения\nНажмите Enter для выстрела\nНажмите Backspace для выхода\n";
			Sleep(1000);
		}
		else if (ship[t][h] == ' ') {
			ship[t][h] = '+';
			i++;
			bang++;
		}
		else {
			t = 1 + rand() % 10;
			h = 1 + rand() % 10;
		}
	}
}
int logik_human_vs_human(char** ship3, char** ship1, char** ship2, int Row, int Col, char** ship1_1, char** ship2_2, char& var, char& var1, int OnePlayer, int TwoPlayer, int egg_1, int score, int cs, int mr, int count1, int count2, int count3, int count4, int count1_2, int count2_2, int count3_2, int count4_2)
{
	int egg = 1, egg2 = 1, egg3 = 1;
	int motion = rand() % 2;
	int  x = 11, y = 10,
		x1 = 11, y1 = 10,
		counter = 0, counter1 = 0, live = 0;

	char symbol = '+', purpose = '0', kil = 'X';
	int reading;
	switch (motion)
	{
	case 0:
	link:
		Easter_Egg_2(ship1, ship3, Row, Col, egg3, purpose);
		x = 11; y = 10; ship2_2[x][y] = symbol;
		system("cls");
		cout << "Ходит Игрок №" << OnePlayer << endl;
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
			cout << "\t|";
			if (i == 1) {
				cout << " " << " У вас осталось:";
			}
			if (i == 2) {
				cout << " " << count4_2 << " четырехпалубный";
			}
			if (i == 3) {
				cout << " " << count3_2 << " трехпалубных";
			}
			if (i == 4) {
				cout << " " << count2_2 << " двухпалубных";
			}
			if (i == 5) {
				cout << " " << count1_2 << " однопалубных";
			}
			if (i == 6) {
				cout << " " << " У противника осталось:";
			}
			if (i == 7) {
				cout << " " << count4 << " четырехпалубный";
			}
			if (i == 8) {
				cout << " " << count3 << " трехпалубных";
			}
			if (i == 9) {
				cout << " " << count2 << " двухпалубных";
			}
			if (i == 10) {
				cout << " " << count1 << " однопалубных";
			}
			cout << endl;
		}
		cout << "   - - - - - - - - - " << ship2_2[x][y] << "\t\t\t\t    - - - - - - - - - -\n";
		cout << "Нажимайте WASD для перемещения\nНажмите Enter для выстрела\nНажмите Backspace для выхода\n\n\n";
		if (egg == 0 && egg_1 == 0 && egg3 == 0)
		{
			cout << "Секретная пасхалка" << endl;
			for (int k = 0; k < Row; k++)
			{
				for (int k1 = 0; k1 < Col; k1++)
				{
					cout << ship2[k][k1] << " ";
				}
				cout << endl;
			}
		}


		while (counter < 20)
		{
			if (_kbhit())
			{
				reading = _getch();
				switch (reading)
				{
				case 230:
				case 119:  // В верх
					up(ship2_2, Row, Col, x, y, symbol, var);
					system("cls");
					print(ship2_2, ship1_1, Row, Col, OnePlayer);
					break;

				case 228:
				case 97:  // Влево
					left(ship2_2, Row, Col, x, y, symbol, var);
					system("cls");
					print(ship2_2, ship1_1, Row, Col, OnePlayer);
					break;

				case 162:
				case 100: //  Вправо
					right(ship2_2, Row, Col, x, y, symbol, var);
					system("cls");
					print(ship2_2, ship1_1, Row, Col, OnePlayer);
					break;

				case 235:
				case 115: // Вниз
					down(ship2_2, Row, Col, x, y, symbol, var);
					system("cls");
					print(ship2_2, ship1_1, Row, Col, OnePlayer);
					break;
				case 8:
					return 1;
				case 13:// Выстрел
					if (ship2[x][y] == purpose)
					{
						int countlives = 0;
						ship2[x][y] = kil;
						ship2_2[x][y] = kil;
						var1 = kil;
						live = check(ship2, ship2_2, Row, Col, x, y, kil, purpose, score, cs, mr);
						int lives = check_lives(ship2, ship2_2, Row, Col, x, y, kil, purpose, countlives);
						switch (lives) {
						case 1:
							count1--;
							break;
						case 2:
							count2--;
							break;
						case 3:
							count3--;
							break;
						case 4:
							count4--;
						default:
							break;
						}
						system("cls");
						print(ship2_2, ship1_1, Row, Col, OnePlayer);
						if (live == 0) { cout << "Попал!"; }
						else cout << "Убил!!!";
						counter++;
						Sleep(500);
						Easter_Egg(ship2_2, Row, Col, '`', egg);
						goto link;
					}
					else if (ship2[x][y] == kil)
					{
						ship2_2[x][y] = kil;
						system("cls");
						print(ship2_2, ship1_1, Row, Col, OnePlayer);
						cout << "Уже стрелял!!";
						Sleep(500);
						goto link;
					}
					else
					{
						ship2_2[x][y] = '*';
						Easter_Egg(ship2_2, Row, Col, '`', egg);
						system("cls");
						print(ship2_2, ship1_1, Row, Col, OnePlayer);
						cout << "Мимо!";
						Sleep(500);
						goto link2;
					}
					break;

				default:
					break;
				}
			}

		}
		break;
	case 1:
	link2:
		Easter_Egg_2(ship2, ship3, Row, Col, egg3, purpose);
		x1 = 11; y1 = 10; ship1_1[x1][y1] = symbol;
		system("cls");
		cout << "Ходит Игрок №" << TwoPlayer << endl;
		cout << "  Вражеское поле: \t\t\t\t    Свое поле:" << endl;
		cout << "   1 2 3 4 5 6 7 8 9 10\t\t\t\t    1 2 3 4 5 6 7 8 9 10\n";
		cout << "   _ _ _ _ _ _ _ _ _ _\t\t\t\t    _ _ _ _ _ _ _ _ _ _\n";
		for (int i = 1; i < 11; i++)
		{
			cout << (char)('@' + i) << "| ";
			for (int j = 1; j < 11; j++)
			{
				cout << ship1_1[i][j] << " ";
			}
			cout << "|";
			cout << "\t\t\t ";
			cout << (char)('@' + i) << "| ";
			for (int j = 1; j < 11; j++)
			{
				cout << ship2_2[i][j] << " ";
			}
			cout << "|";
			cout << "\t|";
			if (i == 1) {
				cout << " " << " У вас осталось:";
			}
			if (i == 2) {
				cout << " " << count4 << " четырехпалубный";
			}
			if (i == 3) {
				cout << " " << count3 << " трехпалубных";
			}
			if (i == 4) {
				cout << " " << count2 << " двухпалубных";
			}
			if (i == 5) {
				cout << " " << count1 << " однопалубных";
			}
			if (i == 6) {
				cout << " " << " У противника осталось:";
			}
			if (i == 7) {
				cout << " " << count4_2 << " четырехпалубный";
			}
			if (i == 8) {
				cout << " " << count3_2 << " трехпалубных";
			}
			if (i == 9) {
				cout << " " << count2_2 << " двухпалубных";
			}
			if (i == 10) {
				cout << " " << count1_2 << " однопалубных";
			}
			cout << endl;
		}
		cout << "   - - - - - - - - - " << ship1_1[x1][y1] << "\t\t\t\t    - - - - - - - - - -\n";
		cout << "Нажимайте WASD для перемещения\nНажмите Enter для выстрела\nНажмите Backspace для выхода\n";

		if (egg2 == 0 && egg_1 == 0 && egg3 == 0)
		{
			cout << "Секретная пасхалка" << endl;
			for (int k = 0; k < Row; k++)
			{
				for (int k1 = 0; k1 < Col; k1++)
				{
					cout << ship2[k][k1] << " ";
				}
				cout << endl;
			}
		}

		while (counter1 < 20)
		{
			if (_kbhit())
			{
				reading = _getch();
				switch (reading)
				{
				case 230:
				case 119:  // В верх
					up(ship1_1, Row, Col, x1, y1, symbol, var1);
					system("cls");
					print(ship1_1, ship2_2, Row, Col, TwoPlayer);
					break;

				case 228:
				case 97:  // Влево
					left(ship1_1, Row, Col, x1, y1, symbol, var1);
					system("cls");
					print(ship1_1, ship2_2, Row, Col, TwoPlayer);
					break;

				case 162:
				case 100: //  Вправо
					right(ship1_1, Row, Col, x1, y1, symbol, var1);
					system("cls");
					print(ship1_1, ship2_2, Row, Col, TwoPlayer);
					break;

				case 235:
				case 115: // Вниз
					down(ship1_1, Row, Col, x1, y1, symbol, var1);
					system("cls");
					print(ship1_1, ship2_2, Row, Col, TwoPlayer);
					break;
				case 8:
					return 1;
					break;

				case 13:// Выстрел
					if (ship1[x1][y1] == purpose)
					{
						int countlives = 0;
						ship1_1[x1][y1] = kil;
						var = kil;
						ship1[x1][y1] = kil;
						live = check(ship1, ship1_1, Row, Col, x1, y1, kil, purpose, score, cs, mr);
						int lives2 = check_lives(ship1, ship1_1, Row, Col, x1, y1, kil, purpose, countlives);
						switch (lives2) {
						case 1:
							count1_2--;
							break;
						case 2:
							count2_2--;
							break;
						case 3:
							count3_2--;
							break;
						case 4:
							count4_2--;
						default:
							break;
						}
						system("cls");
						print(ship1_1, ship2_2, Row, Col, TwoPlayer);
						if (live == 0) { cout << "Попал!"; }
						else cout << "Убил!!!";
						counter1++;
						Sleep(500);
						Easter_Egg(ship1_1, Row, Col, '.', egg2);
						goto link2;
					}
					else if (ship1[x1][y1] == kil)
					{
						ship1_1[x1][y1] = kil;
						system("cls");
						print(ship1_1, ship2_2, Row, Col, TwoPlayer);
						cout << "Уже стрелял!!";
						Sleep(500);
						goto link2;
					}
					else
					{
						ship1_1[x1][y1] = '*';
						var = ship1_1[x1][y1];
						system("cls");
						print(ship1_1, ship2_2, Row, Col, TwoPlayer);
						cout << "Мимо";
						Sleep(500);
						Easter_Egg(ship1_1, Row, Col, '.', egg2);
						goto link;
					}
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
	system("cls");
	if (counter == 20) { cout << "\n\t\t\t\tWIN PLAER ONE!!!" << endl; }
	else { cout << "\n\t\t\t\tWIN PLAER TWO" << endl; }
	Sleep(1000);
	return 0;
}
int logik_human_vs_PC(char** ship3, char** ship1, char** ship2, int Row, int Col, char** ship1_1, char** ship2_2, char& var, char& var1, int OnePlayer, int TwoPlayer, int egg_1, int& score, int count1, int count2, int count3, int count4, bool str1, bool str2, bool str3, bool str4, bool str5, bool str6, bool str7, bool str8, bool str9, bool str10)
{
	int bang = 0, egg = 1, egg3 = 1, t, h, dir = 0, dir2 = 0, cs, mr;
	if (score == 0) {
		t = 1 + rand() % 10;
		h = 1 + rand() % 10;
	}
	int motion = rand() % 2;
	int  x = 11, y = 10,
		x1 = 11, y1 = 10,
		counter = 0, counter1 = 0, live = 0;
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			if (ship1[i][j] == '*')
			{
				ship1[i][j] = ' ';
			}
		}
	}

	char symbol = '+', purpose = '0', kil = 'X';
	Easter_Egg_2(ship1, ship3, Row, Col, egg3, purpose);
	int reading;

	switch (motion)
	{
	case 0:
	link:
		x = 11; y = 10; ship2_2[x][y] = symbol;
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
				cout << ship1[i][j] << " ";
				if (i == t && j == 10 && bang > 0) {
					cout << " <---- Выстрел";
					switch (i)
					{
					case 1:
						str1 = true;
						break;
					case 2:
						str2 = true;
						break;
					case 3:
						str4 = true;
						break;
					case 4:
						str4 = true;
						break;
					case 5:
						str5 = true;
						break;
					case 6:
						str6 = true;
						break;
					case 7:
						str7 = true;
						break;
					case 8:
						str8 = true;
						break;
					case 9:
						str9 = true;
						break;
					case 10:
						str10 = true;
						break;

					}
				}
			}
			cout << "|";
			if (i == 1) {
				if (str1 == true) {
					cout << " | У вас осталось:";
				}
				else {
					cout << "\t\t| У вас осталось:";
				}
				str1 = false;
			}
			if (i == 2) {
				if (str2 == true) {
					cout << " | " << count3_4 << " четырехпалубный";
				}
				else {
					cout << "\t\t| " << count3_4 << " четырехпалубный";
				}
				str2 = false;
			}
			if (i == 3) {
				if (str3 == true) {
					cout << " | " << count3_3 << " трехпалубных";
				}
				else {
					cout << "\t\t| " << count3_3 << " трехпалубных";
				}
				str3 = false;
			}
			if (i == 4) {
				if (str4 == true) {
					cout << " | " << count3_2 << " двухпалубных";
				}
				else {
					cout << "\t\t| " << count3_2 << " двухпалубных";
				}
				str4 = false;
			}
			if (i == 5) {
				if (str5 == true) {
					cout << " | " << count3_1 << " однопалубных";
				}
				else {
					cout << "\t\t| " << count3_1 << " однопалубных";
				}
				str5 = false;
			}
			if (i == 6) {
				if (str6 == true) {
					cout << " | У противника осталось:";
				}
				else {
					cout << "\t\t| У противника осталось:";
				}
				str6 = false;
			}
			if (i == 7) {
				if (str7 == true) {
					cout << " | " << count4 << " четырехпалубный";
				}
				else {
					cout << "\t\t| " << count4 << " четырехпалубный";
				}
				str7 = false;
			}
			if (i == 8) {
				if (str8 == true) {
					cout << " | " << count3 << " трехпалубных";
				}
				else {
					cout << "\t\t| " << count3 << " трехпалубных";
				}
				str8 = false;
			}
			if (i == 9) {
				if (str9 == true) {
					cout << " | " << count2 << " двухпалубных";
				}
				else {
					cout << "\t\t| " << count2 << " двухпалубных";
				}
				str9 = false;
			}
			if (i == 10) {
				if (str10 == true) {
					cout << " | " << count1 << " однопалубных";
				}
				else {
					cout << "\t\t| " << count1 << " однопалубных";
				}
				str10 = false;
			}
			cout << endl;
		}
		cout << "   - - - - - - - - - " << ship2_2[x][y] << "\t\t\t\t    - - - - - - - - - -\n";
		cout << "Нажимайте WASD для перемещения\nНажмите Enter для выстрела\nНажмите Backspace для выхода\n";
		if (egg == 0 && egg_1 == 0 && egg3 == 0)
		{
			cout << "Секретная пасхалка" << endl;
			for (int k = 0; k < Row; k++)
			{
				for (int k1 = 0; k1 < Col; k1++)
				{
					cout << ship2[k][k1] << " ";
				}
				cout << endl;
			}
		}

		while (counter < 20)
		{
			if (_kbhit())
			{
				reading = _getch();
				switch (reading)
				{
				case 8:
					return 1;
					break;
				case 230:
				case 119:  // В верх
					up(ship2_2, Row, Col, x, y, symbol, var);
					system("cls");
					print_pc(ship2_2, ship1, Row, Col, bang, t);
					break;

				case 228:
				case 97:  // Влево
					left(ship2_2, Row, Col, x, y, symbol, var);
					system("cls");
					print_pc(ship2_2, ship1, Row, Col, bang, t);
					break;

				case 162:
				case 100: //  Вправо
					right(ship2_2, Row, Col, x, y, symbol, var);
					system("cls");
					print_pc(ship2_2, ship1, Row, Col, bang, t);
					break;

				case 235:
				case 115: // Вниз
					down(ship2_2, Row, Col, x, y, symbol, var);
					system("cls");
					print_pc(ship2_2, ship1, Row, Col, bang, t);
					break;


				case 13:// Выстрел
					if (ship2[x][y] == purpose)
					{
						int countlives = 0;
						ship2[x][y] = kil;
						ship2_2[x][y] = kil;
						var1 = kil;
						live = check(ship2, ship2_2, Row, Col, x, y, kil, purpose, score, cs, mr);
						int lives = check_lives(ship2, ship2_2, Row, Col, x, y, kil, purpose, countlives);
						switch (lives) {
						case 1:
							count1--;
							break;
						case 2:
							count2--;
							break;
						case 3:
							count3--;
							break;
						case 4:
							count4--;
						default:
							break;
						}
						system("cls");
						print_pc(ship2_2, ship1, Row, Col, bang, t);
						if (live == 0) { cout << "Попал!"; }
						else cout << "Убил!!!";
						counter++;
						Sleep(500);
						Easter_Egg(ship2_2, Row, Col, '`', egg);
						goto link;
					}
					else if (ship2[x][y] == kil)
					{
						ship2_2[x][y] = kil;
						system("cls");
						print_pc(ship2_2, ship1, Row, Col, bang, t);
						cout << "Уже стрелял!!";
						Sleep(500);
						goto link;
					}
					else
					{
						ship2_2[x][y] = '*';
						system("cls");
						print_pc(ship2_2, ship1, Row, Col, bang, t);
						cout << "Мимо!";
						Sleep(500);
						Easter_Egg(ship2_2, Row, Col, '`', egg);
						goto link2;
					}
					break;
				default:
					break;
				}
			}

		}
		break;
	case 1:
	link2:
		bang = 0;
		if (score == 0) {
			t = 1 + rand() % 10;
			h = 1 + rand() % 10;
		}
		Logic_PC2(ship1, purpose, kil, Row, Col, counter1, t, h, bang, ship2_2, x, y, score, dir, dir2, cs, mr);
		if (counter1 == 20)
		{
			break;
		}
		goto link;
		break;
	default:
		break;
	}
	system("cls");
	if (counter == 20) { cout << "\n\t\t\t\tWIN PLAER ONE!!!" << endl; }
	else { cout << "\n\t\t\t\tWIN PLAER TWO" << endl; }
	Sleep(1000);
	return 0;
}


int main() {
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	int count4 = 1, count3 = 2, count2 = 3, count1 = 4, count4_2 = 1, count3_2 = 2, count2_2 = 3, count1_2 = 4;
	bool str1 = false, str2 = false, str3 = false, str4 = false, str5 = false, str6 = false, str7 = false, str8 = false, str9 = false, str10 = false;
	int Row = 12, Col = 12, score = 0;
	int OnePlayer = 1, TwoPlayer = 2;
	char var = '.', var1 = '`';
	char purpose = '0';
	int egg_1 = 1;
	int cs = 0, mr = 0;

	char** ship3 = new char* [Row];
	for (int i = 0; i < Row; i++)
	{
		ship3[i] = new char[Col];
	}
	ship3[1][1] = purpose;
	ship3[2][1] = purpose;
	ship3[3][1] = purpose;
	ship3[4][1] = purpose;

	ship3[1][3] = purpose;
	ship3[2][3] = purpose;
	ship3[3][3] = purpose;

	ship3[1][5] = purpose;
	ship3[2][5] = purpose;
	ship3[3][5] = purpose;

	ship3[1][7] = purpose;
	ship3[2][7] = purpose;

	ship3[1][9] = purpose;
	ship3[2][9] = purpose;

	ship3[6][1] = purpose;
	ship3[7][1] = purpose;

	ship3[6][3] = purpose;
	ship3[6][5] = purpose;
	ship3[6][7] = purpose;
	ship3[6][9] = purpose;

	char** ship1 = new char* [Row];
	for (int i = 0; i < Row; i++)
	{
		ship1[i] = new char[Col];
	}

	char** ship2 = new char* [Row];
	for (int i = 0; i < Row; i++)
	{
		ship2[i] = new char[Col];
	}

	char** ship2_2 = new char* [Row];
	for (int i = 0; i < Row; i++)
	{
		ship2_2[i] = new char[Col];
	}

	char** ship1_1 = new char* [Row];
	for (int i = 0; i < Row; i++)
	{
		ship1_1[i] = new char[Col];
	}

	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			ship1_1[i][j] = var;
			ship2_2[i][j] = var1;
		}
	}
	char game = 'Y';
	int read;
	short status = -1, modul = 1, mom = 0, mem = -1;

	while (game != 'N' && game != 'n' && game != 'Н' && game != 'н')
	{
	modul0:
		system("cls");
		cout << "\n\n\n\n            |\\  /|   ___   ___   ___        ___    \\_/      ___    ___    \\_/\n            | \\/ |  |   | |___| |     |  / |   |  |  /|    |      |   |  |  /|\n            |    |  |   | |     |     |_/  |   |  | / |    |___   |   |  | / |\n            |    |  |___| |     |___  |  \\ |___|  |/  |    |___|  |___|  |/  |";
		cout << "\n\n\n\n\t       __________________\n\t      | ________________ |\t\t\t   ________________\n\t      ||                ||\t\t\t  |                |\n\t      ||                ||\t\t\t  |                |\n\t      ||    И Г Р О К   ||\t\t\t  |    И Г Р О К   |\n\t      ||        &       ||\t\t\t  |        &       |\n\t      ||    И Г Р О К   ||\t\t\t  |    Р О Б О Т   |\n\t      ||________________||\t\t\t  |________________|\n\t      |__________________|";
		cout << "\n\n\n\tA / D - ДЛЯ ВЫБОРА\tENTER - ПОДТВЕРДИТЬ ВЫБОР\tBACKSPACE - ВЕРНУТЬСЯ НАЗАД";
		modul = 1; game = '0';
		int menucounter = 0;
		while (modul == 1) {
			if (_kbhit()) {

				read = _getch();
				switch (read)
				{
				case 228:
				case 97:
					system("cls");
					cout << "\n\n\n\n            |\\  /|   ___   ___   ___        ___    \\_/      ___    ___    \\_/\n            | \\/ |  |   | |___| |     |  / |   |  |  /|    |      |   |  |  /|\n            |    |  |   | |     |     |_/  |   |  | / |    |___   |   |  | / |\n            |    |  |___| |     |___  |  \\ |___|  |/  |    |___|  |___|  |/  |";
					cout << "\n\n\n\n\t       __________________\n\t      | ________________ |\t\t\t   ________________\n\t      ||                ||\t\t\t  |                |\n\t      ||                ||\t\t\t  |                |\n\t      ||    И Г Р О К   ||\t\t\t  |    И Г Р О К   |\n\t      ||        &       ||\t\t\t  |        &       |\n\t      ||    И Г Р О К   ||\t\t\t  |    Р О Б О Т   |\n\t      ||________________||\t\t\t  |________________|\n\t      |__________________|";
					cout << "\n\n\n\tA / D - ДЛЯ ВЫБОРА\tENTER - ПОДТВЕРДИТЬ ВЫБОР\tBACKSPACE - ВЕРНУТЬСЯ НАЗАД";
					if (menucounter == 0 || menucounter == 2 || menucounter == 3) {
						menucounter++;
					}
					else menucounter = 0;
					status = 1;
					break;
				case 162:
				case 100:
					system("cls");
					cout << "\n\n\n\n            |\\  /|   ___   ___   ___        ___    \\_/      ___    ___    \\_/\n            | \\/ |  |   | |___| |     |  / |   |  |  /|    |      |   |  |  /|\n            |    |  |   | |     |     |_/  |   |  | / |    |___   |   |  | / |\n            |    |  |___| |     |___  |  \\ |___|  |/  |    |___|  |___|  |/  |";
					cout << "\n\n\n\n\t\t\t\t\t\t          __________________\n\t        ________________  \t\t\t | ________________ |\n\t       |                | \t\t\t ||                ||\n\t       |                | \t\t\t ||                ||\n\t       |    И Г Р О К   | \t\t\t ||    И Г Р О К   ||\n\t       |        &       | \t\t\t ||        &       ||\n\t       |    И Г Р О К   | \t\t\t ||    Р О Б О Т   ||\n\t       |________________| \t\t\t ||________________||\n\t\t\t\t\t\t\t |__________________|";
					cout << "\n\n\n\tA / D - ДЛЯ ВЫБОРА\tENTER - ПОДТВЕРДИТЬ ВЫБОР\tBACKSPACE - ВЕРНУТЬСЯ НАЗАД";
					if (menucounter == 1) {
						menucounter++;
					}
					else menucounter = 0;
					status = 0;
					break;
				case 13:
					if (status != -1)
						modul = 0;
					break;
				case 8:
					game = 'N';
					return 0;
					break;
				default:
					break;
				}
			}
			if (menucounter == 4 && egg_1 == 1) {
				system("cls");
				cout << "\t\t\t\tПасхалка 1";
				egg_1 = 0;
				Sleep(1000);
				while (true) {
					if (_kbhit()) goto modul0;
				}
			}
		}
		while (modul == 0)
		{
			switch (status)
			{
			case 1:
			modul1:
				system("cls");
				cout << "\n\n\n\n            |\\  /|   ___   ___   ___        ___    \\_/      ___    ___    \\_/\n            | \\/ |  |   | |___| |     |  / |   |  |  /|    |      |   |  |  /|\n            |    |  |   | |     |     |_/  |   |  | / |    |___   |   |  | / |\n            |    |  |___| |     |___  |  \\ |___|  |/  |    |___|  |___|  |/  |";
				cout << "\n\n\t\t\t\t\tИ Г Р О К   №1";
				cout << "\n\n\n\t       __________________\n\t      | ________________ |\t\t\t   ________________\n\t      ||                ||\t\t\t  |                |\n\t      ||                ||\t\t\t  |                |\n\t      ||   РАССТАВИТЬ   ||\t\t\t  |   РАССТАВИТЬ   |\n\t      || В Р У Ч Н У Ю  ||\t\t\t  |С Л У Ч А Й Н О |\n\t      ||                ||\t\t\t  |                |\n\t      ||________________||\t\t\t  |________________|\n\t      |__________________|";
				cout << "\n\n\n\tA / D - ДЛЯ ВЫБОРА\tENTER - ПОДТВЕРДИТЬ ВЫБОР\tBACKSPACE - ВЕРНУТЬСЯ НАЗАД";
				game = '0', mom = 1;
				while (game != '1')
				{
					if (_kbhit()) {
						read = _getch();
						switch (read)
						{
						case 8:
							modul = 1;
							goto modul0;
							break;
						case 228:
						case 97:
							system("cls");
							cout << "\n\n\n\n            |\\  /|   ___   ___   ___        ___    \\_/      ___    ___    \\_/\n            | \\/ |  |   | |___| |     |  / |   |  |  /|    |      |   |  |  /|\n            |    |  |   | |     |     |_/  |   |  | / |    |___   |   |  | / |\n            |    |  |___| |     |___  |  \\ |___|  |/  |    |___|  |___|  |/  |";
							cout << "\n\n\t\t\t\t\tИ Г Р О К   №1";
							cout << "\n\n\n\t       __________________\n\t      | ________________ |\t\t\t   ________________\n\t      ||                ||\t\t\t  |                |\n\t      ||                ||\t\t\t  |                |\n\t      ||   РАССТАВИТЬ   ||\t\t\t  |   РАССТАВИТЬ   |\n\t      || В Р У Ч Н У Ю  ||\t\t\t  |С Л У Ч А Й Н О |\n\t      ||                ||\t\t\t  |                |\n\t      ||________________||\t\t\t  |________________|\n\t      |__________________|";
							cout << "\n\n\n\tA / D - ДЛЯ ВЫБОРА\tENTER - ПОДТВЕРДИТЬ ВЫБОР\tBACKSPACE - ВЕРНУТЬСЯ НАЗАД";
							mom = 1;
							break;
						case 162:
						case 100:
							system("cls");
							cout << "\n\n\n\n            |\\  /|   ___   ___   ___        ___    \\_/      ___    ___    \\_/\n            | \\/ |  |   | |___| |     |  / |   |  |  /|    |      |   |  |  /|\n            |    |  |   | |     |     |_/  |   |  | / |    |___   |   |  | / |\n            |    |  |___| |     |___  |  \\ |___|  |/  |    |___|  |___|  |/  |";
							cout << "\n\n\t\t\t\t\tИ Г Р О К   №1";
							cout << "\n\n\n\t\t\t\t\t\t          __________________\n\t        ________________  \t\t\t | ________________ |\n\t       |                | \t\t\t ||                ||\n\t       |                | \t\t\t ||                ||\n\t       |   РАССТАВИТЬ   | \t\t\t ||   РАССТАВИТЬ   ||\n\t       | В Р У Ч Н У Ю  | \t\t\t ||С Л У Ч А Й Н О ||\n\t       |                | \t\t\t ||\t\t   ||\n\t       |________________| \t\t\t ||________________||\n\t\t\t\t\t\t\t |__________________|";
							cout << "\n\n\n\tA / D - ДЛЯ ВЫБОРА\tENTER - ПОДТВЕРДИТЬ ВЫБОР\tBACKSPACE - ВЕРНУТЬСЯ НАЗАД";
							mom = 0;
							break;
						case 13:
							game = '1';
							break;
						default:
							break;
						}
					}
				}
				switch (mom)
				{
				case 1:
					mem = arrangement(ship1, Row, Col, OnePlayer);
					if (mem == 1) { goto modul1; };
					break;
				case 0:
					Randship(ship1, Row, Col);
					break;
				default:
					break;
				}
			modul2:
				game = '0';
				system("cls");
				cout << "\n\n\n\n            |\\  /|   ___   ___   ___        ___    \\_/      ___    ___    \\_/\n            | \\/ |  |   | |___| |     |  / |   |  |  /|    |      |   |  |  /|\n            |    |  |   | |     |     |_/  |   |  | / |    |___   |   |  | / |\n            |    |  |___| |     |___  |  \\ |___|  |/  |    |___|  |___|  |/  |";
				cout << "\n\n\t\t\t\t\tИ Г Р О К   №2";
				cout << "\n\n\n\t       __________________\n\t      | ________________ |\t\t\t   ________________\n\t      ||                ||\t\t\t  |                |\n\t      ||                ||\t\t\t  |                |\n\t      ||   РАССТАВИТЬ   ||\t\t\t  |   РАССТАВИТЬ   |\n\t      || В Р У Ч Н У Ю  ||\t\t\t  |С Л У Ч А Й Н О |\n\t      ||                ||\t\t\t  |                |\n\t      ||________________||\t\t\t  |________________|\n\t      |__________________|";
				cout << "\n\n\n\tA / D - ДЛЯ ВЫБОРА\tENTER - ПОДТВЕРДИТЬ ВЫБОР\tBACKSPACE - ВЕРНУТЬСЯ НАЗАД";
				mom = 1;
				while (game != '1')
				{
					if (_kbhit()) {
						read = _getch();
						switch (read)
						{
						case 8:
							modul = 1;
							goto modul0;
							break;
						case 228:
						case 97:
							system("cls");
							cout << "\n\n\n\n            |\\  /|   ___   ___   ___        ___    \\_/      ___    ___    \\_/\n            | \\/ |  |   | |___| |     |  / |   |  |  /|    |      |   |  |  /|\n            |    |  |   | |     |     |_/  |   |  | / |    |___   |   |  | / |\n            |    |  |___| |     |___  |  \\ |___|  |/  |    |___|  |___|  |/  |";
							cout << "\n\n\t\t\t\t\tИ Г Р О К   №2";
							cout << "\n\n\n\t       __________________\n\t      | ________________ |\t\t\t   ________________\n\t      ||                ||\t\t\t  |                |\n\t      ||                ||\t\t\t  |                |\n\t      ||   РАССТАВИТЬ   ||\t\t\t  |   РАССТАВИТЬ   |\n\t      || В Р У Ч Н У Ю  ||\t\t\t  |С Л У Ч А Й Н О |\n\t      ||                ||\t\t\t  |                |\n\t      ||________________||\t\t\t  |________________|\n\t      |__________________|";
							cout << "\n\n\n\tA / D - ДЛЯ ВЫБОРА\tENTER - ПОДТВЕРДИТЬ ВЫБОР\tBACKSPACE - ВЕРНУТЬСЯ НАЗАД";
							mom = 1;
							break;
						case 162:
						case 100:
							system("cls");
							cout << "\n\n\n\n            |\\  /|   ___   ___   ___        ___    \\_/      ___    ___    \\_/\n            | \\/ |  |   | |___| |     |  / |   |  |  /|    |      |   |  |  /|\n            |    |  |   | |     |     |_/  |   |  | / |    |___   |   |  | / |\n            |    |  |___| |     |___  |  \\ |___|  |/  |    |___|  |___|  |/  |";
							cout << "\n\n\t\t\t\t\tИ Г Р О К   №2";
							cout << "\n\n\n\t\t\t\t\t\t          __________________\n\t        ________________  \t\t\t | ________________ |\n\t       |                | \t\t\t ||                ||\n\t       |                | \t\t\t ||                ||\n\t       |   РАССТАВИТЬ   | \t\t\t ||   РАССТАВИТЬ   ||\n\t       | В Р У Ч Н У Ю  | \t\t\t ||С Л У Ч А Й Н О ||\n\t       |                | \t\t\t ||\t\t   ||\n\t       |________________| \t\t\t ||________________||\n\t\t\t\t\t\t\t |__________________|";							mom = 0;
							cout << "\n\n\n\tA / D - ДЛЯ ВЫБОРА\tENTER - ПОДТВЕРДИТЬ ВЫБОР\tBACKSPACE - ВЕРНУТЬСЯ НАЗАД";
							mom = 0;
							break;
						case 13:
							game = '1';
							break;
						default:
							break;
						}
					}
				}
				switch (mom)
				{
				case 1:
					mem = arrangement(ship2, Row, Col, TwoPlayer);
					if (mem == 1) { goto modul2; };
					break;
				case 0:
					Randship(ship2, Row, Col);
					break;
				default:
					break;
				}
				var = '.', var1 = '`';
				for (int i = 0; i < Row; i++)
				{
					for (int j = 0; j < Col; j++)
					{
						ship1_1[i][j] = var;
						ship2_2[i][j] = var1;
					}
				}
				mem = logik_human_vs_human(ship3, ship1, ship2, Row, Col, ship1_1, ship2_2, var, var1, OnePlayer, TwoPlayer, egg_1, score, cs, mr, count1, count2, count3, count4, count1_2, count2_2, count3_2, count4_2);
				if (mem == 1) {
					goto modul0;
				}
				modul = 1;
				break;
			case 0:
			modul3:
				mom = 1;
				system("cls");
				cout << "\n\n\n\n            |\\  /|   ___   ___   ___        ___    \\_/      ___    ___    \\_/\n            | \\/ |  |   | |___| |     |  / |   |  |  /|    |      |   |  |  /|\n            |    |  |   | |     |     |_/  |   |  | / |    |___   |   |  | / |\n            |    |  |___| |     |___  |  \\ |___|  |/  |    |___|  |___|  |/  |";
				cout << "\n\n\t\t\t\t\t  И Г Р О К";
				cout << "\n\n\n\t       __________________\n\t      | ________________ |\t\t\t   ________________\n\t      ||                ||\t\t\t  |                |\n\t      ||                ||\t\t\t  |                |\n\t      ||   РАССТАВИТЬ   ||\t\t\t  |   РАССТАВИТЬ   |\n\t      || В Р У Ч Н У Ю  ||\t\t\t  |С Л У Ч А Й Н О |\n\t      ||                ||\t\t\t  |                |\n\t      ||________________||\t\t\t  |________________|\n\t      |__________________|";
				cout << "\n\n\n\tA / D - ДЛЯ ВЫБОРА\tENTER - ПОДТВЕРДИТЬ ВЫБОР\tBACKSPACE - ВЕРНУТЬСЯ НАЗАД";
				while (game != '1')
				{
					if (_kbhit) {
						read = _getch();
						switch (read)
						{
						case 8:
							modul = 1;
							goto modul0;
							break;
						case 228:
						case 97:
							system("cls");
							cout << "\n\n\n\n            |\\  /|   ___   ___   ___        ___    \\_/      ___    ___    \\_/\n            | \\/ |  |   | |___| |     |  / |   |  |  /|    |      |   |  |  /|\n            |    |  |   | |     |     |_/  |   |  | / |    |___   |   |  | / |\n            |    |  |___| |     |___  |  \\ |___|  |/  |    |___|  |___|  |/  |";
							cout << "\n\n\t\t\t\t\t  И Г Р О К";
							cout << "\n\n\n\t       __________________\n\t      | ________________ |\t\t\t   ________________\n\t      ||                ||\t\t\t  |                |\n\t      ||                ||\t\t\t  |                |\n\t      ||   РАССТАВИТЬ   ||\t\t\t  |   РАССТАВИТЬ   |\n\t      || В Р У Ч Н У Ю  ||\t\t\t  |С Л У Ч А Й Н О |\n\t      ||                ||\t\t\t  |                |\n\t      ||________________||\t\t\t  |________________|\n\t      |__________________|";
							cout << "\n\n\n\tA / D - ДЛЯ ВЫБОРА\tENTER - ПОДТВЕРДИТЬ ВЫБОР\tBACKSPACE - ВЕРНУТЬСЯ НАЗАД";
							mom = 1;
							break;
						case 162:
						case 100:
							system("cls");
							cout << "\n\n\n\n            |\\  /|   ___   ___   ___        ___    \\_/      ___    ___    \\_/\n            | \\/ |  |   | |___| |     |  / |   |  |  /|    |      |   |  |  /|\n            |    |  |   | |     |     |_/  |   |  | / |    |___   |   |  | / |\n            |    |  |___| |     |___  |  \\ |___|  |/  |    |___|  |___|  |/  |";
							cout << "\n\n\t\t\t\t\t  И Г Р О К";
							cout << "\n\n\n\t\t\t\t\t\t          __________________\n\t        ________________  \t\t\t | ________________ |\n\t       |                | \t\t\t ||                ||\n\t       |                | \t\t\t ||                ||\n\t       |   РАССТАВИТЬ   | \t\t\t ||   РАССТАВИТЬ   ||\n\t       | В Р У Ч Н У Ю  | \t\t\t ||С Л У Ч А Й Н О ||\n\t       |                | \t\t\t ||\t\t   ||\n\t       |________________| \t\t\t ||________________||\n\t\t\t\t\t\t\t |__________________|";							mom = 0;
							cout << "\n\n\n\tA / D - ДЛЯ ВЫБОРА\tENTER - ПОДТВЕРДИТЬ ВЫБОР\tBACKSPACE - ВЕРНУТЬСЯ НАЗАД";
							mom = 0;
							break;
						case 13:
							game = '1';
							break;
						default:
							break;
						}
					}
				}
				switch (mom)
				{
				case 1:
					game = '0';
					mem = arrangement(ship1, Row, Col, OnePlayer);
					if (mem == 1) { goto modul3; };
					break;
				case 0:
					Randship(ship1, Row, Col);
					break;
				default:
					break;
				}
				Randship(ship2, Row, Col);
				var = '.', var1 = '`';
				for (int i = 0; i < Row; i++)
				{
					for (int j = 0; j < Col; j++)
					{
						ship1_1[i][j] = var;
						ship2_2[i][j] = var1;
					}
				}
				mem = logik_human_vs_PC(ship3, ship1, ship2, Row, Col, ship1_1, ship2_2, var, var1, OnePlayer, TwoPlayer, egg_1, score, count1, count2, count3, count4, str1, str2, str3, str4, str5, str6, str7, str8, str9, str10);
				if (mem == 1) {
					goto modul0;
				}
				modul = 1;
				break;

			default:
				break;
			}
		}
		cout << "\t\t\t\tPlay again(Y/N?) | Хотите сыграть снова (Д/Н)?" << endl;
		while (true)
		{
			if (_kbhit()) {

				game = _getch();
				break;
			}
		}
		switch (game)
		{
		case 8:
		case 27:
			return 0;
		default:
			break;
		}

	}
	return 0;
}