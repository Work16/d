// Количество нулей.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


const int m = 10;

struct list
{
	int val;
	int position;
	list *next;
};


void add(list *&beg, int x, int y)
{
	list *temp = new list;
	if (!beg)
	{
		temp->val = x;
		temp->position = y;
		temp->next = NULL;
		beg = temp;
	}
	else
	{
		temp->val = x;
		temp->position = y;
		temp->next = beg;
		beg = temp;
	}
}


int count(list *beg,int i,int j)
{
	int count = 0;
	while (beg->next)
	{
		if (i < beg->position < j && beg->position-beg->next->position !=0)
		{
			count += beg->position - beg->next->position -1;
		}
		beg = beg->next;
	}
	return count;
}

int main()
{
	list *l = NULL;
	int x, y = 0, i, j, v;
	for (int k = 0;k < m;k++)
	{
		cout << "Enter number:\n";
		cin >> x;
		y++;
		if (x != 0)
		{
			add(l, x, y);
			//y = 0;
		}
	}
	cout << "Enter i and j :\n";
	cin >> i >> j ;
	/*if (search(l, i, j, v))
		cout << "True\n";
	else
		cout << "False\n";*/
	cout << count(l, i, j)<<endl;
	system("pause");
    return 0;
}

