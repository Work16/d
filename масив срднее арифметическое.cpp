// масив срднее арифметическое.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include <conio.h>
using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "\t\t среднее арифметическое \n\n";
	const int n = 5;
	int a[n], sum = 0, sa = 0;
	for (int i = 0;i < n;i++)
	{
		cout << "Введите " << i + 1 << "елемент масива:";
		while (!(cin >> a[i]))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "Введите " << i + 1 << "елемент масива:";
		}
	}
	system("cls");
	for (int i = 0;i < n;i++)
	{
		sum += a[i];
	}
	sa = sum / n;
	cout << "среднее арифметическое равно " << sa << endl;
	_getch();
    return 0;
}

