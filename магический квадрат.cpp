// магический квадрат.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include <conio.h>
#include <iomanip>
using namespace std;


int main()
{
	int n,sum=0,sum2=0,count=0;
	cout << "n=";
	cin >> n;
	int **p;
	p = new int *[n];
	for (int i = 0;i < n;i++)
	{
		p[i] = new int[n];
	}
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			cout << "Enter [" << i + 1 << "," << j + 1 << "] element of matrix:";
			while (!(cin >> p[i][j]))
			{
				cin.clear();
				while (cin.get() != '\n');
				cout << "Enter [" << i + 1 << "," << j + 1 << "] element of matrix:";
			}
		}
	}
	system("cls");
	for (int i = 0;i < n;i++)
	{
		cout << "\n";
		for (int j = 0;j < n;j++)
		{
			cout << setw(3) << p[i][j];
		}
	}
	cout << endl << endl;
	for (int i = 0;i < 1;i++)
	{
		for (int j = 0;j < n;j++)
		{
			sum += p[i][j];
		}
	}
	for (int i = 1;i < n;i++)
	{
		sum2 = sum;
		sum = 0;
		for (int j = 0;j < n;j++)
		{
			sum += p[i][j];
		}
		if (sum != sum2)
		{
			cout << "Answer negative!\n";
		}
		else {
			count++;
		}
	}
	if (count > 0)
	{
		cout << "Answer positive!\n";
	}
	for (int i = 0;i < n;i++)
	{
		delete[] p[i];
	}
	delete[]p;
	_getch();
    return 0;
}

