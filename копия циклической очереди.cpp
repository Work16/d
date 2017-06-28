// копия циклической очереди.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

struct quee
{
	int place;
	int val;
	quee *next;
};
void add(quee *&t,int v)
{
	if (t)
	{

	}
	else
	{
		t = new quee;
		t->val = v;
		t->place=1;
		t->next = t;
	}
}


int main()
{
	quee *t = NULL;
	system("pause");
    return 0;
}

