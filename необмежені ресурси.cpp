// необмежені ресурси.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include <conio.h>
using namespace std;


int main()
{
	float  prize=0, pay=0;
	cout << "Prize :";
	cin >> prize;
	cout << "Pay:";
	cin >> pay;
	if (pay < prize)
	{
		cout << "You should pay more\n";
		_getch();
		return 0;
	}
   float p = pay - prize;
   float a[] = { 500.0,200.0,100.0,50.0,20.0,10.0,5.0,2.0,1.0,0.5,0.25,0.1,0.05,0.02,0.01};
	
	for (int i = 0; p !=0.0 && i<15;i++)
	{
		while ((p - a[i]) >=0.0)
		{
	
			cout << a[i] << "\n";
			p -= a[i];
		 }
	}
	_getch();
    return 0;
}

