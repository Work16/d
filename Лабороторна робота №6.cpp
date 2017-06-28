// Лабороторна робота №6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

struct tree
{
	int val;
	int height;
	tree *right;
	tree *left;
};
/*char height(tree *&p)
{
	if (p) return p->height;
	else return 0;
}*/

int BF(tree *&p)
{
	return p->right->height - p->left->height;
}
void OverHeight(tree *&p)
{

	int hleft = p->left->height;
	int hright = p->right->height;
	p->height = (hleft>hright ? hleft : hright) + 1;
}
tree* RightRotation(tree *&x)
{
	tree *y = x->left;
	x->left = y->right;
	y->right = x;
	OverHeight(x);
	OverHeight(y);
	return y;
}
tree *LeftRotation(tree *&y)
{
	tree *x = y->right;
	y->right = x->left;
	x->left = y;
	OverHeight(y);
	OverHeight(x);
	return x;
}
tree *Balance(tree *&x)
{
	OverHeight(x);
	if (BF(x) == 2)
	{
		if (BF(x->right)<0) x->right = RightRotation(x->right);
		return LeftRotation(x);
	}
	if (BF(x) == -2)
	{
		if (BF(x->left)>0) x->left = LeftRotation(x->left);
		return RightRotation(x);
	}
	return x;
}
tree *SearchMin(tree *&x)
{
	if (x->left) return SearchMin(x->left);
	else return x;
}
tree *Insert(tree *&x, int k)
{
	if (!x) {
		x = new tree;
		x->val = k;
		x->left = x->right = NULL;
		x->height = 1;
		return x;
	}
	if (k<x->val) x->left = Insert(x->left, k);
	else x->right = Insert(x->right, k);
	return Balance(x);
}
tree *DeleteMin(tree *&x)
{
	if (x->left == 0) return x->right;
	x->left = DeleteMin(x->left);
	return Balance(x);
}
tree *Delete(tree *&x, int k)
{
	if (!x) return 0;
	if (k<x->val) x->left = Delete(x->left, k);
	else if (k>x->val) x->right = Delete(x->right, k);
	else
	{
		tree *y = x->left;
		tree *z = x->right;
		delete x;
		if (!z) return y;
		tree * min = SearchMin(z);
		min->right = DeleteMin(z);
		min->left = y;
		return Balance(min);
	}
	return Balance(x);
}


void print(tree *x)
{
	if (x)
	{
		print(x->left);
		cout << x->val << " ";
		print(x->right);
	}
}
int main()
{
	tree *x = NULL;
	int k;
	for (int i = 0;i < 3;i++)
	{
		cin >> k;
		Insert(x, k);
	}
		cout << "*****\n";
		print(x);
		cout << "\n*****\n";
		cin >> k;
		Delete(x, k);
		cout << "******\n";
		print(x);
		cout << endl;
	system("pause");
    return 0;
}

