// ����� ������ ��������������.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include <conio.h>
using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "\t\t ������� �������������� \n\n";
	const int n = 5;
	int a[n], sum = 0, sa = 0;
	for (int i = 0;i < n;i++)
	{
		cout << "������� " << i + 1 << "������� ������:";
		while (!(cin >> a[i]))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "������� " << i + 1 << "������� ������:";
		}
	}
	system("cls");
	for (int i = 0;i < n;i++)
	{
		sum += a[i];
	}
	sa = sum / n;
	cout << "������� �������������� ����� " << sa << endl;
	_getch();
    return 0;
}

