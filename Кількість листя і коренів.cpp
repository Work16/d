// Кількість листя і коренів.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


const int n = 3;

struct tree
{
	int value;
	tree *s[n];
};

void builder(tree *&d,int x)
{
	if (!d)
	{
		d->value = x;
	}

}

int main()
{
	tree *d = NULL;
	system("pause");
    return 0;
}

