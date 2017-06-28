// Максимум.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

struct tree
{
	int val;
	tree *right, *left;
};

void add(tree *&t, int a)
{
	if (t)
	{
		if (a < t->val)
		{
			if (t->left) add(t->left, a);
			else
			{
				t->left = new tree;
				t->left->val = a;
				t->left->left = t->left->right = NULL;
			}
		}
		if (a > t->val)
		{
			if (t->right) add(t->right, a);
			else
			{
				t->right = new tree;
				t->right->val = a;
				t->right->right = t->right->left = NULL;
			}
		}
	}
	else
	{
		t = new tree;
		t->val = a;
		t->left = t->right = NULL;
	}
}

int max(tree *t)
{
	if (t->right)
	{
		return max(t->right);
	}
	return t->val;
}
int max1(tree *t)
{
	while (t->right)
		t = t->right;
	return t->val;
}

int main()
{
	tree *t = NULL;
	int a;
	for (int i = 0;i < 3;i++)
	{
		cin >> a;
		add(t, a);
	}
	cout << max(t) << endl << max1(t) << endl;
	system("pause");
    return 0;
}

