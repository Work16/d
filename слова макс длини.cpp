// слова макс длини.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include <conio.h>
using namespace std;

int main()
{
	char s[256];
	int count = 0, max = 0;
	cout << "s:";
	cin.getline(s, 256);
	cout << endl << endl;
			for (int i = 0;s[i] != '\0';i++)
		{
 	     if (s[i] == ' ')
{
	     if (count > max)
	{
		max = count;
	}
	i = count + 1;
	count = 0;
}

			if (s[i] != ' ')
			{
				count++;
			}
			
		}
    cout << max ;
	_getch();
	return 0;
}

