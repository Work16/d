// числа фібоначі.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include <conio.h>
using namespace std;


int main()
{
	/*int n;
	cout << "n=";
	cin >> n;
	int *a;
	a = new int[2*n];
	a[0] = 1;
	a[1] = 1;
//	cout << a[0] << endl << a[1] << endl;
	for (int i = 0;i < 2*n+1;i++)
	{
		if (i == 0 || i==1)
			a[i] = 1;
		else
		a[i] = a[i - 1] + a[i - 2];
		cout << a[i] << endl;
		if (a[i] > n)
		{
			cout << "***" << endl << a[i] << endl << i + 1 << endl;
			system("pause");
			return 0;
		}
	}*/
	unsigned long long x = 1;
	unsigned long long y = 0;
	unsigned long long  n;
	cout << "n=";
	cin >> n;
	int k = 0;
	while (1)
	{
		k++;
		unsigned long long z = x + y;
		x = y;
		y = z;
		cout << z << endl;
		if (z > n)
		{
			cout << "***\n" << z << endl << k << endl;
			_getch();
			return 0;

		}
	}
}

