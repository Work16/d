// порівняння рядків.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include <conio.h>
using namespace std;


int main()
{
	char a[256],b[256];
	cout << "a:";
	cin >> a;
	cout << "b:";
	cin >> b;
	for (int i = 0;i < 256;i++)
	{
		if (a[i] == b[i])
		{
			cout << "0\n";

		}
		else {
			cout << "-1\n";
			_getch();
			return -1;
		}
	}
		/*if (a[i] == '\0' && b[i] != '\0')
		{
			cout << "-1\n";
			
		}
		if (a[i] != '\0' && b[i] == '\0')
		{
			cout << "1\n";
			
		}
		else {
			cout << "0\n";
		}*/
	//}
	_getch();
    return 0;
}

