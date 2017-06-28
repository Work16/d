// сума.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
using namespace  std;


typedef struct list
{
	int a;
	list *next;
} listn , *listp;



void builder(list *&head, int b)
{
	if (head == NULL)
	{
		list *k = new list;
		k->a = b;
		k->next = NULL;
		head = k;
	}
	else
	{
		list *n = new list;
		n->a = b;
		n->next = head;
		head = n;
	}
}


/*int sum(listp beg)
{
	//if (beg == NULL) return 0;
	if (!beg)return 0;

	while (beg)
	{
		return (beg->a + sum(beg->next));
	}
	
}*/

int pl (listp beg, int sum)
{
	while (beg)
	{
		sum += beg->a;
		beg = beg->next;
	}
	return sum;
}
int main()
{
	listp l=NULL;
	int sum = 0;
	for (int i = 0;i < 3;i++)
	{
		builder(l, i+1);
	}
	cout << "***" << pl(l,sum);
	_getch();
    return 0;
}

