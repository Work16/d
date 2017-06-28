// меню.cpp : Defines the entry point for the console application.
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
		std::cout << "Здравсвуйте, вас приветствует программа для управления БД сотовых телефонов\n";

		while (true)
		{
			//Массив указателей на функции - пункты меню
			void(*options[])() = { print_base,
				sort_base,
				find,
				remove_data,
				exit };

			std::cout << "Выберите действие:\n\
                     1. Просмотреть базу данных\n\
                     2. Вывести на экран содержимое базы данных\n\
                     3. Отсортировать базу\n\
                     4. Поиск в базе\n\
                     5. Выход из программы\n > ";
			unsigned choise;
			std::cin >> choise;

			//Проверяем выбор на "правильность"
			if (choise < 0)
			{
				std::cout << "Неверный выбор!\n";
			}
			else
			{
				//Если выбор правильный, вызываем соответсвующий пункт
				options[choise -1]();
			}
			system("pause");
			system("cls");
		}
		system("pause");
    return 0;
}

