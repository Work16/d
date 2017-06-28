// ќбединение  бинарных деревьев.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

struct tree
{
	int val;
	int count;
	tree *l, *r;
};

void add(tree *&t,int x)
{
	if (t)
	{
		if (x < t->val)
		{
			if (t->l) add(t->l, x);
			else
			{
				t->l = new tree;
				t->l->val = x;
				t->l->count = 1;
				t->l->l = t->l->r = NULL;
			}
		}
		else if (x>t->val)
		{

			if (t->r) add(t->r, x);
			else
			{
				t->r = new tree;
				t->r->val = x;
				t->r->count = 1;
				t->r->l = t->r->r = NULL;
			}
		}
		else t->count++;
}
	else
	{
		t = new tree;
		t->val = x;
		t->count = 1;
		t->l = t->r = NULL;
	}
}
void together(tree *&t, tree *&t1)
{
	if (t1)
	{
		add(t, t1->val);
		if (t1->count > 1)
			t->count += t1->count - 1;
		together(t, t1->l);
		together(t, t1->r);
	}
}

void del (tree *t)
{
	if (t->l)del(t->l);
	 if (t->r)del(t->r);
	delete t;
}

void print(tree *&t)
{
	if (t)
	{
		print(t->l);
		cout << t->val << " " << t->count << endl;
		print(t->r);
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	tree *t = NULL, *t1 = NULL;
	int a, n;
	cout << "¬ведите количество элементов первого дерева:\n";
	cin >> n;
	if (n > 0)
	{
		cout << "¬ведите значение дл€ первого дерева:\n";
		for (int i = 0;i < n;i++)
		{
			cin >> a;
			add(t, a);
		}
	}
	cout << "¬ведите количество элементов второго дерева:\n";
	cin >> n;
	if (n > 0)
	{
		cout << "¬ведите значение дл€ второго дерева:\n";
		for (int i = 0;i < n;i++)
		{
			cin >> a;
			add(t1, a);
		}
	}
	system("cls");
	together(t, t1);
	del(t1);
	cout << "ќбьединение деревьев:\n";
	print(t);
	system("pause");
    return 0;
}

