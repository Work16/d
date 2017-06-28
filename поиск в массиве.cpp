// поиск в массиве.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include <conio.h>
using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "\t\t поиск в массиве \n\n";
	const int n = 5;
	int u=0;
	int a[n];
	for (int i = 0;i < n;i++)
	{
		a[i] = rand();
		cout << a[i]<< endl;
	}
	int g;
	cout << "¬ведите ваше значение :";
	cin >> g;
	for (int i = 0;i < n;i++)
	{
		if (a[i] == g)
		{
			u++;
			cout << "¬аше значение найдено под индексом " << i << "\n";
		}
			
	}
	if (u == 0)
		cout << "¬аше значение не найдено!\n" << -1<<endl;

	
	_getch();
    return 0;
}

