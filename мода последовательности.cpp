// мода последовательности.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "conio.h"
using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "\t\t мода последовательности\n\n";
	const int n=5;
	int a[n];
	int u, y;
	for (int i = 0;i < n;i++)
	{
		cout << "¬ведите " << i+1 << "елемент масива:";
		while (!(cin >> a[i]))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "¬ведите " << i+1 << "елемент масива:";
		}
	}
	system("cls");

	_getch();
    return 0;
}

