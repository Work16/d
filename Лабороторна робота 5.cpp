// Ћабороторна робота 5.cpp : Defines the entry point for the console application.
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

void search(list *t)
{
	bool *num;
	num = new bool[t->val];
	int i = 0;
	for (i = 0;i <t-> val;i++)
		num[i] = i < t->val;
	for (i = 0;i < t->val;i++)
		if (num[i])dfs(t, i);
}

void dfs(list *t, int i)
{
	list *v;
	cout << v << ",";
	num[i] = ;
	for(v=s
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
		cout << "¬ведите смежную с " << i + 1 << " вершину:\n";
		cin >> a;
		builder(l[i], a - 1);
	}
	system("cls");
	
	system("pause");
	return 0;
}



