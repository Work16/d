// лаб4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

struct tree
{
	int x;
	tree *l, *r;
};

void builder(tree *&beg,int x)
{
		if (!beg) 
		{
			beg = new tree; 
			beg->x = x; 
			beg->l = beg->r = NULL; 
		}

		if (x<beg->x)   
		{
			if (beg->l ) builder(beg->l,x); 
			else 
			{
				beg->l = new tree;  
				beg->l->l = beg->l->r = NULL; 
				beg->l->x = x;  
			}
		}

		if (x>beg->x)  
		{
			if (beg->r != NULL) builder(beg->r,x); 
			else 
			{
				beg->r = new tree;  
				beg->r->l = beg->r->r = NULL; 
				beg->r->x = x;
			}
		}

	}
void show(tree *beg)
{
	if (beg)
	{
		cout << beg->x << " ";
		for (int i = 0;i < 5;i++) show(beg->r);
	}
}

int main()
{
	tree *l = NULL;
	for (int i = 0;i < 5;i++)
		builder(l, i);
	show(l);
	system("pause");
    return 0;
}

