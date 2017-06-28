// ѕЋјЌј–Ќќ—“№ 1,2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


struct gr
{
	int val;
	bool was;
	gr *next;
};

const int n = 4;

void add(gr *&t, int v)
{
	if (t)
	{
		gr *temp = t;
		temp = new gr;
		temp->val = v;
		temp->was = false;
		temp->next = t;
		t = temp;
	}
	else
	{
		t = new gr;
		t->val = v;
		t->was = false;
		t->next = NULL;
	}
}
void print(gr *f)
{
	while (f)
	{
		cout << f->val << " " << f->was << " ";
		f = f->next;
	}
}
void dfs(gr **&t, gr *f, int &count, int &count1, int i, int j, int **visited)
{
	gr *temp = t[j];
	if (temp == f)
		return;
	count++;
	if (t[j]->was)
		count1++;
	while (temp)
	{
		if (visited[i][temp->val] != 1)
			dfs(t, f, count, count1, i, temp->val, visited);
		temp = temp->next;
	}
}

int main()
{
	gr *k[n];
	for (int i = 0;i < n;i++)
		k[i] = NULL;
	int a=1;
	for (int i = 0;i < n;i++)
	{
		cout << "¬ведите смежные с " << i + 1 << "вершины:\n";
		a = 1;
		while (a)
		{
			cin >> a;
			add(k[i], a-1);
		}
	}
	int visited[n*n-n][n];
	for (int i = 0;i < n*n-n;i++)
		for (int j = 0;j < n;j++)
			visited[i][j] = 0;
	int copy[n];
	for (int i = 0;i <n;i++)
		copy[i] = 0;
	int count =0, count1 = 0,z=0;
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;)
		{

		}
	}
	system("pause");
    return 0;
}

