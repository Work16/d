// �����.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include <conio.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int  rubley;
	cout << "���������� ������:";
	cin >> rubley;
	cout << "\n\n";
	if (rubley < 0)
	{
		cout << "\t�� ����� ������������� ���������� �����!\n";
		_getch();
		return -1;
	}
	if ((rubley % 100) >= 11 && (rubley % 100) <= 19)
		cout << "\t � ��� " << rubley << "������!\n";
	if ((rubley % 10) == 1)
		cout << "\t � ��� " << rubley << "�����!\n";
	else if ((rubley % 10) >= 2 && (rubley % 10) <= 4)
		cout << "\t � ���" << rubley << "�����!\n";
	else
		cout << "\t � ��� " << rubley << "������!\n";
		_getch();
    return 0;
}

