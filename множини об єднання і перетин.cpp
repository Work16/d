// множини об єднання і перетин.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


struct list
{
	int x;
	list *next;
};
void builder(list *& beg,int b)
{
	if (beg == NULL)
	{
		list*n = new list;
		n->x = b;
		n->next = NULL;
		beg = n;
	}
	else
	{
		list *k = new list;
		k->x = b;
		k->next = beg;
		beg = k;
	}
}
void print(list *& beg)
{
	while (beg)
	{
		cout << beg->x << " ";
		beg = beg->next;
	}
	cout << endl;
}
void plu(list *&beg1, list *&beg2,list *&beg3)
{
	if (beg1 == NULL && beg2 == NULL)
	{
		beg3->next = NULL;
	}
	else if (beg1 == NULL)
	{
         builder(beg3, beg2->x);
	   plu(beg1, beg2->next,beg3);
	}
	else if (beg2 == NULL)
	{
		builder(beg3, beg1->x);
		beg3->next =	plu(beg1->next, beg2,beg3);
	}
	else
	{
		if (beg1->x > beg2->x)
		{builder(beg3, beg1->x);
		plu(beg1->next, beg2,beg3);}
		else if (beg1->x<beg2->x)
		{
			builder(beg3, beg2->x);
			plu(beg1, beg2->next,beg3);
		}
		else {
			builder(beg3, beg1->x);
			plu(beg1->next, beg2->next, beg3);
		}
	}
}

int main()
{
	list *l = NULL, *b = NULL, *c = NULL;
	int a;
	for (int i = 0;i < 3;i++)
	{
		cout << "a=";
		cin >> a;
		builder(l, a);
	}
	system("cls");
	for (int i = 0;i < 3;i++)
	{
		cout << "a=";
		cin >> a;
		builder(b, a);
	}
	system("cls");
	print(l);
	print(b);
	plu(l, b, c);
	print(c);
	system("pause");
	return 0;
}

