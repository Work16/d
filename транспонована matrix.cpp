// транспонована matrix.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include <conio.h>
#include <iomanip>
using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "n=";
	cin >> n;
	int **p;
	p = new int *[n];
	for (int i = 0;i < n;i++)
	{
		p[i] = new int[n];
	}
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			cout << "Введите [" << i + 1 << "," << j + 1 << "] елемент матрици :";
			while (!(cin >> p[i][j]))
			{
				cin.clear();
				while (cin.get() != '\n');
				cout << "Введите [" << i + 1 << "," << j + 1 << "] елемент матрици :";
			}
		}
	}
	system("cls");
	cout << "Your matrix:";
	for (int i = 0;i < n;i++)
	{
		cout << "\n";
		for (int j = 0;j < n;j++)
		{
			cout << setw(3)<<p[i][j];
		}
	}
	cout << "\ntransponen matrix:\n";
	int **b;
	b = new int *[n];
	for (int i = 0;i < n;i++)
	{
		b[i] = new int[n];
	}
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			b[i][j] = p[j][i];
		}
	}
	for (int i = 0;i < n;i++)
	{
		cout << "\n";
		for (int j = 0;j < n;j++)
		{
			cout << setw(3) << b[i][j];
		}
	}
	for (int i = 0;i < n;i++)
	{
		delete[]p[i];
	}
	delete[] p;
	for (int i = 0;i < n;i++)
	{
		delete[] b[i];
	}
	delete[] b;
	_getch();
    return 0;
}

