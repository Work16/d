// лаб 1 телефонная книга.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

#define FIELD_NAME 0
#define FIELD_STREET 1
#define FIELD_NUMBER 2
#define FIELD_DAY 3
#define FIELD_MONTH 4
#define FIELD_YEAR 5
#define FIELD_EMAIL 6
#define FIELD_STATYS 7


void builder();
void print();
void add();
void delet();
void search_1();
void search_2();
void search_3();
void search_4();
void number();
void conclusion();
int field();
void edit(int k, int field);
void exit_s();


struct adress
{
	char street[30];
	int number;
};

struct dat
{
	int day;
	char  month [10];
	int year;
} ;

 struct book

{
	int n;
	char name[25];

	adress place;
	dat birth;
	char email[10];
   char statys[15];
} ;

void conclusion();


int main()
{
	builder();
	int a;
	char e;
menu :
	system("cls");
	cout << "1.watch\n2.add\n3.delete\n4.search\n5.edit\n6.conlusion\n7.exit\n";
	cin >> a;
	switch (a - 1)
	{
	case 0: 
	{
		system("cls");
		print();
		goto menu;
	}
	case 1 : 
	{
		system("cls");
		add();
		goto menu;
	}
	case 2: 
	{
		system("cls");
		delet();
		goto menu;
	}
	case 3:
	{
		menu1:
		cout << "a.Month\nb.Name\nc.statys\nf.year\n";
		cin >> e;
		switch (e)
		{
		case 'a':
		{
			system("cls");
			search_1();
			system("pause");
			goto menu;
		}
		case 'b':
		{
			system("cls");
			search_2();
			system("pause");
			goto menu;
		}
		case 'c':
		{
			system("cls");
			search_3();
			system("pause");
			goto menu;
		}
		case 'f' :
		{
			system("cls");
			search_3();
			system("pause");
			goto menu;
		}
		default : { goto menu1;}
		}
	}
	case 4:
	{
	menu2:
		int k;
		cout << "Enter the number of editing contact:\n";
		cin >> k;

		int f = field();
		if( f == -1 )
			goto menu2;
		edit(k, f);
		goto menu;
	}
	case 5:
	{
		system("cls");
		conclusion();
		system("pause");
		goto menu;
	}
	case 6:
	{
		exit_s();
	}
	default: {goto menu;}
	}
	system("pause");
    return 0;
}
int field()
{
	char e;
	char s;
	cout << "a.Name\nb.Adress\nc.Birth\nf.email\ng.statys\n";
	cin >> e;
	system("cls");


	switch (e)
	{
	case 'a':
	{
		return FIELD_NAME;
	}
	case 'b':
	{

		cout << "1.Street\n2.Number";
		cin >> s;
		system("cls");
		switch (s) {
		case '1':
			return FIELD_STREET;
		case '2':
			return FIELD_NUMBER;
		default:
			return -1;
		}
	}
	case 'c':
	{

		cout << "1.Day\n2.Month\n3.Year";
		cin >> s;
		system("cls");
		switch (s) {
		case '1':
			return FIELD_DAY;
		case '2':
			return FIELD_MONTH;
		case '3':
			return FIELD_YEAR;
		default:
			return -1;
		}
	}
	case 'f':
	{
		return FIELD_EMAIL;
	}
	case 'g':
	{
		return FIELD_STATYS;
	}
	}
	return -1;
}


void builder()
{
	
	
	/*
	frewite &test, sizeof test 1
	*/

	

book test[10] =
	 {
		1,"Sopyn", "Lomonosova", 25, 4, "aprill",1987, "a.gmail", "friend",
			2,"Petrov", "Mezevay", 3, 8, "march",1998, "b.gmail", "collegue",
			3,"Sidorov" , "Radyznay" ,14 ,6,"december" ,2000,"c.gmail","neighboor",
			4,"Kylikov","Gongadze" ,8,16,"february",1897,"d.gmail","relative",
			5,"Morozov","Vasylkivska",60,5,"may",1999,"f.gmail","friend",
			6,"Malysheva","Maykovskovo",14,9,"march",1965,"h.gmail","collegue",
			7,"Martynova","Vladimirskay",25,28,"june",1997,"o.gmail","friend",
			8,"Yrov","Svoboda",4,17,"august",1999,"u.gmail","collegue",
			9,"Myshkin","Nizniy Val",10,15,"september",1995,"p.gmail","relative",
			10,"Philipova","Yroslavskay",36,20,"november",1974,"s.gmail","friend"
	};
	ofstream out("2",ios::binary);
	if (!out)
	{
		cout << "failed to open halyar\n";
	}
	
		out.write((char*)& test, sizeof(test));

	out.close();
}

void print ()
{
	book test;
	ifstream in;
	in.open("2", ios::binary);
	if (!in) cout << "failed to open halyard\n";
	cout << setw(3) << "  |" << setw(15) << "Name" << setw(15) << "Adress" << setw(20) << "Date of birthday" << setw(10) << "Email|" << setw(10) << "Statys" << endl;
	in.read((char*)& test, sizeof(test));
	while (!in.eof())
	{
		cout << setw(3) << test.n << setw(15) << test.name << setw(15) << test.place.street << test.place.number << setw(5) << test.birth.day << test.birth.month << test.birth.year << setw(15) << test.email << setw(12) << test.statys << endl;
		in.read((char*)&test, sizeof(test));
	}
	in.close();
	system("pause");

}

void add()
{

	book test;
	
	ofstream out("2", ios::binary | ios::app);
		cout << "Enter number of contact:\n";
		
		cin >> test.n;
		cout << "Enter name:\n";
		cin >> test.name;
		cout << "Enter street:\n";
		cin >> test.place.street;
		cout << "Enter the number of the house:\n";
		cin >> test.place.number;
		cout << "Enter day of birthday:\n";
		cin >> test.birth.day;
		cout << "Enter month of birthday:\n";
		cin >> test.birth.month;
		cout << "Enter year of birthday:\n";
		cin >> test.birth.year;
		cout << "Enter email:\n";
		cin >> test.email;;
		cout << "Enter statys:\n";
		cin >> test.statys;
		out.write((char*)&test, sizeof(test));
		//number();

	/*out << test.n;
	out.seekp(sizeof (test.n),ios::beg);
	out << test.fdel;
	out.seekp(sizeof(test.n+test.fdel), ios::beg);
	out << test.name;
	out.seekp(sizeof(test.n + test.fdel + test.name), ios::beg);
	out << test.place.street;
	out.seekp(sizeof(test.n + test.fdel + test.name)+sizeof( test.place.street), ios::beg);
	out << test.place.number;
	out.seekp(sizeof(test.n + test.fdel + test.name) + sizeof(test.place.street+test.place.number), ios::beg);
	out << test.birth.day;
	out.seekp(sizeof(test.n + test.fdel + test.name) + sizeof(test.place.street + test.place.number)+sizeof(test.birth.day), ios::beg);
	out << test.birth.month;
	out.seekp(sizeof(test.n + test.fdel + test.name) + sizeof(test.place.street + test.place.number) + sizeof(test.birth.day+test.birth.month), ios::beg);
	out << test.birth.year;
	out.seekp(sizeof(test.n + test.fdel + test.name) + sizeof(test.place.street + test.place.number) + sizeof(test.birth.day + test.birth.month)+sizeof (test.birth.year), ios::beg);
	out << test.email;
	out.seekp(sizeof(test.n + test.fdel + test.name) + sizeof(test.place.street + test.place.number) + sizeof(test.birth.day + test.birth.month) + sizeof(test.birth.year+test.email), ios::beg);
	out << test.statys;
	out.write((char*)&test, sizeof(test));
	out.close();
	system("pause");*/
}
void delet()
{
	book test;
	int k;
	cout << "Enter the number of deleting contact:\n";
	cin >> k;
	ofstream out;
	out.open("3", ios::binary);
	if (!out) {cout << "failed to open halyard\n";}
	ifstream in;
	in.open("2", ios::binary);
	if (!in) { cout << "failed to open halyard\n"; }
	int i = 0;
	in.read((char*)&test, sizeof(test));
	while (!in.eof())
	{
		
		if (i!=k-1)
		{

				out.write((char*)&test,sizeof(test));
	}
	  i++;
		in.read((char*)&test, sizeof(test));
	}
	in.close();
	out.close();
	remove("2");
	rename("3", "2");
	//number();

	
}

void search_1()
{
	book test;
	ifstream in("2", ios::binary);
	if (!in) { cout << "failed to open halyard \n"; }
    char ch[10];
	cout << "Enter the word for searching:\n";
	cin >> ch;
	//cout << ch;
	cout << setw(3) << "  |" << setw(15) << "Name" << setw(15) << "Adress" << setw(20) << "Date of birthday" << setw(10) << "Email|" << setw(10) << "Statys" << endl;
	in.read((char*)&test, sizeof(test));
	while (!in.eof())
	{
		//cout << ch << endl << test.birth.month << endl;
              if (strcmp(ch,test.birth.month)==0)
				cout << setw(3) << test.n << setw(15) << test.name << setw(15) << test.place.street << test.place.number << setw(5) << test.birth.day << test.birth.month << test.birth.year << setw(15) << test.email << setw(12) << test.statys << endl;
			in.read((char*)&test, sizeof(test));
	}
	in.close();
}
void search_2()
{
	book test;
	ifstream in("2", ios::binary);
	if (!in) { cout << "failed to open halyard \n"; }
	char ch[10];
	cout << "Enter the word for searching:\n";
	cin >> ch;
	//cout << ch;
	cout << setw(3) << "  |" << setw(15) << "Name" << setw(15) << "Adress" << setw(20) << "Date of birthday" << setw(10) << "Email|" << setw(10) << "Statys" << endl;
	in.read((char*)&test, sizeof(test));
	while (!in.eof())
	{
		//cout << ch << endl << test.birth.month << endl;
		if (strcmp(ch, test.name) == 0)
			cout << setw(3) << test.n << setw(15) << test.name << setw(15) << test.place.street << test.place.number << setw(5) << test.birth.day << test.birth.month << test.birth.year << setw(15) << test.email << setw(12) << test.statys << endl;
		in.read((char*)&test, sizeof(test));
	}
	in.close();
}
void search_3()
{
	book test;
	ifstream in("2", ios::binary);
	if (!in) { cout << "failed to open halyard \n"; }
	char ch[10];
	cout << "Enter the word for searching:\n";
	cin >> ch;
	//cout << ch;
	cout << setw(3) << "  |" << setw(15) << "Name" << setw(15) << "Adress" << setw(20) << "Date of birthday" << setw(10) << "Email|" << setw(10) << "Statys" << endl;
	in.read((char*)&test, sizeof(test));
	while (!in.eof())
	{
		//cout << ch << endl << test.birth.month << endl;
		if (strcmp(ch, test.statys) == 0)
			cout << setw(3) << test.n << setw(15) << test.name << setw(15) << test.place.street << test.place.number << setw(5) << test.birth.day << test.birth.month << test.birth.year << setw(15) << test.email << setw(12) << test.statys << endl;
		in.read((char*)&test, sizeof(test));
	}
	in.close();
}
void search_4()
{
	book test;
	int t = 0;
	ifstream in("2", ios::binary);
	if (!in) { cout << "failed to open halyard \n"; }
	cout << "Enter searching year:\n";
	cin >> t;
	in.read((char*)&test, sizeof(test));
	while (!in.eof())
	{
		if (t==test.birth.year)
			cout << setw(3) << test.n << setw(15) << test.name << setw(15) << test.place.street << test.place.number << setw(5) << test.birth.day << test.birth.month << test.birth.year << setw(15) << test.email << setw(12) << test.statys << endl;
		in.read((char*)&test, sizeof(test));
	}
	in.close();
	
}
void conclusion ()
{
	int q=0, k=0, g=0, z=0;
	ifstream in ("2", ios::binary);
	if (!in) cout << "failed to open hardlyard\n";
	book test;
	in.read((char*)& test, sizeof(test));
	while (!in.eof())
	{
		for (int i = 0;i < 1;i++)
		{
			if (test.statys[i] == 'f')q++;
			if (test.statys[i] == 'c') k++;
			if (test.statys[i] == 'r')g++;
			if (test.statys[i]=='n')z++;
		}
		in.read((char*)& test, sizeof(test));
	}
	cout << "You have:\n" << q << " friends\n" << k << " colleagues\n" << g << " relatives\n"<<z<<" neighboors\n";
	
}
void  exit_s()
{
	exit(0);
}
void number()
{
	book test;
	ifstream in("2", ios::binary);
	ofstream out("2", ios::binary);
	if (!in) cout << "failed to open hardlyard\n";
	if (!out) cout << "failed to open hardlyard\n";
	in.read((char*)&test, sizeof(test));
	int i = 0;
	while (in.eof())
	{
		test.n = i + 1;
		i++;
		in.read((char*)&test, sizeof(test));
	}
	out.write((char*)&test, sizeof(test));

}


void edit( int k, int field)
{
	book test;
	ofstream out;
	out.open("3", ios::binary);
	if (!out) { cout << "failed to open halyard\n"; }
	ifstream in;
	in.open("2", ios::binary);
	if (!in) { cout << "failed to open halyard\n"; }
	int i = 0;
	in.read((char*)&test, sizeof(test));
	while (!in.eof())
	{
		if (i != k - 1)
		{
			out.write((char*)&test, sizeof(test));
		}
		else
		{
			switch (field)
			{
				case FIELD_NAME:
					cout << "Enter name:\n";
					cin >> test.name;
				break;
				case FIELD_STREET:
					cout << "Enter street:\n";
					cin >> test.place.street;
				break;
				case FIELD_NUMBER:
					cout << "Enter the number of the house:\n";
					cin >> test.place.number;
				break;
				case FIELD_DAY:
					cout << "Enter day of birthday:\n";
					cin >> test.birth.day;
				break;
				case FIELD_MONTH:
					cout << "Enter month of birthday:\n";
					cin >> test.birth.month;
				break;
				case FIELD_YEAR:
					cout << "Enter year of birthday:\n";
					cin >> test.birth.year;
				break;
				case FIELD_EMAIL:
					cout << "Enter email:\n";
					cin >> test.email;;
				break;
				case FIELD_STATYS:
					cout << "ВEnter statys:\n";
					cin >> test.statys;
				break;
			}
			out.write((char*)&test, sizeof(test));
		}
		i++;
		in.read((char*)&test, sizeof(test));
	}
	in.close();
	out.close();
	remove("2");
	rename("3", "2");
	number();


}