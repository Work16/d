// квадратное уравнение.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include<conio.h>
#include <cmath>
using namespace std;

int main()
{
	cout << "\t\ta*x^2+b*x+c=0\n";
	int a, b, c;
	cout << "a=";
	cin >>  a;
	cout << "b=";
	cin >> b;
	cout << "c=";
	cin >> c;
	int d = b*b - 4 * a*c;
	if (d < 0)
		cout << "there is no solution!\n";
	else if (d == 0)
		cout << "x=" << (-b) /( 2*a) << "\n";
	else
	{
		cout << "x1=" << ((-b) + sqrt(d)) / (2 * a) << "\n";
		cout << "x2=" << ((-b) - sqrt(d)) / (2 * a) << "\n";
	}
	_getch();
    return 0;
}

