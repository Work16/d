// лаба1.Бинарный файл .База данных.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int exit()
{
	return -1;
}

struct adress
{
	char street[45];
	int number;
};

struct dat
{
	int day;
	char  month [15];
	int year;
} ;

struct book

{
	int n;
	char name[30];

	adress place;
	dat birth;
	char email[30];
   char statys[30];
};


void builder()
{
	book test[11];

	char str0[] = "ФИО";
	strcpy_s(test[0].name, str0);
	char str1[] = "Сопун";
	strcpy_s(test[1].name, str1);
	char str2[] = "Федоров";
	strcpy_s(test[2].name, str2);
	char str3[] = "Николаев";
	strcpy_s(test[3].name, str3);
	char str4[] = "Шаповалов";
	strcpy_s(test[4].name, str4);
	char str5[] = "Коперников";
	strcpy_s(test[5].name, str5);
	char str6[] = "Волошкин";
	strcpy_s(test[6].name, str6);
	char str7[] = "Колокольников";
	strcpy_s(test[7].name, str7);
	char str8[] = "Дол";
	strcpy_s(test[8].name, str8);
	char str9[] = "Кац";
	strcpy_s(test[9].name, str9);
	char str10[] = "Щукин";
	strcpy_s(test[10].name, str10);
	char ad0[] = "Адрес";
	strcpy_s(test[0].place.street, ad0);
	test[0].place.number = 0;
	char ad1[] = "Нижний Вал";
	strcpy_s(test[1].place.street, ad1);
	test[1].place.number = 10;
	char ad2[] = "Верхний Вал";
	strcpy_s(test[2].place.street, ad2);
	test[2].place.number = 21;
	char ad3[] = "Ярославская";
	strcpy_s(test[3].place.street, ad3);
	test[3].place.number = 36;
	char ad4[] = "Правды";
	strcpy_s(test[4].place.street, ad4);
	test[4].place.number = 2;
	char ad5[] = "Свободы";
	strcpy_s(test[5].place.street, ad5);
	test[5].place.number = 4;
	char ad6[] = "Межевая";
	strcpy_s(test[6].place.street, ad6);
	test[6].place.number = 17;
	char ad7[] = "Гонгадзе";
	strcpy_s(test[7].place.street, ad7);
	test[7].place.number = 8;
	char ad8[] = "Васильковская";
	strcpy_s(test[8].place.street, ad8);
	test[8].place.number = 60;
	char ad9[] = "Владимирская";
	strcpy_s(test[9].place.street, ad9);
	test[9].place.number = 25;
	char ad10[] = "Маяковская";
	strcpy_s(test[10].place.street, ad10);
	test[10].place.number = 14;
	char b0[] = "День Рождения";
	strcpy_s(test[0].birth.month, b0);
	test[0].birth.day = 0;
	test[0].birth.year = 0;
	for (int i = 1;i < 11;i++)
	{
		test[i].birth.day = i;
	}
	char b1[] = "сентября";
	strcpy_s(test[1].birth.month, b1);
	test[1].birth.year = 1998;
	char b2[] = "августа";
	strcpy_s(test[2].birth.month, b2);
	test[2].birth.year = 1976;
	char b3[] = "января";
	strcpy_s(test[3].birth.month, b3);
	test[3].birth.year = 1963;
	char b4[] = "декабря";
	strcpy_s(test[4].birth.month, b4);
	test[4].birth.year = 1999;
	char b5[] = "июня";
	strcpy_s(test[5].birth.month, b5);
	test[5].birth.year = 1978;
	char b6[] = "июля";
	strcpy_s(test[6].birth.month, b6);
	test[6].birth.year = 1987;
	char b7[] = "ноября";
	strcpy_s(test[7].birth.month, b7);
	test[7].birth.year = 1974;
	char b8[] = "марта";
	strcpy_s(test[8].birth.month, b8);
	test[8].birth.year = 1968;
	char b9[] = "мая";
	strcpy_s(test[9].birth.month, b9);
	test[9].birth.year = 1997;
	char b10[] = "апреля";
	strcpy_s(test[10].birth.month, b10);
	test[10].birth.year = 2000;
	char s0[] = "Статус";
	strcpy_s(test[0].statys, s0);
	char s1[] = "друг";
	strcpy_s(test[1].statys, s1);
	char s2[] = "колега";
	strcpy_s(test[2].statys, s2);
	char s3[] = "родственик";
	strcpy_s(test[3].statys, s3);
	strcpy_s(test[4].statys, s1);
	strcpy_s(test[5].statys, s2);
	strcpy_s(test[6].statys, s3);
	strcpy_s(test[7].statys, s1);
	strcpy_s(test[8].statys, s2);
	strcpy_s(test[9].statys, s3);
	strcpy_s(test[10].statys, s1);
	char e0[] = "email";
	strcpy_s(test[0].email, e0);
	char e1[] = "a.gmail";
	strcpy_s(test[1].email, e1);
	char e2[] = "b.gmail";
	strcpy_s(test[2].email, e2);
	char e3[] = "c.gmail";
	strcpy_s(test[3].email, e3);
	char e4[] = "d.gmail";
	strcpy_s(test[4].email, e4);
	char e5[] = "f.gmail";
	strcpy_s(test[5].email, e5);
	char e6[] = "g.gmail";
	strcpy_s(test[6].email, e6);
	char e7[] = "h.gmail";
	strcpy_s(test[7].email, e7);
	char e8[] = "j.gmail";
	strcpy_s(test[8].email, e8);
	char e9[] = "i.gmail";
	strcpy_s(test[9].email, e9);
	char e10[] = "o.gmail";
	strcpy_s(test[10].email, e10);
	for (int i = 0;i < 11;i++)
		test[i].n = i;
	/*
	frewite &test, sizeof test 1
	*/

	FILE *f;
	fopen_s(&f, "D:\\1", "w+b");
	if (f == NULL)
	{
		printf("не удается открыть файл\n");
		fclose(f);
	}
	else
	{

		//	int o000 = fwrite(&test[0], sizeof(book), 11, f);
		//book test22[11];
		//int ppp = fseek(f, 0, SEEK_SET);
		//fclose(f);
		//fopen_s(&f, "D:\\1", "rb");

		//int qqq = fread(&test22[0], sizeof(book), 11, f);
		//cout << test22[0].name<< endl;
		for (int i = 0;i < 11;i++)
		{
			fwrite(&test[i], sizeof(book), 1, f);
		}
	}
	fclose(f);
}
	/*
	frewite &test, sizeof test 1
	*/

		FILE *f;
		fopen_s(&f, "D:\\1", "w+b");
	if (f == NULL)
	{
		printf("не удается открыть файл\n");
		fclose(f);
	}
	else
	{
		
	//	int o000 = fwrite(&test[0], sizeof(book), 11, f);
		//book test22[11];
		//int ppp = fseek(f, 0, SEEK_SET);
		//fclose(f);
		//fopen_s(&f, "D:\\1", "rb");
		
		//int qqq = fread(&test22[0], sizeof(book), 11, f);
		//cout << test22[0].name<< endl;
		for (int i = 0;i < 11;i++)
		{
			fwrite(&test[i], sizeof(book), 1, f);
		}
	}
	fclose(f);
}
void print ()
{
	book test [11];
	FILE *f;
	fopen_s(&f, "D:\\1", "rb");
	if (f == NULL)
	{
		printf("не удается открыть файл\n");
		fclose(f);
	}
	else
	{
		/*int i = 0;
		while (fread(&test[i], sizeof(book), 11, f) != EOF)
		{
			
			
			cout << test[i].name << " "
				<< test[i].place.street << test[i].place.number << " "
				<< test[i].birth.day << test[i].birth.month << test[i].birth.year << " "
				<< test[i].email << " "
				<< test[i].statys << "\n";
			i++;
		}*/
		for (int i = 0;i < 11;i++)
		{

			fread(&test, sizeof(book), 1, f);
			/*if (i == 0)
			{

				for (int j = 0;j < 5;j++)
					cout << " ";
				cout << test[i].name;
				for (int j = 0;j < 15 - strlen(test[i].name);j++)
					cout << " ";
				cout << test[i].place.street;
				for (int j = 0;j < 15 - strlen(test[i].place.street);j++)
					cout << " ";
				cout << test[i].birth.month;
				for (int j = 0;j < 15 - strlen(test[i].birth.month);j++)
					cout << " ";
				cout << test[i].email;
				for (int j = 0;j < 15 - strlen(test[i].email);j++)
					cout << " ";
				cout << test[i].statys << "\n";

			}
			cout << test[i].n;
			for (int j = 0;j< 5 - sizeof(test[i].n);j++)
				cout << " ";
			cout << test[i].name;
			for (int j = 0;j < 15 - strlen(test[i].name);j++)
				cout << " ";
			cout << test[i].place.street << " " << test[i].place.number;
			for (int j = 0;j< 14- sizeof (test[i].place);j++)
				cout << " ";
			cout << test[i].birth.day << " " << test[i].birth.month << " " << test[i].birth.year;
			for (int j=0;j < 13 - sizeof(test[i].birth);j++)
				cout << " ";
			cout << test[i].email;
			for (int j = 0;j <15 - strlen(test[i].email);j++)
				cout << " ";
			cout << test[i].statys << "\n";*/
		
		if (i == 0)
	{
		cout << test[i].name << "|| "
			<< test[i].place.street  << "|| "
			 << test[i].birth.month << "|| "
			<< test[i].email << "|| "
			<< test[i].statys << "\n";
	}
	else
	{
		cout << test[i].name << " ||"
			<< test[i].place.street << test[i].place.number << "|| "
			<< test[i].birth.day << test[i].birth.month << test[i].birth.year << "|| "
			<< test[i].email << "|| "
			<< test[i].statys << "\n";
	}
}
		}
			fclose(f);
		
	}
}
int main()
{
	setlocale(LC_ALL, "Russian");
	 builder();
	
	menu:
	cout << "*** Телефонна книга ***\n";
	int a;
	int q;
	cout << "1.Просмотреть книгу\n"
		<< "2.Добавить контакт \n"
		<< "3.Редагувати \n"
		<< "4.Поиск\n"
		<< "5.Сортировать\n"
		<< "6.Выход\n";
	cout << "Ваш вибор:";
	cin >> a;
	switch (a - 1)
	{
	case 0: {print();; break;}
	case 1: { /*adding();*/break; }
	case 2: 
	{menu1:
		system("cls");
		cout << "1.ФИО\n"
			<< "2.Адрес\n"
			<< "3.Email\n"
			<< "4.Дату рождения\n"
			<< "5.Статус\n"
			<< "6.Выход\n";
		cout << "Ваш выбор:\n";
		cin >> q;
		switch (q - 1)
		{
		case 0: { /*redact1()*/;break; }
		case 1: {/* redact2()*/;break;}
		case 2: { /*redact3()*/;break;}
		case 3: {/*redact4()*/;break;}
		case 4: {/* redact5()*/;break;}
		case 5: {exit();break;}
		default: {
			goto menu1;
		}
		}
	}
	case 3 :{menu2:
		system("cls");
		cout << "1.ФИО\n"
			<< "2.Адрес\n"
			<< "3.Email\n"
			<< "4.Дату рождения\n"
			<< "5.Статус\n"
			<< "6.Выход\n";
		cout << "Ваш выбор:\n";
		cin >> q;
		switch (q - 1)
		{
		case 0: { /*search1()*/;break;}
		case 1: {/*search2()*/;break;}
		case 2: {/*search3()*/;break;}
		case 3: {/*search4()*/;break;}
		case 4: {/*search5()*/;break;}
		case 5: {exit();break;}
		default: {goto menu2;}
		}
	}
	case 4: {/*sorting()*/;break;}
	case 5: {exit();break;}
	default: { system("cls");
		goto menu;}
	}
    return 0;
}

