// контенація рдків.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include <conio.h>
using namespace std;


int main()
{
	char a[25], b[25];
	cout << "a:";
	cin.getline(a, 25);
	//cout << a;
	cout << "b:";
	cin.getline(b, 25);
	//cout << b;
	for (int i = 0;i < 25;i++)
	{
		if (a[i] == '\0')
		{
			for (int j = 0;j < 25-i  ;j++ && i++  )
			{
				a[i] = b[j];
				if (b[j] == '\0')
				{
					a[i] = b[j];
					j = 25-i;
				}
			}
		}
	}
	cout << a;
	_getch();
    return 0;
}

