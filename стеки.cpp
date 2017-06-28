// стеки.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

const int n = 6;

struct m
{
	int val;

}a[n];
int p = -1, q = n;


void add(int i, int j)
{
	switch (j)
	{
	case 1:
	{
		p++;
		a[p].val = i;
		break;
	}
	case 2:
	{
		q--;
		a[q].val = i;
		break;
	}
	default: cout << "Your date is useless...\n";
	}
}

void del(int i, int j)
{
	switch (j)
	{
	case -1 :
	{
		if (p == -1)
			cout << "Stack1 is free\n";
		else
		p--;
		break;
	}
	case -2 :
	{
		if (q == n)
			cout << "Stack 2 is free\n";
		else
		q++;
		break;
	}
	default: cout << "Your date is useless...\n";
	}
}

int main()
{
	int i, j;
	for (int u = 0;;u++)
	{
		if (p == q - 1)
		{
			cout << "Steck is overflow \n";
			break;
		}
		cout << "Enter i and j:\n";
		cin >> i >> j;
		switch (bool(j >= 0))
		{
		case 0:
		{
			del(i, j);
			break;
		}
		case 1: 
		{
			add(i, j);
		}
		}
	}
	cout << "\n***\n";
	for (int u = 0;u < n;u++)
	{
		cout << a[u].val<<' ';
	}
	cout << endl;
	system("pause");
    return 0;
}

