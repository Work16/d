// ѕланарнысть графа цикли.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


struct list
{
	int val;
	bool was;
	list *next;
};






void builder(list *&beg, int a)
{
	if (!beg)
	{
		list *temp;
		temp = new list;
		temp->val = a;
		temp->was = false;
		temp->next = NULL;
		beg = temp;
	}
	else
	{
		list *temp;
		temp = new list;
		temp->val = a;
		temp->was = false;
		temp->next = beg;
		beg = temp;
	}
}

void dfs(list ** l, int i)
{

}

void maxver(list *beg,int &count)
{
	while (beg)
	{
		count++;
		beg = beg->next;
	}
	
}


int main()
{
	
	setlocale(LC_ALL, "Russian");
	const int n = 3;
	bool were[n];
	for (int i = 0;i < n;i++)
		were[i] = 0;
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
	int count[n];
	for (int i = 0;i < n;i++)
		count[i] = 0;
	for (int i = 0;i < n;i++)
		maxver(l[i],count[i]);
	int max = -159;
	for (int i = 0;i < n;i++)
		if (count[i]>max)
			max = count[i];
	bool **visited;
	*visited = new bool[max];
	for (int i = 0;i < max;i++)
		visited[i] = new bool[max];
	for (int i = 0;i < n;i++)
	{
		while (count[i])
		{
			count[i]--;

        }
	}
	system("pause");
	return 0;
}
