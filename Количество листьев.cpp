// Количество листьев.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


struct list
{
	int val;
	list *l, *r;
};

void add(int x, list *&tree)
{
	if (!tree)
	{
		tree = new list;
		tree->l = tree->r = NULL;
		tree->val = x; 
	}

	else if (!tree->l) add(x, tree->l); 
	else add(x, tree->r); 
}

int search(list *beg)
{
	static int count = 0;
	if (!beg) return count;
	if (beg-> l!= NULL || beg->r != NULL)
		count++;
	search(beg->r);
	search(beg->l);
	return count;


}

int max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

int height(list *cur)
{
	if (cur)
	{
		return 1 + max(height(cur->l), height(cur->r));
	}
	return 0;
}

int main()
{
	list *k = NULL;
	const int n = 5;
	for (int i = 0;i < n;i++)
	{
		add(i + 1, k);
	}
	cout << "Fun =" << search(k)<< endl;
	cout << "****\n";
	cout << height(k)<< endl;
	system("pause");
    return 0;
}

