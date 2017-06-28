// рядки за не спаданням.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include <conio.h>
#include <iomanip>
using namespace std;


int main()
{
	int n, m;
	cout << "n=";
	cin >> n;
	cout << "m=";
	cin >> m;
	int **p;
	p = new int *[n];
	for (int i = 0;i < n;i++)
	{
		p[i] = new int[m];
	}
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			cout << "Enter [" << i + 1 << "," << j + 1 << "] element of matrix :";
			while (!(cin >> p[i][j]))
			{
				cin.clear();
				while (cin.get() != '\n');
				cout << "Enter [" << i + 1 << "," << j + 1 << "] element of matrix :";
			}
		}
	}
	system("cls");
	cout << "Your matrix :\n";
	for (int i = 0;i < n;i++)
	{
		cout << "\n";
		for (int j = 0;j < m;j++)
		{
			cout << setw(3) << p[i][j];
		}
	}
	cout << "\nResult:\n";
	for (int k = 0;k < n*m;k++)
	{
		for (int i = 0;i < n - 1;i++)
		{
			if (p[i][0] > p[i + 1][0])
			{
				for (int j = 0;j < m;j++)
				{
					swap(p[i][j], p[i + 1][j]);
				}
			}

		}
	}
	for (int i = 0;i < n;i++)
	{
		cout << "\n";
		for (int j = 0;j < m;j++)
		{
			cout << setw(3) << p[i][j];
		}
	}
	for (int i = 0;i < n;i++)
	{
		delete[] p[i];
	}
	delete[]p;
	_getch();
    return 0;
}

