// планарность графа.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

const int n = 5;
int visited[n];
struct list
{
	int val;
	list *next;
};
void dfs(list **l, list **p, int j)
{
	if (0 < j < n)
	{
		visited[j] = 1;
		while (l[j])
		{
			if (!visited[l[j]->val])
				dfs(l, p, l[j]->val);
			l[j] = l[j]->next;
		}
	}

}
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
		cout << "¬ведите смежную с " << i + 1 << " вершину:\n";
		cin >> a;
		if (a!=i)
		builder(l[i], a - 1);
	}
	system("cls");
	int count_0 = 0;
	for (int i = 0;i < n;i++)
	{
		if (visited[i] == 0)
			count_0++;
		visited[i]++;
	}
	for (int i = 0;i < n;i++)
		if (visited[i] != 1)
		{

		}
	for (int i = 0;i < n;i++)
		print(l[i]);
	system("pause");
	return 0;
}





