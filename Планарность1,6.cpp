// Планарность1,6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

struct list
{
	int val;
	list *next;
};
const int  n =5;
bool  visited[n];
void builder(list *&beg, int a)
{
	if (beg)
	{
		list *temp = beg;
		while (temp->next)
			temp = temp->next;
		temp->next = new list;
		temp->next->val = a;
		temp->next->next = NULL;
	}
	else
	{
		beg = new list;
		beg->val = a;
		beg->next = NULL;
	}
}

void print(list *beg, int i)
{
	if (beg)
	{
		cout << i + 1 << " вершина смежная с ";
		while (beg)
		{
			cout << beg->val << " ";
			beg = beg->next;
		}
		cout << "вершиной\\вершинами " << endl;
	}
}




void dfs(list **l, int j,int &q)
{
	
		visited[j] = true;
		list *temp = l[j];
		while (temp)
		{
			if (!visited[temp->val])
			{
				q--;
			//	builder(p[j], l[j]->val);
				dfs(l, temp->val,q);
			}
			temp = temp->next;
		}
	
}



int main()
{
	int k = 0;//количество компонент связности
	int z;//количество ребер 
	int q = 0;//количество граней без общей
	setlocale(LC_ALL, "Russian");
	int a = 1;
	list *l[n];
	for (int i = 0;i < n;i++)
		l[i] = NULL;
	for (int i = 0;i < n;i++)
	{
		a = 1;
		while (a > 0)
		{
			cout << "Введите смежную с " << i + 1 << " вершину:\n";
			cin >> a;
			if (a > 0)
			{
				builder(l[i], a - 1);q++;
			}
		}
		system("cls");
	}
	q = q / 2;
	z= q;
	if (n>=3 && !(z < 3 * n - 6))
	{
		cout << "Граф НЕ планарен!!!";
		system("pause");
		return 0;
	}

		for (int i = 0;i < n;i++)
			visited[i] = false;
		for (int i = 0;i < n;i++)
			if (!visited[i])
			{
				k++;
				dfs(l, i, q);
			}
		system("cls");
	//	cout << "**" << q << "***" << endl;
	//	cout << z << endl << k << endl;

			if (q + 1 + n - z== 1 + k)
				cout << "Граф планарен!!!" << endl;
			else
				cout << "Граф НЕ планарен !!!" << endl;
	
	system("pause");
	return 0;
}

