// лаб 2 многочлен в списку.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

struct list
{
	int a;
	int kx, ky, kz;
	list *next;
};


void difer(list *beg)
{
	list *temp = beg->next;
	while (beg->next)
	{
		if (beg->a != 0)
			while (temp)
			{
				if (beg->kx == temp->kx && beg->ky == temp->ky && beg->kz == temp->kz)
				{
					beg->a = beg->a + temp->a;
					temp->a = 0;
				}
				temp = temp->next;
			}
		beg = beg->next;
		temp = beg->next;
	}
}
void write(list * &beg, int f, int g, int h, int r)
{
	list *temp = new list;
	if (!beg )
	{
		temp->a = f;
		temp->kx = g;
		temp->ky = h;
		temp->kz = r;
		temp->next = NULL;
		beg = temp;
	}
	else
	{
		    temp->a = f;
            temp->kx = g;
			temp->ky = h;
			temp->kz = r;
			temp->next = beg;
			beg = temp;
	}
}
void print(list *beg)
{
//	delete(beg);
	while (!beg) cout << "ошибка\n";
	while (beg )
	{
		if (beg->a >= 0)
			cout << beg->a;
		else if (beg->a <0)
			cout << '(' << beg->a << ')';
		if (beg->kx == 1)
			cout << "*x";
					else if (beg->kx)
					cout << "*x^" << beg->kx;
		if (beg->ky == 1)
			cout << "*y";
		else if (beg->ky)
					cout << "*y^" << beg->ky;
		if (beg->kz == 1)
			cout << "*z";
		else if (beg->kz)
				cout << "*z^" << beg->kz;
				if (beg->next)
					cout << "+";
				beg = beg->next;
  }
	cout << endl;
}
int point(list *beg,int x,int y,int z)
{
	int sum = 0;
	while (beg)
	{
		sum += beg->a * pow(x, beg->kx) * pow(y, beg->ky)*pow(z, beg->kz);
		beg = beg->next;
	}
	return sum;
}
void mnoz(list *beg,int c)
{
	if (!c) beg == NULL;
		while (beg)
	{
		beg->a = beg->a *c;
		beg = beg->next;
	}
}
/*void delet_0(list *beg)
{
	list *temp;

	while (beg)
	{

		while (beg)
		{
			temp = 0;
		}
		if (!(beg->next) && !(beg->next->a))
		{
			temp = beg->next;
			beg->next = NULL;
			delete temp;
		}

		else 	if (beg->next->a == 0)
		{
			temp = beg->next;
			beg->next = beg->next->next;
			delete temp;
		}
		else
		{
			temp = beg;
			beg = beg->next;
			delete temp;
		}


	}
}/
/*list * sum(list *beg1, list * beg2)
{
	list *temp = beg2;
	list *beg3 = NULL;
	while (beg1)
	{
		while (beg2)
		{
			if (beg1->kx == beg2->kx && beg1->ky == beg2->ky && beg1->kz == beg2->kz)
			{
				if (beg1->a + beg2->a)
				{
					/*beg3->a = beg1->a + beg2->a;
					beg3->kx = beg1->kx;
					beg3->ky = beg1->ky;
					beg3->kz = beg1->kz;
					beg3= beg3->next;
					write(beg3, beg1->a + beg1->a, beg1->kx, beg1->ky, beg3 -> kz);
					beg2->a = 0;
				}
				else
					beg2->a = 0;
			}
			beg2 = beg2->next;
		}
		if (!(beg2 = temp->next));
		temp = temp->next;
		beg1 = beg1->next;
	}
	//delet_0(beg2);
	while (beg2)
	{
		if (beg2->a != 0)
		{
			write(beg3, beg2->a + beg2->a, beg2->kx, beg2->ky, beg3->kz);
			/*beg3->a = beg2->a;
			beg3->kx = beg2->kx;
			beg3->ky = beg2->ky;
			beg3->kz = beg2->kz;
			beg3 = beg3->next;
		}
			beg2 = beg2->next;
	}
	return beg3;
}*/
list *home(list *beg1, list*beg2)
{
	list *temp = beg2;
	list *beg3 = NULL;
	while (beg1)
	{
		beg2 = temp;
		while (beg2)
		{
			write(beg3, beg1->a*beg2->a, beg1->kx + beg2->kx, beg1->ky + beg2->ky, beg1->kz + beg2->kz);
			beg2 = beg2->next;
		}
		beg1 = beg1->next;
	}
	difer(beg3);
	//del(beg3);
	return beg3;
}
void del(list *beg)
{
	list *temp = beg->next;
	while (beg)
	{
		if (temp->a == 0)
			beg->next = temp->next;
		beg = beg->next;
		temp = temp->next;
	}
}
list *suma(list *beg1, list *beg2)
{
	bool flag = false;
	list *temp = beg2;
	list *beg3 = NULL;
	while (beg1)
	{
		flag = false;
		while (beg2)
		{
			if (beg1->kx == beg2->kx && beg1->ky == beg2->ky && beg1->kz == beg2->kz)
			{
				write(beg3, beg1->a + beg2->a, beg1->kx, beg1->ky, beg1->kz);
				beg2->a = 0;
				flag = true;
			}
			
				beg2 = beg2->next;
		}
		if (!flag)
			write(beg3, beg1->a, beg1->kx, beg1->ky, beg1->kz);
		beg1 = beg1->next;
	}
	/*while (beg1)
	{
		if (beg1->a != 0)
			write(beg3, beg1->a, beg1->kx, beg1->ky, beg1->kz);
		beg1 = beg1->next;
	}*/
	while (temp)
	{
		if (temp->a != 0)
			write(beg3, temp->a, temp->kx, temp->ky, temp->kz);
		temp = temp->next;
	}
	difer(beg3);
	//del(beg3);
	return beg3;
}
list *minu(list*beg1, list * beg2)
{
	mnoz(beg2, -1);
	return 	suma(beg1, beg2);
}
void buble(list *beg)
{
	list *temp = beg; 
	list *node, *node2;

	for (node = temp; node; node = node->next)
		for (node2 = temp; node2; node2 = node2->next)
			if (node->a > node2->a) { 
				int i = node->a;
				node->a = node2->a;
				node2->a = i;
				i = node->kx;
				node->kx = node2->kx;
				node2->kx = i;
				i = node->ky;
				node->ky = node2->ky;
				node2->ky = i;
				i = node->kz;
				node->kz = node2->kz;
				node2->kz = i;
			}
}


void de(list *&beg)
{
	while (beg)
	{
		list *temp = beg->next;
		delete beg;
		beg = temp;
	}
}

int main()
{
	list *l = NULL, *d = NULL;
	int n;
	setlocale(LC_ALL, "Russian");
	//delet_0(l);
	system("cls");
	int c,f,g,h,r;
	menu :
	cout << "1.Ввести\n2.Умножить на констаnнту\n3.Перемножить многочлены\n4.умножить на одночлен\n5.Сложить многочлены\n6.отнять многочлены\n7.значение в точке\n";
	cin >> c;
	switch (c)
	{
	case 1:
	{
		system("cls");
		cout << "Введите количество слогаемых:";
		cin >> n;
		for (int i = 0;i < n;i++)
		{

			cout << "Коэфициэнт:";
			cin >> f;
			cout << "Степень x :";
			cin >> g;
			cout << "Степень y :";
			cin >> h;
			cout << "Степень z :";
			cin >> r;
			if (f)
			write(l, f, g, h, r);
		}
		print(l);
		system("pause");
		de(l);
		system("cls");
		goto menu;
	}
	case 2:
	{system("cls");
		cout << "Введите количество слогаемых:";
	cin >> n;
		for (int i = 0;i < n;i++)
		{

			cout << "Коэфициэнт:";
			cin >> f;
			cout << "Степень x :";
			cin >> g;
			cout << "Степень y :";
			cin >> h;
			cout << "Степень z :";
			cin >> r;
			if (f)
			write(l, f, g, h, r);
		}
		print(l);
		int v;
		cout << "Введите константу :\n";
		cin >> v;
		mnoz(l, v);
		print(l);
		system("pause");
		de(l);
		system("cls");
		goto menu;
	}
	case 3:
	{system("cls");
		cout << "Введите количество слогаемых:";
		cin >> n;

		for (int i = 0;i < n;i++)
		{

			cout << "Коэфициэнт:";
			cin >> f;
			cout << "Степень x :";
			cin >> g;
			cout << "Степень y :";
			cin >> h;
			cout << "Степень z :";
			cin >> r;
			if (f)
			write(l, f, g, h, r);
		}
		cout << "Введите количество слогаемых:";
		cin >> n;

		for (int i = 0;i < n;i++)
		{

			cout << "Коэфициэнт:";
			cin >> f;
			cout << "Степень x :";
			cin >> g;
			cout << "Степень y :";
			cin >> h;
			cout << "Степень z :";
			cin >> r;
			//if (f)
			write(d, f, g, h, r);
		}
		print(l);
		print(d);
		print(home(l, d));
		system("pause");
		de(l);
		de(d);
		system("cls");
		goto menu;
	}
	case 4:
	{system("cls");
		cout << "Введите количество слогаемых:";
	cin >> n;
	int f, g, h, r;
	for (int i = 0;i < n;i++)
	{

		cout << "Коэфициэнт:";
		cin >> f;
		cout << "Степень x :";
		cin >> g;
		cout << "Степень y :";
		cin >> h;
		cout << "Степень z :";
		cin >> r;
		if (f)
		write(l, f, g, h, r);
	}
	cout << "Введите одночлен:\n";
	for (int i = 0;i < 1;i++)
	{

		cout << "Коэфициэнт:";
		cin >> f;
		cout << "Степень x :";
		cin >> g;
		cout << "Степень y :";
		cin >> h;
		cout << "Степень z :";
		cin >> r;
		if (f)
		write(d, f, g, h, r);
	}
	print(l);
	print(d);
	print(home(l, d));
	system("pause");
	de(l);
	de(d);
	system("cls");
	goto menu;
	}

	case 5:
	{system("cls");
		cout << "Введите количество слогаемых:";
	cin >> n;

	for (int i = 0;i < n;i++)
	{

		cout << "Коэфициэнт:";
		cin >> f;
		cout << "Степень x :";
		cin >> g;
		cout << "Степень y :";
		cin >> h;
		cout << "Степень z :";
		cin >> r;
		if (f)
		write(l, f, g, h, r);
	}
	cout << "Введите количество слогаемых:";
	cin >> n;
	for (int i = 0;i < n;i++)
	{

		cout << "Коэфициэнт:";
		cin >> f;
		cout << "Степень x :";
		cin >> g;
		cout << "Степень y :";
		cin >> h;
		cout << "Степень z :";
		cin >> r;
		if (f)
		write(d, f, g, h, r);
	}
	print(l);
	print(d);
	print(suma(l, d));
	system("pause");
	de(l);
	de(d);
	system("cls");
	goto menu;
	}

	case 6:
	{system("cls");
		cout << "Введите количество слогаемых:";
		cin >> n;
		for (int i = 0;i < n;i++)
		{

			cout << "Коэфициэнт:";
			cin >> f;
			cout << "Степень x :";
			cin >> g;
			cout << "Степень y :";
			cin >> h;
			cout << "Степень z :";
			cin >> r;
			if (f)
			write(l, f, g, h, r);
		}
		cout << "Введите количество слогаемых:";
		cin >> n;
		for (int i = 0;i < n;i++)
		{

			cout << "Коэфициэнт:";
			cin >> f;
			cout << "Степень x :";
			cin >> g;
			cout << "Степень y :";
			cin >> h;
			cout << "Степень z :";
			cin >> r;
			if (f)
			write(d, f, g, h, r);
		}
		print(l);
		print(d);
		print(minu(l, d));
		system("pause");
		de(l);
		de(d);
		system("cls");
		goto menu;
	}

	case 7:
	{
		system("cls");
		cout << "Введите количество слогаемых:";
		cin >> n;

		for (int i = 0;i < n;i++)
		{

			cout << "Коэфициэнт:";
			cin >> f;
			cout << "Степень x :";
			cin >> g;
			cout << "Степень y :";
			cin >> h;
			cout << "Степень z :";
			cin >> r;
			if (f)
			write(l, f, g, h, r);
		}
		print(l);
		int x, y, z;
		cout << "Введите координаты :\n";
		cin >> x >> y >> z;
		cout << point(l, x, y, z)<< endl;
		//print(l);
		system("pause");
		de(l);
		de(d);
		system("cls");
		goto menu;
	}
	}
	
}


