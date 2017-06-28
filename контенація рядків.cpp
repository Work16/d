// контенація рядків.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include <conio.h>
using namespace std;


int main()
{
	char a[256], b[256];
	cout << "a:";
	cin.getline(a, 256);
	cout << "b:";
	cin.getline(b, 256);
	cout << "***\n";
	for (int i = 0;i<512;i++)
	{
		
			if (a[i] == '\0')
			{
				for (int j = 0;j < 256;j++)
				{
					a[i] = b[j];
					
				}
			
		}
	}
	for (int i = 0;i < 512;i++)
	{
		cout << a[i];
	}
	_getch();
    return 0;
}

