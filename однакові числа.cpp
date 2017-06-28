// однакові числа.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
using namespace std;

struct list
{
	int a;
	bool t;
	list *next;
};


void builder(list *&head,int b)
{
	if (head == NULL)
	{
		list *k=new list;
		k->a = b;
		k->t = false;
		k->next = NULL;
		head = k;
	}
	else
	{
		list *n = new list;
		n->a = b;
		n->t = false;
		n->next = head;
		head = n;
	}
}


 void print(list *c)
{
	while (c)
	{
		cout << c->a << "  ";
		c = c->next;
	}
	cout << endl;
}



 void same(list *&head,int &q)
 {
	 
	 int k = 0;
	 list *temp = new list, *temp2 = new list;
	 if (head == NULL)
		 cout << "mistake\n";
	 else
	 {
		
		 int k = 0;
		 temp = head;
		 for (int i = 0;i < 9;i++)
		 {
			/* for (int j = 0;j < 10;j++)
			 {
				 temp->t = temp2->t;
				 temp->next = temp2->next= head;
				 head = temp = temp2;
			 }*/
			 temp2 = temp->next;
			 for (int j = 0;j < 9-i ;j++)
			 {
				 if (temp->t == true)
					 break;
				 if (temp2->a == temp->a )
				 {
					 k++;
					 temp->next->t = true;
				 }
				 temp2=temp2->next;
			 }
			 if (k > 0)
				 q++;
			 temp = temp->next;
		 }
	 }
 }

int main()
{
	int q = 0;
	list *l=NULL;
	int a;
	for (int i = 0;i < 10;i++)
	{
		cin >> a;
		builder(l, a);
	}
	print(l);
	same(l, q);
	cout <<"***\n"<<q;
	_getch();
    return 0;
}

