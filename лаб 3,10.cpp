// лаб 3,10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
struct list
{
	int value;
	list *next;
};


void builder(list *&beg, int a)
{

	if (!beg)
	{
		list *temp = new list;
		temp->value = a;
		temp->next = temp;
		beg = temp;
	}
	else
	{
		list *temp = new list;
		temp->value = a;
		temp->next = beg;
		beg->next = temp;
	}
}


void print(list *beg)
{
	while (beg)
	{
		cout << beg->value << " ";
		beg = beg->next;
	}
	cout << endl;
}

void del(list *&beg)
{
	while (beg)
	{
		list *temp = beg->next;
		delete beg;
		beg = temp;
	}
}

void searchmax(list *&beg,int &max,int max2,int flag,int t)
{

	/*if (flag == false)
	{
		while (t)
		{
			if (beg->value < max)
				max = beg->value;
			beg = beg->next;
			t--;
		}
	}
	else
	{*/
	if (beg)
	{
		if (beg->value == max2)
			beg = beg->next;
		while (t)
		{
			if (beg->next->value == max2)
				beg->next = beg->next->next;
			//t--;

			if (beg->value < max)
				max = beg->value;
			beg = beg->next;
			t--;
		}
	}
	//}
}

void sort(int *&a, int n)
{
	bool flag = false;
	int t = sqrt(n);
	list **l = new list *[t+1];
	for (int i = 0;i < t+1;i++)
		l[i] = NULL;
	int j = 0, k = 0, z = n, max2 = -1, max3 = -1;
	while (z)
	{
		if (k == t)
		{
			j++;k = 0;
		}
		else
		{
			k++;
		}
		builder(l[j], a[z - 1]);
		z--;
	}
	int *max = new int[t];
	int f= 0;
	while (f<n)
	{
		for (int i =0;i < t;i++)
			max[i] = 123456789;
		for (int i = 0;i < t;i++)
		{
			if (max3 == i)
				flag = true;
				searchmax(l[i], max[i], max2, flag,t);
			}
		flag = false;
		for (int i = 0;i < t;i++)
		{
			if (max[i]< max[i++])
			{
				max2 = max[i];
				max3 = i;
			}
			else
			{
				max2 = max[i++];
				max3 = i++;
			}
		}
		a[f] = max2;
			f++;
	}
	
}


int main()
{
	int n;
	cout << "Enter n:";
	cin >> n;
	int *a = new int[n];
	for (int i = 0;i < n;i++)
		a[i] = fabs(rand());
	for (int i = 0;i < n;i++)
		cout << a[i] << " ";
	cout << "\n******************\n";
	sort(a, n);
	for (int i = 0;i < n;i++)
		cout << a[i] << " ";
	cout << endl;
	system("pause");
	return 0;
}





