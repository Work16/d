// ���� ��������� �������.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include <conio.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "\t\t ���� ��������� �������\n\n";
	int sum=0;
	const int n = 5;
	int a[n];
	for (int i = 0;i < n;i++)
	{
		cout << "������� " << i + 1 << " ������� ������:";
		cin >> a[i];
	}
	system("cls");
	for (int i = 0; i < n;i++)
	{
		sum += a[i];
	}
	cout << "���� ��������� ������� ����� " << sum << endl;
	_getch();
    return 0;
}

