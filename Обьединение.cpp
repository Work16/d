// Обьединение.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

struct list
{
	int val;
	list *next;
};

void add(list *&t, int v)
{
	if (t)
	{
		list *temp = t;
		if (temp->val > v)
		{
			list *f = new list;
			f->val = v;
			f->next = temp;
			temp = f;
			return;
		}
		while (temp->next)
		{
			if (t->next->val>v)
			{
				list *f = new list;
				f->next = temp->next;
				temp->next = f;
				f->val = v;
				return;
			}
			temp = temp->next;
		}
		if (temp->val <= v && temp->next == NULL)
		{
			list *f = new list;
			f->next = NULL;
			temp->next = f;
			f->val = v;
			return;
		}
	}
	else
	{
		t = new list;
		t->next = NULL;
		t->val = v;
		return;
	}
}
void print(list *t)
{
	while (t)
	{
		cout << t->val << " ";
		t = t->next;
	}
}
void together(list *&t, list *&h)
{
	list *temp = t;
	while (temp->next)
		temp = temp->next;
	temp->next = h;
}

int main()
{
	list *t = NULL,*h=NULL;
	int a;
	for (int i = 0;i < 5;i++)
	{
		cin >> a;
		add(t, a);
	}
	system("cls");
	for (int i = 0;i < 5;i++)
	{
		cin >> a;
		add(h, a);
	}
	system("cls");
	together(t, h);
	print(t);
	system("pause");
    return 0;
}

