// лаб3,2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
const int n = 4;


int main()
{
	int a[n], y = -1, mins = 0;
for (int i = 0;i <n;i++)
	a[i] = fabs(rand());
int t = sqrt(n);
int **p = new int *[t];
for (int i = 0;i < t;i++)
	p[i] = new int[t];
int *min;
min = new int[t];

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
while (y<n)
{
	mins = 123456789;
	for (int i = 0;i < t;i++)
		min[i] = 0;
	y++;
	for (int i = 0;i < t;i++)
		for (int j = 0;j<t;j++)
			if (p[i][j]<min[i])
			{
				min[i] = p[i][j];
				//p[i][j] = 0;
			}


	for (int i = 0;i < t;i++)
		if (min[i]<mins)
			mins = min[i];
	a[y] = mins;
	for (int i = 0;i < t;i++)
		for (int j = 0;j < t;j++)
		{
			if (p[i][j] == mins)
				p[i][j] = 0;
		}
}
for (int i = 0;i < n;i++)
	cout << a[i] << endl;
delete[] min;
for (int i = 0;i < t;i++)
	delete[] p[i];
delete[] p;
system("pause");
return 0;
}

