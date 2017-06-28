// мода.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include <conio.h>
using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "\t\tмода\n\n";
	const int n = 5;
	int a[n],count=0, max=0;
	for (int i = 0;i < n;i++)
	{
		cout << "¬ведите " << i + 1 << " елемент последовательности :";
		while (!(cin >> a[i]))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "¬ведите " << i + 1 << " елемент последовательности :";
		}
	}
	for (int i = 0;i < n - 1;i++)
	{
		for (int j = 0;j < n - 1;j++)
		{
			if (a[j] > a[j + 1])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			if (a[i] == a[i + j])
			{
				count++;
			}
		}
		if (count > max)
		{
			max = count;
		}
	}
	for (int i = count;i < max;i++)
	{
		cout << a[i] << endl;
	}
	
	_getch();
    return 0;
}

