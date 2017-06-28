// Осн операції над бін деревами.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

struct tree
{
	int val;
	tree *l, *r;
};
tree * p;
	tree* build(int nn) {
		 int dd, nleft, nright;
		if (!nn) return NULL;  
		nleft = nn / 2;  
		nright = nn - nleft - 1;   
		cout << "Enter node data: "; cin >> dd; cout << endl;
		p = new tree; p->val = dd; 
		p->l = build(nleft);  
		p->r = build(nright);  
		return p;
	}


void sym_ord(tree *&t)
{
	sym_ord(t->l);
	cout << t->val << " ";
	sym_ord(t->r);
}
int max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}
int height(tree *cur)
{
	if (cur)
	{
		return 1 + max(height(cur->l), height(cur->r));
	}
	return 0;
}
int main()
{
	//tree *t = NULL;
	int a;
	//cout << "Enter node data: ";
	cin >> a;
		 build(a);

	sym_ord(p);
	system("pause");
    return 0;
}

