// лаб3,1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;



int main()
{
	const int n =36;
	int a[n], y = n, maxs = 0;
	for (int i = 0;i <n;i++)
		a[i] = fabs(rand());
	int t = sqrt(n);
	int **p= new int *[t];
	for (int i = 0;i < t;i++)
		p[i] = new int [t];
	int *max;
	max = new int[t];
	
	int i = 0;
	for (int j = 0;j < t;j++)
		for (int k = 0;k < t;k++)
		{
			p[k][j] = a[i];
			i++;
		}
	for (int j = 0;j < t;j++)
		for (int k = 0;k < t;k++)
			cout << p[k][j] << endl;
	cout << "***\n";
	while (y)
	{
		maxs = 0;
		for (int i = 0;i < t;i++)
			max[i] = 0;
		y--;
		for (int i = 0;i < t;i++)
			for (int j = 0;j<t;j++)
				if (p[i][j]>max[i])
				{
					max[i] = p[i][j];
					//p[i][j] = 0;
			}		

		for (int i = 0;i < t;i++)
			if (max[i]>maxs)
				maxs = max[i];
		a[y] = maxs;
		for (int i = 0;i < t;i++)
			for (int j = 0;j < t;j++)
			{
				if (p[i][j] == maxs)
				p[i][j] = 0;
			}
	}
	for (int i = 0;i < n;i++)
		cout << a[i] << endl;
	delete[] max;
	for (int i = 0;i < t;i++)
		delete[] p[i];
	delete[] p;
	system("pause");
    return 0;
}

