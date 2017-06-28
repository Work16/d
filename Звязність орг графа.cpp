// ַגÿחם³סעü מנד דנאפא.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iomanip>
#include <iostream>
using namespace std;




int main()
{
	bool flag = false;
	const int n = 3;
	int a[n][n],count=0;
	for (int i = 0;i < n;i++)
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
			cout << a[i][j] << " ";
	for (int i = 0;i < n;i++)
	{
		count = 0;
		for (int j = 0;j < n;j++)
		{
			if (a[j][i]) count++;
			if (count == n)
				flag = true;
		}
	}
	for (int i = 0;i < n;i++)
	{
		count = 0;
		for (int j = 0;j < n;j++)
		{
			if (a[i][j]) count++;
			if (count == n)
				flag = true;
		}
	}
	if (flag)
		cout << "yes\n";
	else
		cout << "no\n";
	system("pause");
    return 0;
}

