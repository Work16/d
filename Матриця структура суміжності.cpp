// Матриця структура суміжності.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;


struct list
{
	int val;
	list *next;
};

void builder(list *&beg, int a)
{
	if (!beg)
	{
		list *temp;
		temp = new list;
		temp->val = a;
		temp->next = NULL;
		beg = temp;
	}
	else
	{
		list *temp;
		temp = new list;
		temp->val = a;
		temp->next = beg;
		beg = temp;
	}
}

void print(list *beg)
{
	while (beg)
	{
		cout << beg->val+1 << " ";
		beg = beg->next;
	}
	cout << endl;
}




int main()
{
	const int n = 3;
	int a[n][n];
	list *l[n];
	for (int i = 0;i < n;i++)
		l[i] = NULL;
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
		{
			cout << "Enter element:\n";
			cin >> a[i][j];
			if (a[i][j])
				builder (l[i], j);
		}
	system("cls");
	for (int i = 0;i < n;i++)
		print(l[i]);
	system("pause");
    return 0;
}

