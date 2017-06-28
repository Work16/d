// лічилка.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


typedef struct list
{
	int a;
	list *next;

}listp,*listn;


void builder(listn &beg,listn &end,int b,int &c)
{
		listn n = new listp;
		n->next = beg;
		n->a = b;
		c++;
		if (beg == NULL)
		{
			end->next = n;
			end = n;
		}
		else
		{
			//beg = end = n;

		}
}


void linch(listn &beg)
{
	/*listn l = NULL;
	listn f = new listp;
	f = beg;
	while (f)
	{
		//delet(l);
		cout << f<<" ";
	}*/
}

void print(listn beg , listn end , int &c)
{
	listn h = new listp;
	int g = c;
	while (g)
	{
		cout << h->a << " ";
		h = h->next;
		c--;
	}
}


/*void delet(listn &beg,int k,int &f)
{
	listn p = new listp;
	p = beg;
	if (p->a==k)
	{
		f = p->a;

	}
	while (p->next->next)
	{
		if ((p->next)->a == k)
		{
			f = (p->next)->a;
		 p->next = p->next->next;
			(p->next)->a = (p->next->next)->a;
		}
		p=p->next;
	
}*/



int main()
{
	int s = 0;
	int f;
	listn l=NULL;
	listn k = NULL;
	int n, m;
	cout << "n=";
	cin >> n;
	cout << "m=";
	cin >> m;
	for (int i = n;i > 0;i--)
	{
		builder(l, k,i,s);
	}
	print(l, k, s);
//	print(l);
//	print(l);
	//lich(l, m);
	system("pause");
    return 0;
}

