// Квадратическая сортировка.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


void sort(int *p,int n)
{
	for (int i = 0;i < n;i++)
		cin >> p[i];
	int t = sqrt(n);
	int *min;
	min = new int[t];
	int j = 0,min2=159,minj;
	int *l;
	l = new int[t];
	int k = 0;
	while (n)
	{
		min2 = 159;
		for (int i = 0;i < t;i++)
			min[t] = 357;
		for (int j = 0;j < t;j++)
		{
			for (int i = j;i < t && p[i];i++)
			{
				if (p[i] < min[j])
					min[j] = p[i];
			}
			for (int i = 0;i < t;i++)
				if (min[i] < min2)
				{
					min2 = min[i];
					minj = i;
				}
			l[k] = min2;
			k++;
			for (int i = minj*t;i < n;i++)
			{
				p[i] = p[i++];
				n--;
				t--;
			}
		}
}
	for (int i = 0;i < n;i++)
		cout << l[i] << endl;
}


int main()
{
	int *p;
	int n;
	cout << " n=";
	cin >> n;
	p = new int[n];
	sort(p,n);
	system("pause");
    return 0;
}

