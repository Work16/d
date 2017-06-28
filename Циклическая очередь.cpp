// Циклическая очередь.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;



bool empty(int head ,int tail)
{
	return head == tail;
}


void add(int head, int tail, int x, int size,int *a)
{
	if (size > 10)
		cout << "Steck is overflow!!!";
	else
	{
		size++;
		if (empty(head, tail))
		{
			a[tail] = x;
			tail = tail + 1;
          }
		else
		{
			a[head] = x;
			head = tail;
		}
	}
}


void show(int head, int tail, int size, int *a)
{
	if (empty(head, tail))
	{
		cout << a[head] << "\n";
		head = head - 1;
	}
	else cout << "Steck is empty!!!";
}

int main()
{
	int size=0;
	int a[10];
	int tail=0;
	int head = tail;
	for (int i = 0;i < 10;i++)
	{
		int n;
		cout << "n=";
		cin >> n;
		add(head, tail, i + 1, size, a);
	}
	for (int i = 0;i < 10;i++)
	{
		show(head, tail, size, a);
	}
	system("pause");
    return 0;
}

