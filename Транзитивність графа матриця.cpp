// Транзитивність графа матриця.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	const int n = 3;
	int a[n][n], count = 0;
	for (int i = 0;i< n;i++)
		for (int j = 0;j < n;j++)
			cin >> a[i][j];
	system("cls");
	for (int k = 0;k < n;k++)
		for (int i = 0;i < n;i++)
			if (a[i][k])
				for (int j = 0;j < n;j++)
					a[i][j] = a[i][j] || a[k][j];
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
			if (a[i][j])
				count++;
	if (count == n*n)
		cout << "Yes\n";
	else
		cout << "No\n";
	system("pause");
    return 0;
}

