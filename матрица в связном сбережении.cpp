// матрица в связном сбережении.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

struct list
{
	int a;
	list *next;
};

void builder(list *& beg,int b)
{
	if (!beg)
	{
		list *temp = new list;
		temp->a = b;
		temp->next = NULL;
		beg = temp;
	}
	else
	{
		list *temp = new list;
		temp->a = b;
		temp->next = beg;
		beg = temp;
	}
	/*list *temp = new list;
	temp->next = beg->next;
	beg->next = temp;*/
}

void print(list *beg)
{
	while (beg)
	{
		cout << beg->a << " ";
		beg = beg->next;
	}
	cout << endl;
}

int main()
{
	list *l = NULL;
	const int n = 3;
	int a[n][n];
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
			cin >> a[i][j];
	system("cls");
	for (int i = 0;i < n;i++)
	{
		cout << endl;
		{
			for (int j = 0;j < n;j++)
				cout << setw(3) << a[i][j];
		}
	}
	cout << endl << endl << "*********" << endl;
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
			if (a[i][j] != 0)
				builder(l, a[i][j]);
	print(l);
	system("pause");
    return 0;
}

