// лаб3,3.cpp : Defines the entry point for the console application.
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
		temp->next  =NULL;
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

int searchmax(list *&beg,int &max,int &max2,bool flag)
{
	/*if (beg)
	{
		if (!beg->next && beg->value != max2)
		{
			max = beg->value;
			return max;
		}
		else if (beg->value == max2)
			return max;
		else
		{
			if (flag == false)
			{
				max = beg->value;
				list *temp = beg->next;
				while (temp)
				{
					if (temp->value > max)
						max = temp->value;
					temp = temp->next;
				}
			}
			else
			{
				/*if (beg->value != max2)
					max = beg->value;
				else if (beg->next)
					max = beg->next->value;
					list *temp = beg->next;
					if (beg->value == max2)
					{
						list * t = beg->next;
						delete beg;
						beg = t;
					}
					if (temp->value == max2)
					{
						list *t = temp->next;
						delete temp;
						temp = t;
					}
					while (temp != beg)
					{
						if (temp->next->value == max2)
						{
							list *t = temp->next->next;
							delete temp->next;
							temp->next = t;
						}
						if (temp->value > max)
							max = temp->value;

						temp = temp->next;
					}
				}*/
				/*if (beg->value != max2)
					max = beg->value;
				else
					max = beg->next->value;
				while (beg)
				{
					/*if (beg->next->value == max2)
					{
						beg->next = beg->next->next;
					}
					if (beg->value == max2)
					{
						list *t = beg->next;
						delete beg;
						beg = t;
					}
					if (beg->value > max)
						max = beg->value;
					beg = beg->next;*/


			/*	if (beg->value == max2)
				{
					if (beg->next)
						max = beg->next->value;
					list *t = beg->next;
					delete beg;
					beg = t;
				}
				else
					max = beg->value;
				//list * temp = beg->next;
				//beg = beg->next;
				while (beg && beg->next)
				{
					if (beg->next->next && beg->next->next->value == max2)
					{
						list *t = beg->next->next->next;
						delete beg->next->next;
						beg = t;
					}
					if (beg->next->value > max)
						max = beg->next->value;
					beg->next = beg->next->next;
				}
			}
		}
	}*/


if (beg)
{
	if (!beg->next)
	{
		if (beg->value != max2)
		{
			max = beg->value;
			return max;
		}
		else
			return max;
	}
	else
	{
		if (beg->value == max2)
		{
			list *t = beg->next;
			delete beg;
			beg = t;
		}
			max = beg->value;
		while (beg)
		{
			if (beg->value > max)
				max = beg->value;
			beg = beg->next;
		}
		return max;
	}
}
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



	while (n && j<t)
	{
		for (int i = 0;i < t;i++)
			max[i] = 0;

		for (int i = 0;i < t;i++)
		{
			//max2 = 0;
			if (max3 == i)
				flag = true;
			searchmax(l[i], max[i], max2, flag);
		}
		flag = false;
		max2 =-155;
		for (int i = 0;i < t;i++)
		{
			if (max2 < max[i])
			{
				max2 = max[i];
				max3 = i;
			}
			/*	else
				{
					max2 = max[i];
					max3 = i;
				}
			}*/
		}
			a[n ] = max2;
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
		cout << a[i] << " ";
	cout << "\n******************\n";
	sort(a, n);
	for (int i = 0;i < n;i++)
		cout << a[i] << " ";
	cout << endl;
	system("pause");
    return 0;
}

