// ���������� �������.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include <conio.h>
using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "\t\t���������� �������\n\n";
	const int n = 2, m = 2;
	int a[n][m],count=0;
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			cout << "������� [ " << i+1 << "," << j+1 << " ] ������� ������:";
			while (!(cin >> a[i][j]))
			{
				cin.clear();
				while (cin.get() != '\n');
				cout << "������� [ " << i+1 << "," << j+1 << " ] ������� ������:";
			}
		}
	}
	system("cls");
	for (int i = 0;i < n-1;i++)
	{
		for (int j = 0;j < m-1;j++)
		{
			if (a[i][j] != a[j][i])
				count++;
		}
	}
	if (count == 0)
		cout << "������� - ����������!\n";
	else
		cout << "������� - ������������!\n";
		_getch();
    return 0;
}

