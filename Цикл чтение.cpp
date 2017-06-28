// Цикл чтение.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


struct list
{
	int x;
//	bool k;
	list *next;
};


void builder(list *&beg, int f )
{
	//size++;
	if (!beg)
	{
		list *temp = new list;
		temp->x = f;
		//temp->k = false;
		temp->next = temp;
		beg = temp;
	}
	else {
		list *temp = new list();
		temp->x = f;
		//temp->k = false;
		temp->next = beg->next;
		beg->next = temp;
	}
}


void rebuilt(list *beg,list *&beg2)
{
	if (beg != NULL)
	{
		//list *p = beg;
		//cout << "Kolcevoj Spisok:" << endl;
		//cout << p->x << endl;
		//p = p->next;
		/*while (p->next != beg)
		{
			//cout << p->x << endl;
			p = p->next;
		}*/
		/*p->k = true;
		cout << p->x << endl;
		while (size-1)
		{
			while (p->next->k == false || p->next->next->k==false)
			{
				p = p->next;
			}
			cout << p->x << endl;
			p->k = true;
			size--;
		}*/
		list *temp = beg->next;
		builder(beg2, temp->x);
		temp = temp->next;
		while (temp != beg->next)
		{
			builder(beg2, temp->x);
			temp = temp->next;
		}

	}
	else
		cout << "Spisok pust." << endl;
}


void print(list *beg)
{
	if (beg)
	{
		list *temp = beg->next;
		cout << temp->x << " ";
		temp = temp->next;
		while (temp != beg->next)
		{
			cout << temp->x << " ";
			temp = temp->next;
		}

	}
}

int main()
{
	list *l(NULL),*d(NULL);
	//static int size = 0;
	for (int i = 0;i < 4;i++)
	{
		builder(l, i+1);
	}
	print(l);
	cout << endl;
	rebuilt(l, d);
	print(d);
	cout << endl;
	system("pause");
    return 0;
}

