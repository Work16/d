// лаб4 Деревья и множества.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

//const int n = 10;

struct node
{
	int value;
	node *l,*r;
};

void builder(node *&beg, int k)
{
	if (beg == NULL)
	{
		node *tree = new node;
		tree->value = k;
		tree->l = tree->r = NULL;
	}
	else
	{
		if (k < beg->value)
		{
			if (beg->l != NULL)
				builder(beg->l, k);
			else
			{
				beg->l = new node;
				beg->l->l = beg->l->r = NULL;
				beg->l->value = k;
			}
		
		}
		else
		{
			if (beg->r != NULL)
				builder(beg->r, k);
			else
			{
				beg->r = new node;
				beg->r->l = beg->r->r = NULL;
				beg->r->value = k;
			}
			
		}
	}
}

void show(node *&beg)
{
	if (beg!=NULL)
	{show(beg->l);
	cout << beg->value << endl;
	show(beg->r);}
}


int main()
{
	node *f = NULL;
	int k;
	for (int i = 0;i < 7;i++)
	{
		//cout << "k=";
		//cin >> k;
		builder(f, i+1);
	}
	system("cls");
	show(f);
	system("pause");
    return 0;
}

