// ��� �����.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include <conio.h>
using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");
	int p1, p2, s1, s2;
	cout << "p1=";
	cin >> p1;
	cout << "p2=";
	cin >> p2;
	cout << "s1=";
	cin >> s1;
	cout << "s2=";
	cin >> s2;
	
		
			if (s1 < p1 && s2 < p2)
			{
				cout << 1;
				if (s1 + 2 == p1 && s2 + 1 == p2)
				{
					cout << "��� ���� 1"<< endl;
				}
				if (s1 + 1 == p1 && s2 + 2 == p2)
				{
					cout << "��� ���� 2" << endl;
				}
				else
				{
					cout << "��� ���� 9" << endl;
				}
			}
			if (s1 < p1 && s2 > p2)
			{
				cout << 2;
				if (s1 + 2 == p1 && s2 - 1)
				{
					cout << "��� ���� 3" << endl;
				}
				if (s1 + 1 == p1 && s2 - 2 == p2)
				{
					cout << "��� ���� 4" << endl;
				}
				else
				{
					cout << "��� ���� 9" << endl;
				}
			}
			if (s1 > p1 && s2 > p2)
			{
				cout << 3;
				if (s1 - 2 == p1 && s2 - 1 == p2)
				{
					cout << "��� ���� 5" << endl;
				}
				if (s1 - 1 == p1 && s2 - 2 == p2)
				{
					cout << "��� ���� 6" << endl;
				}
				else
				{
					cout << "��� ���� 9" << endl;
				}

			}
			if (s1 > p1 && s2 <p2)
			{
				cout << 4;
				if (s1 - 2 == p1 && s2 + 1 == p2)
				{
					cout << "��� ���� 7" << endl;
				}
				if (s1-1==p1 && s2+2==p2)
				{
					cout << "��� ���� 8" << endl;
				}
				else
				{
					cout << "��� ���� 9" << endl;
				}
			}
			else
			{
				cout << "��� ���� 9" << endl;
			}
		
	
	_getch();
    return 0;
}

