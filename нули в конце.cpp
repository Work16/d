// ���� � �����.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include <conio.h>
using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");
	int n = 0,count =0;
	cout << "n=";
	cin >> n;
	int *a,*b;
	a = new int[n];
	b = new int[n];
	for (int i = 0;i < n;i++)
	{
		cout << "������� " << i + 1 << " ������� ������:";
		while (!(cin >> a[i]))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "������� " << i++ << " ������� ������:";
		}
	}
	system("cls");
	for (int i = 0;i < n;i++)
	{
		b[i] = 0;
	}
	int j = 0;
	for (int i = 0;i < n;i++)
	{
		if (a[i] != 0)
		{
			b[j] = a[i];
			j++;
		}
	}
	for (int i = 0;i < n;i++)
	{
		cout << b[i] << endl;
	}
	delete[] b;
	delete[] a;
		_getch();
    return 0;
}
