// транспонована матриц€.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include <conio.h>
using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "\t\tтранспонована матриц€\n\n";
	const int n = 2, m = 3;
	int a[n][m];
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			cout << "¬ведите [" << i+1 << "," << j+1 << " ] елемент матрици:";
			while (!(cin >> a[i][j]))
			{
				cin.clear();
				while (cin.get() != '\n');
				cout << "¬ведите [" << i+1 << "," << j+1 << " ] елемент матрици:";
			}
		}
	}
	system("cls");
	int b[n][m];
	for (int i = 0;i < n-1;i++)
	{
		for (int j = 0;j < m-1;j++)
		{ 
		 	b[i][j] = a[i][j];
			a[i][j] = a[j][i];
			a[j][i] = b[i][j];
		}
	}
	for (int i = n;i < n - 1;i++)
	{
		for (int j = m;j < m - 1;j++)
		{
			a[i][j] = b[j][i];
		}
	}
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			cout << a[i][j] << endl;
		}
	}

	_getch();
    return 0;
}

