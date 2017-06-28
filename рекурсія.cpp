// рекурсія.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int f(int m, int n)
{
	if (m*n == 0) return m + n + 1;
	else
		return f(m - 1, f(m, n - 1));
}


int main()
{
	int n, m;
	cout << "Enter m and n :\n";
	cin >> m >> n;
	cout << "Fun=" << f(m, n)<<endl;
	system("pause");
    return 0;
}

