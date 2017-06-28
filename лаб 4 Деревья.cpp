// лаб 4 Деревья.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


struct tree
{
	int val;
	tree *l, *r;
};


/*tree* builder(tree *&t,int *a,int from,int n)
{
	int n1, n2;
	if (!n) return NULL;
	t = new tree;
	t->val = a[from];
	n1 = n / 2;
	n2 = n - n1 - 1;
	t->l = builder(t,a, from + 1, n1);
	t->r = builder(t, a, from + 1 + n1, n2);
	return t;
}*/

void add(tree *&t, int v)
{
	if (!t)
	{
		t = new tree;
		t->val = v;
		t->l=t->r = NULL;
	}
	if (v < t->val)
	{
		if (t->l) add(t->l, v);
		else
		{
			t->l = new tree;
			t->l->r = t->l->l = NULL;
			t->l->val = v;
		}
	}
	if (v > t->val)
	{
		if (t->r) add(t->r, v);
		else
		{
			t->r = new tree;
			t->r->r = t->r->l = NULL;
			t->r->val = v;
		}
	}
}


void show(tree *&t)
{
	if (t)
	{
		show(t->l);
		cout << t->val<< " ";
		show(t->r);
	}
	//cout << endl;
}
 
void show_1(tree *&t)
{
	if (t)
	{
		cout << t->val<< " ";
		show_1(t->l);
		show_1(t->r);
	}
}

void show_2(tree *&t)
{
	if (t)
	{
		show_2(t->l);
		 show_2(t->r);
		cout << t->val<<" ";
	}
}
bool search(tree *&t,int x)
{
	bool flag = false;
       if (t)
	{

		if (x > t->val)
		return 	search(t->r, x);
		else if (x < t->val)
		return 	search(t->l, x);
		else
		{
			flag = true;
			return flag;
		}
	}
	return flag;
}

void together(tree *&t1, tree *&t2, tree *&t3)
{
	if (t1)
	{
		if (search(t2, t1->val))
			add(t3, t1->val);
	 together(t1->l, t2, t3);
		 together(t1->r, t2, t3);
	}
	
}


void no(tree *&t1,tree *&t2,tree *&t3)
{
	if (t1 && t2)
	{
			if (!search(t2, t1->val))
				add(t3, t1->val);
			no(t1->l, t2, t3);
			no(t1->r, t2, t3);

	}
}

void pert(tree* &t1, tree *&t2)
{
	if (t1)
	{
		add(t2, t1->val);
		pert(t1->l, t2);
		pert(t1->r, t2);
	}
}
int p = 0;
void poriv(tree *&t1, tree *&t2,int n,int z,bool &flag,bool &flag_1,bool &flag_2)
{
	if (t1 && t2)
	{
		if (n <= z)
		{
			if (search(t2, t1->val))
				p++;
			poriv(t1->l, t2, n, z, flag, flag_1,flag_2);
			poriv(t1->r, t2, n, z, flag, flag_1,flag_2);
		}
		else
		{
			if (search(t1, t2->val))
				p++;
			poriv(t2->l, t1, n, z, flag, flag_1,flag_2);
			poriv(t2->r, t1, n, z, flag, flag_1,flag_2);
		}
	}
	if (p == n )
	{
		flag = true;
		if (n == z)
			flag_1 = true;
	}
	else if (p==z)
	{
		flag_2 = true;
		if (n == z)
			flag_1 = true;
	}
}
int count(tree *&t,int &k)
{
	if (t)
	{
		count(t->l,k);
		k++;
		count(t->r,k);
	}
	return k;
}

int leaves(tree *&t,int &k)
{
	
	if (t)
	{
		if (!t->l && !t->r)
			k++;
			leaves(t->l, k);
			leaves(t->r, k);
	}
	return k;
}
	
	
	

int max_1(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

int height(tree *cur)
{
	if (cur)
	{
		return 1 + max_1(height(cur->l), height(cur->r));
	}
	return 0;
}
tree *search_1(tree *&t, int x,bool &m)
{
    if (!t) return NULL;
	if (t->val == x)
	{
		m = true;return t;
	}
	else if (t->val>x) return search_1(t->l, x,m);
	else return  search_1(t->r, x,m);
}
int verx(tree *&t,int &k)
{
	if (t)
	{
		if (t->l || t->r)
		{
			k++;
		}
		 verx(t->l,k);
		 verx(t->r,k);
		}
	
return k;
}
void del_2 (tree *&t)
{
	if (t)
	{
		del_2(t->l);
		del_2(t->r);
		delete t;
		t = NULL;
	}
}
/*void del(tree *&t, int x,bool m)
{
	tree *w = NULL;
	if (t)
	{
		search_1(t, x,m);
		if (m)
		{
			if (t->val == x && !t->l && !t->r)
				delete t;
			else if (t->val == x &&!t->l && t->r)
			{
				t->val = t->r->val;delete t->r;
			}
			else if (t->val == x && t->l && !t->r)
			{
				t->val = t->l->val; delete t->l;
			}
			else
			{
	

			}
		}
	}
}*/
int max(tree *t)
{
	while (t->r)
		t = t->r;
	return t->val;
}

int min(tree *t)
{

	while (t->l)
		t = t->l;
	return t->val;
}
int main()
{
	tree *t = NULL,*t1=NULL,*t2=NULL;
	setlocale(LC_ALL, "Russian");
	menu:
	cout << " 1.Добавить\n2Симетрично просмотреть\n3.Прямой просмотр\n4.Обратный просмотр \n5.Принадлежность элемента множеству \n6.Перетин\n7.Симетрическая разница\n8.Обьединение\n9.Сравнение\n10.Количетво вершин\n11.количество листьев\n12.количество элементов множества\n13.макс\n14.мин\n15.Очистить\n16.Высота\n17exit\n";
	int n;
	cin >> n;
	switch (n)
	{
	case 1: {
		system("cls");
		int x;
		cout << "Введите добавляемое число:";
		cin >> x;
		add(t, x);
		cout << "Удостоверьтесь в правильности добавления\n";
		show(t);
		cout << endl;
		system("pause");
		system("cls");
		goto menu;
	}
	case 2:
	{
		system("cls");
		show(t);
		cout << endl;
		system("pause");
		system("cls");
		goto menu;
	}
	case 3:
	{
		system("cls");
		show_1(t);
		cout << endl;
		system("pause");
		system("cls");
		goto menu;
	}
	case 4:
	{
		system("cls");
		show_2(t);
		cout << endl;
		system("pause");
		system("cls");
		goto menu;
	}
	case 5:
	{
		system("cls");
		int y;
		cout << "Введите элемент для поиска\n";
		cin >> y;
		if (search(t, y))
			cout << "Элемент входит в множество\n";
		else
			cout << "Элемент не входит в множество\n";
		cout << endl;
		system("pause");
		system("cls");
		goto menu;
	}

	case 6:
	{
		system("cls");
		int n, a, f;
		cout << "Желаете что-то добавить к первому множеству\n";
		char z;
		cin >> z;
		if (z == 'y')
		{
			cout <<
				"Сколько элементов вы хотите добавить ?\n";
			cin >> n;
			system("cls");
			cout << "Введите элементы\n";
			for (int i = 0;i < n;i++)
			{
				cin >> a;
				add(t, a);
			}
		}
		system("cls");
		cout << "Введите количество элементов второго множества\n";
		cin >> f;
		cout << "Введите элементы второго множества\n";
		for (int i = 0;i < f;i++)
		{
			cin >> a;
			add(t1, a);
		}
		together(t, t1, t2);
		show(t2);
		del_2(t1);
		del_2(t2);
		cout << endl;
		system("pause");
		system("cls");
		goto menu;
	}
	case 7:
	{
		system("cls");
		int n, a, f;
		cout << "Желаете что-то добавить к первому множеству\n";
		char z;
		cin >> z;
		if (z == 'y')
		{
			cout <<
				"Сколько элементов вы хотите добавить ?\n";
			cin >> n;
			system("cls");
			cout << "Введите элементы\n";
			for (int i = 0;i < n;i++)
			{
				cin >> a;
				add(t, a);
			}
		}
		system("cls");
		cout << "Введите количество элементов второго множества\n";
		cin >> f;
		cout << "Введите элементы второго множества\n";
		for (int i = 0;i < f;i++)
		{
			cin >> a;
			add(t1, a);
		}
		no(t, t1, t2);
		no(t1, t, t2);
		show(t2);
		cout << endl;
		system("pause");
		system("cls");
		del_2(t1);
		del_2(t2);
		goto menu;
	}
	case 8:
	{
		system("cls");
		int n, a, f;
		cout << "Желаете что-то добавить к первому множеству\n";
		char z;
		cin >> z;
		if (z == 'y')
		{
			cout <<
				"Сколько элементов вы хотите добавить ?\n";
			cin >> n;
			system("cls");
			cout << "Введите элементы\n";
			for (int i = 0;i < n;i++)
			{
				cin >> a;
				add(t, a);
			}
		}
		system("cls");
		cout << "Введите количество элементов второго множества\n";
		cin >> f;
		cout << "Введите элементы второго множества\n";
		for (int i = 0;i < f;i++)
		{
			cin >> a;
			add(t1, a);
		}

		pert(t, t1);
		show(t1);
		del_2(t1);
		system("pause");
		system("cls");
		goto menu;
	}
	case 9:
	{
		system("cls");
		int n, a, f;
		cout << "Желаете что-то добавить к первому множеству\n";
		char z;
		cin >> z;
		if (z == 'y')
		{
			cout <<
				"Сколько элементов вы хотите добавить ?\n";
			cin >> n;
			system("cls");
			cout << "Введите элементы\n";
			for (int i = 0;i < n;i++)
			{
				cin >> a;
				add(t, a);
			}
		}
		system("cls");
		cout << "Введите количество элементов второго множества\n";
		cin >> f;
		cout << "Введите элементы второго множества\n";
		for (int i = 0;i < f;i++)
		{
			cin >> a;
			add(t1, a);
		}
		bool flag = false, flag_1 = false, flag_2 = false;
		poriv(t, t1, n, f, flag, flag_1, flag_2);
		if ((flag && flag_1) || (flag_2 && flag_1))
			cout << "Множества совпадают\n";
		else if (flag && !flag_1)
			cout << "Первое множество-подмножество второго множества\n";
		else if (flag_2 && !flag_1)
			cout << "Второе множество - подмножество первого множества\n";
		else if (!flag && !flag_1 && !flag_2)
			cout << "Множества различны\n";
		system("pause");
		del_2(t1);
		system("cls");
		goto menu;
	}
	case 10:
	{
		int k;
		system("cls");
		cout << endl << verx(t, k) << endl;
		system("pause");
		system("cls");
		goto menu;
	}
	case 11:
	{
		int k;
		system("cls");
		cout << endl << leaves(t, k) << endl;
		system("pause");
		system("cls");
		goto menu;
	}
	case 12:
	{
		int k;
		system("cls");
		cout << endl << count(t, k) << endl;
		system("pause");
		system("cls");
		goto menu;
	}
	case 13:
	{
		int k;
		system("cls");
		cout << endl << max(t) << endl;
		system("pause");
		system("cls");
		goto menu;
	}
	case 14:
	{
		int k;
		system("cls");
		cout << endl << min(t) << endl;
		system("pause");
		system("cls");
		goto menu;
	}
	case 15:
	{
		system("cls");
		char z;
		cout << "Вы уверены\n";
		cin >> z;
		if (z == 'y')
			del_2(t);
		system("cls");
		goto menu;
	}
	case 16:
	{
		system("cls");
		cout <<endl<< height(t) << endl;
		system("pause");
		system("cls");
		goto menu;
	}
	case 17 :
	{
		system("cls");
		break;
	}
	default :
	{
		system("cls");
		goto menu;
	}
	}
	system("pause");
    return 0;
}

