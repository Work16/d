// пересечение множеств.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

struct list
{
	int val;
	list *next;
};

void builder(list *beg,int a)
{
	list *temp = new list;
	if (!beg)
	{
		temp->val = a;
		temp->next = NULL;
		beg = temp;
	}
	else
	{
		temp->val = a;
		temp->next = beg;
		beg = temp;
	}

}

void print(list *&beg)
{
	while (beg)
	{
		cout << beg->val << " ";
		beg = beg->next;
	}
	cout << endl;
}

list * love(list *&a, list*&b)
{
	list* temp = new list;
	temp = NULL;
	if ((!a && !b)|| (!a)||(!b)) return NULL;
	else
	{

		while (a&&b)
		{
			if (a->val == b->val)
			{
				if (temp)
				temp = temp->next;
				temp->val = a->val;
				//temp->next = NULL;
				a = a->next;
				b = b->next;
			}
			else if (a->val < b->val)
				b = b->next;
			else
				a = a->next;
		}
		a = temp;
		return a;
	}
}
int main()
{
	list *l = NULL,*m=NULL;
	int a;
	for (int i = 0;i < 4;i++)
	{
		cout << "a=";
		cin >> a;
		builder(l, a);
	}
	for (int i = 0;i < 4;i++)
	{
		cout << "a=";
		cin >> a;
		builder(m, a);
	}
	love(l, m);
	print(l);
	system("pause");
    return 0;
}

