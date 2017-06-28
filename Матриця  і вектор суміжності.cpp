// Матриця  і вектор суміжності.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

const int max = 16;
struct vec
{
	int n;
	unsigned int e[max];
};

int main()
{
	vec *l = NULL;
	const int m = 4;
	int a[m][m];
	for (int i = 0;i < m;i++)
		for (int j = 0;j < m;j++)
			cin >> a[i][j];
	l = new vec;
	for (int i = 0;i < m;i++)
		l->e[i] = 0;
	l->n = m;
	for (int i = 0;i < m;i++)
	{
		int f = 0;
		for (int j = m - 1;j >= 0;j--)
		{

			l->e[i] =l->e[i] +(a[i][j] * pow(2, f));
			f++;
		}
	}
	system("cls");
	cout << l->n << " (";
	for (int i = 0;i < m;i++)
		cout << l->e[i] << " ";
	cout << ")\n";
	system("pause");
    return 0;
}

