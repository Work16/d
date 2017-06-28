// лаб3,4.cpp : Defines the entry point for the console application.
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
		temp->next = NULL;
		beg = temp;
	}
	else
	{
		list *temp = new list;
		temp->value = a;
		temp->next = beg;
		beg = temp;
	}
}


void print(list *beg)
{
	/*if (beg)
	{
	list *temp = beg;
	cout << beg->value << " ";
	temp = temp->next;
	while (temp != beg)
	{
	cout << temp->value << " ";
	temp = temp->next;
	}
	cout << "***\n";
	}*/
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

int searchmax(list *&beg, int &max, int max2, bool flag)
{
	if (flag = false)
	{
		max = beg->value;
		list *t = beg;
		while (t)
		{
			if (t->value> max)
				max = t->value;
			t = t->next;
		}
	}
	else
	{
		if (!beg)
			return max;
		if (beg)
		{
			if (!beg->next)
			{
				if (beg->value != max2)
				{
					max = beg->value;
					return max;
				}
				beg->value = 0;
				return max;
			}
			if (beg->value == max2)
			{
				list *temp = beg->next;
				delete beg;
				beg = temp;
			}
			max = beg->value;
			list *tem = beg;
			while (tem)
			{
				if (tem->next && tem->next->value == max2)

				{
					if (tem->next->next)
					{
						beg = tem;
						beg->next = beg->next->next;
					}
					else
						beg->next = NULL;
				}
				if (tem->value > max)
					max = tem->value;
				tem = tem->next;
			}
		}
	}
	return max;
}

void sort(int *&a, int n)
{
	bool flag = false;
	int t = sqrt(n);
	list **l = new list *[t];
	for (int i = 0;i < t;i++)
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

	while (n)
	{
		//max2 = -155;
		for (int i = 0;i < t;i++)
			max[i] = 0;

		for (int i = 0;i < t;i++)
		{

				if (max3 == i)
			flag = true;
			searchmax(l[i], max[i], max2, flag);
		}
		flag = false;
		max2 = -155;
		for (int i = 0;i < t;i++)
		{
			if (max2 < max[i])
			{
				max2 = max[i];
				max3 = i;
			}
		}
	a[n-1] = max2;
	n--;

	}

	for (int i = 0;i < t;i++)
		del(l[i]);
	delete[] max;
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
		cout << a[i] << endl;
	cout << "\n******************\n";
	sort(a, n);
	for (int i = 0;i < n;i++)
		cout << a[i] <<endl;
	cout << endl;
	system("pause");
    return 0;
}

