// ≥зольован≥ вершини матриц€.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

const int n = 2;

int fall(int a[n][n])
{
	int count = 0,z=0;
	for (int i = 0;i < n;i++)
	{
		z = 0;
		for (int j = 0;j < n;j++)
			if (!a[i][j]) z++;
		if (z == n)
			count++;
	}
	return count;
}

int main()
{
	int a[n][n];
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
			cin >> a[i][j];
	system("cls");
	cout << fall(a) << endl;
	system("pause");
    return 0;
}

