// Зовнішнє представлення графу.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
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
		cout << beg->val << " ";
		beg = beg->next;
	}
	cout << endl;
}


int main()
{
	setlocale(LC_ALL, "Russian");
	const int n = 3;
	int a;
	list *l[n];
	for (int i = 0;i < n;i++)
		l[i] = NULL;
	for (int i = 0;i < n;i++)
	{
		cout << "Введите смежную с " << i+1 << " вершину:\n";
		cin >> a;
		builder(l[i], a-1);
	}
	system("cls");
	for (int i = 0;i < n;i++)
		print(l[i]);
	system("pause");
    return 0;
}

