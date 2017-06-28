// нод.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include <conio.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int a, b;
	cout << "a=";
	cin >> a;
	cout << "b=";
	cin >> b;
	if (a == 0 || b == 0)
		cout << "Нод не существует !!!";
	else if (a % b == 0)
		cout << b << "\n";
	else if (b % a == 0)
		cout << a << "\n";
	else
	{
		while  (a != 0 &&  b != 0)
		{
	          	if (a > b)
					a = a % b;
				else b = b % a;
			}
		cout << a + b << "\n";
		}
	
	
	_getch();
    return 0;
}

