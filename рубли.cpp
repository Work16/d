// рубли.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include <conio.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int  rubley;
	cout << "Количество рублей:";
	cin >> rubley;
	cout << "\n\n";
	if (rubley < 0)
	{
		cout << "\tВи ввели отрицательное количество рубей!\n";
		_getch();
		return -1;
	}
	if ((rubley % 100) >= 11 && (rubley % 100) <= 19)
		cout << "\t У вас " << rubley << "рублей!\n";
	if ((rubley % 10) == 1)
		cout << "\t У вас " << rubley << "рубль!\n";
	else if ((rubley % 10) >= 2 && (rubley % 10) <= 4)
		cout << "\t У вас" << rubley << "рубля!\n";
	else
		cout << "\t У вас " << rubley << "рублей!\n";
		_getch();
    return 0;
}

