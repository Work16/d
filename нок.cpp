// ���.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include <conio.h>
using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");
	int a, b,c;
	cout << "a=";
	cin >> a;
	cout << "b=";
	cin >> b;
	if (a == 0 || b == 0)
		cout << "��� �� ����������!!!" << "\n";
	else if (a % b == 0)
		cout << "���:" << a << "\n";
	else if (b % a ==0)
		cout << "���:" << b << "\n";
	else
	{
		c = a;
		while (a != b)
		{
			if (a > b)
				a = a - b;
			else b = b - a;
			}
		cout << "���:" << (a*b)/c ;
	}
	_getch();
    return 0;
}

