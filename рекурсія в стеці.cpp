// рекурсія в стеці.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

void adds(int, int);
void reads();
const int g = 100;
int h = g;
int n, m;
struct 
{
	int mi, ni;
}a[g];

int b(int ms, int ns)
{
	int f;
	adds(ms, ns);
	do
	{
		reads();
	//	h--;
		if (m*n) adds(m, n - 1);
		else
		{
			f = m + n + 1;
			if (++h < g)
			{
				reads();h++;
				adds(m-1 , f);
			}

		}

	} while (h < g);
	return f;
}


void adds(int ms, int ns)
{
	if (h--) {
		a[h].mi = ms; a[h].ni = ns;
	}
	else cout << "Steck full" << endl;
}

void reads()
{
	n = a[h].ni; m = a[h].mi;
}

int main()
{
	cout << "Entre m and n:\n";
	cin >> m >> n;
	cout << endl << "Fun=" << b(n, m)<< endl;
	system("pause");
    return 0;
}

