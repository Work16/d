// ����.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

void print_base()
{
	cout << "\nprint\n";
}
void sort_base()
{
	cout << "\nsort\n";
}

void find()
{
	cout << "\nfind\n";
}
 
void remove_data()
{
	cout << "\nremove\n";
}

void   exit()
{
	
}


int main()
{
	setlocale(LC_ALL, "Russian");
		std::cout << "�����������, ��� ������������ ��������� ��� ���������� �� ������� ���������\n";

		while (true)
		{
			//������ ���������� �� ������� - ������ ����
			void(*options[])() = { print_base,
				sort_base,
				find,
				remove_data,
				exit };

			std::cout << "�������� ��������:\n\
                     1. ����������� ���� ������\n\
                     2. ������� �� ����� ���������� ���� ������\n\
                     3. ������������� ����\n\
                     4. ����� � ����\n\
                     5. ����� �� ���������\n > ";
			unsigned choise;
			std::cin >> choise;

			//��������� ����� �� "������������"
			if (choise < 0)
			{
				std::cout << "�������� �����!\n";
			}
			else
			{
				//���� ����� ����������, �������� �������������� �����
				options[choise -1]();
			}
			system("pause");
			system("cls");
		}
		system("pause");
    return 0;
}

