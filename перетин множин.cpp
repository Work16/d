// перетин множин.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

struct list
{
	int val;
	list *next;
};

void builder(list *&beg, int v)
{
	if (beg)
	{
		list *temp = beg;
		while (temp->next)
			temp = temp->next;
		temp->next = new list;
		temp->next->val = v;
		temp->next->next = NULL;
	}
	else
	{
		beg = new list;
		beg->val = v;
		beg->next = NULL;
	}
}
void print(list *beg)
{
	while (beg)
	{
		cout << beg->val << " ";
		beg = beg->next;
	}
}

void petogether(list *t, list *t1, list *&t2)
{
	while (t1 && t)
	{
		if (t->val > t1->val)
		{
			builder(t2, t1->val);
				t1 = t1->next;
		}
		else
			if (t->val < t1->val)
			{
				builder(t2, t->val);
				t = t->next;
			}
			else
			{
				t = t->next;
				t1 = t1->next;
			}
	}
	while (t)
	{
		builder(t2, t->val);
		t = t->next;
	}
	while (t1) 
	{
		builder(t2, t1->val);
		t1 = t1->next;
	}
}
void peretun(list *t, list *t1, list *&t2)
{
	while (t && t1)
	{
		if (t->val > t1->val)
			while (t1 &&t->val > t1->val )
				t1 = t1->next;
		else if (t->val == t1->val)
		{
			builder(t2, t->val);
			t = t->next;
			t1 = t1->next;
		}
		else
			while (t && t->val <t1->val)
				t = t->next;
	}
}
int main()
{
	setlocale(LC_ALL, "Russian");
	list *t = NULL,*t1=NULL,*t2=NULL;
	int a=1;
	cout << "¬ведите элементы первого множества:\n";
	while (a > 0)
	{
			cin >> a;
			if(a>0)
			builder(t, a);
		
	}
	a = 1;
	system("cls");
	cout << "¬ведите элементы второго множества:\n";
	while (a > 0)
	{
			cin >> a;
			if(a>0)
			builder(t1, a);
	}
	system("cls");
	peretun(t, t1, t2);
	print(t2);
	cout << endl;
	system("pause");
    return 0;
}

