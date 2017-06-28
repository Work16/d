// калькулятор.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include <conio.h>
#include <cmath>
using namespace std;

int main()
{
	double a, b;
	char c;
	cout << "a=";
	cin >> a;
	cout << "b=";
	cin >> b;
	cout << "enter operetion:";
	cin >> c;
	/*if (c == '+')
		cout << a << "+" << b << "=" << (a + b)<<"\n";
	else if (c == '-')
		cout << a << "-" << b << "=" << (a - b) << "\n";
	else if (c == '*')
		cout << a << "*" << b << "=" << (a*b) << "\n";
	else cout << a << "/" << b << "=" << (a / b) << "\n";*/
	switch (c)
	{
	case '+': cout << a << "+" << b << "=" << (a + b) << "\n";break;
	case'-':  cout << a << "-" << b << "=" << (a - b) << "\n"; break;
	case '*': cout << a << "*" << b << "=" << (a*b) << "\n";break;
	default: cout << a << "/" << b << "=" << (a / b);
	}
	_getch();
    return 0;
}

