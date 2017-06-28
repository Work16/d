// список 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

struct Node { char val;Node *next; };//Listn, *Listp;

Node* builder(char a, char b, char c)
{
	Node *p, *prev;
	p = new Node; p->next = NULL;p->val = c;
	prev = new Node;p->next = p; prev->val = b; 
	p = prev;
	prev = new Node; prev->next = p; prev->val = a;
	p = prev;
	return p;
}




void  deleting_first(Node **beg)
{
	Node *temp = (*beg)->next;
	delete *beg;
	*beg = temp;
}




void deleteing_last(Node **beg)
{
	Node *temp1 , *temp2;
	temp1 = *beg;
	temp1 = temp1->next;
	//delete temp->next; temp->next = NULL;
	temp2= temp1/*(beg)*/->next;
	temp1->next = NULL;
}

void deleteing_second(Node *beg)
{
	Node *t = beg->next;
	beg->next = t->next;
	delete t;
}


void add_end(Node *beg,char ch)
{
	Node *temp = beg->next;
	while (temp->next)
	{
		temp = temp->next;
	}
	Node *newIteam = new Node;  newIteam->val = ch; newIteam->next ;
		temp -> next = newIteam;
	


}
void add_after(Node *beg, char pivot, char ch)
{
	Node *temp = beg;
	while (temp->val != pivot)
	{
		temp = temp->next;
	}
	Node * newIteam = new Node; newIteam->val = ch;
	newIteam->next = temp->next;
	temp->next = newIteam;

}

int main()
{


	system("pause");
    return 0;
}

 