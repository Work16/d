// ���������� ���������.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include <conio.h>
using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "\t\t ���������� ��������� \n\n";
	const int n = 5;
	int a[n];
	for (int i = 0;i < n;i++)
	{
		cout << "������� �������� " << i + 1 << " �������� ������:";
		//cin >> a[i];
		while (!(cin >> a[i]))
		{
			cin.clear();
			while ((cin.get()) != '\n');
			cout << "������� �������� " << i + 1 << " �������� ������:";
		}
	}
	
	system("cls");
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n-1;j++)
		{ 
			if (a[j] > a[j + 1])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}

		}
	}
	cout << "\t\t�������������� �����:\n\n";
	for (int i = 0;i < n;i++)
	{
		cout << i+1 << "������� ������: " << a[i] << endl;
	}
	_getch();
    return 0;
}

