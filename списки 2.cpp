// списки 2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

struct Node { char val;Node *next; };



void  write(Node *next)
{
	Node *p, *prev;
	Node *temp = new Node;
	p = new Node; p->next = NULL; p->val = 3;
	prev = new Node; prev->next = p;prev->val = 2;
	p = prev;
	prev = new Node; prev->next = p;prev->val = 5;
	p = prev;
}

void watch(Node *next)
{
	Node *p, *prev;
	Node *temp = new Node;
	p = new Node; p->next = NULL; cout << p->val <<"\n" ;
	prev = new Node; prev->next = p;cout<< prev->val<< "\n";
	p = prev;
	prev = new Node; prev->next = p; cout << prev->val <<"\n";
	p = prev;
}

int main()
{
	Node *next=0;
	 write(next);
	 watch(next);
	system("pause");
    return 0;
}

