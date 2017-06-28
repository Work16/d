// Планарен ли граф.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;


const int n = 3;
int visited[n*n-n][n*n-n];
int with[n];

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

/*void dfs(list **l, int i,int k)
{
	if (l[i])
	{
		list *p = l[i];
		visited[k][p->val] = 1;
		for (int j= 0;j < n;j++)
			if (j != k)
				visited[j][p->val] = -1;
		for (int i = 0;i < n;i++)
			for (int j = 0;j < n;j++)
				if (visited[i][j]==1)
				visited[i][j] == visited[j][i];

	//	p->was = true;
		while (p)
		{
			if (!visited[k][p->val])
			{

				dfs(l, p->val,k);
			}

			p = p->next;
		}
	}
}*/
/*void dfs(list **l, int i, int k)
{
	if (l[i])
	{
		list *p = l[i];
		visited[k][p->val] = 1;
		/*for (int j = 0;j < n;j++)
			if (j != k)
				visited[j][p->val] = -1;*/
		/*for (int i = 0;i < n;i++)
			for (int j = 0;j < n;j++)
				if (visited[i][j] == 1)
					visited[i][j] = visited[j][i];

		//	p->was = true;
		while (p)
		{
			if (visited[k][p->val]==0 || visited[k][p->val]==-1)
			{

				dfs(l, p->val, k);
			}

			p = p->next;
		}
	}
}*/
/*void dfs(list *l,int j,int i)
{
		list *p = l;
		visited[i][j] = true;
		menu:
		while (p)
		{
			if (!visited[i][p->val])
			{
				dfs(p, p->val, i);
			}
			p = p->next;
		}
		if ()
		{

			goto menu;
		}

}*/

void dfs1(list **l,  int j)
{
	list *t = l[j];
	
		with[j] ++;

		while (t)
		{
			if (!visited[t->val])

				dfs1(l,  t->val);
			t = t->next;
		}
	

}
int main()
{
	setlocale(LC_ALL, "Russian");
	int a=1,count=0,q=0;
	list *l[n];
	for (int i = 0;i < n;i++)
		l[i] = NULL;
	for (int i = 0;i < n;i++)
			with[i] = false;

	for (int i = 0;i < n;i++)
	{
		a = 1;
		cout << "Введите смежную с " << i + 1 << " вершину:\n";
		while (a > 0)
		{
			cin >> a;
			if (a > 0 && a != i)
			{
				builder(l[i], a - 1);
				//q++;//считаем ребра
			}
		}
			system("cls");
	}
	system("cls");
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
		visited[i][j] = 0;
	for (int i = 0;i < n;i++)
	{
		if (l[i])
		{
			if (visited[i][count]==0)
			{
				list *p = l[i];
				while (p)
				{

					if (visited[count][p->val] == 0)
					{
						visited[count][p->val] = 1;
						for (int j = 0;j < n;j++)
							if (j != count)
								visited[j][p->val] = -1;

						count++;//считаем грани 
						dfs(l[i], p->val, count);
					}

					p = p->next;
				}
			}
		}
		
	}
	int f = 0;
	for (int i = 0;i < n*n-n;i++)
	{
		cout << endl;
		for (int j = 0;j < n*n-n;j++)
			cout << setw(3) << visited[i][j];
	}
	cout << endl;
	for (int i = 0;i < n*n-n;i++)
	{
		f = 1;
		for (int j = 0;j <n*n-n;j++)
		{
			if (visited[j][i]==1) f++;
			if (f > 2)
			{
				cout << "Граф НЕ планарен!\n";
				system("pause");
				return 0;
			}
		}
	}
	cout << "Граф планарен!\n";
	int max = -159;
	//Поиск количества компонент связности
/*	for (int i = 0;i < n;i++)
		if (with[i]>max)
			max = with[i];
	//Формула ейлера
	if (n - q + count == 1 + max)
		cout << "Граф планарен!\n";
	else
		cout << "Граф НЕ планарен!\n";*/
	system("pause");
	return 0;
}


