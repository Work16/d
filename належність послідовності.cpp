// належність послідовності.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
using namespace std;


struct list
{
	int a;
	list *next;
};


void builder(list *&head ,int b)
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
void print(list *p)
{
	while (p)
	{
		cout << p->a << " ";
		p = p->next;
	}
	cout << endl;
}

bool nalez (list *& head,int c)
{
	bool q =false;
	list *temp = new list ,*r=new list;
	temp = head;
	/*for (int i = 0;i < 9;i++)
	{
		r = temp;*/
	for (int j = 0;j < 9 ;j++)
	{
		if (temp->a == c)
			q = true;
		temp = temp->next;
	}
		/*}
		temp = r->next;
	}*/
	return q;
}
int main()
{
	list *l=NULL;
	int a;
	for (int i = 0;i < 10;i++)
	{
		cin >> a;
		builder(l, i);
	}
	print(l);
	if (nalez(l, 5))
		cout << "true\n";
	else
		cout << "false\n";
	_getch();
    return 0;
}

