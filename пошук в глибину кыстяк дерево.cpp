// пошук в глибину кыстяк дерево.cpp : Defines the entry point for the console application.
//



#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;
const int n = 3;
bool *visited = new bool[n];

int graph[n][n] =
/*{
	{ 0, 1, 0, 0, 1 },
	{ 1, 0, 1, 1, 0 },
	{ 0, 1, 0, 0, 1 },
	{ 0, 1, 0, 0, 1 },
	{ 1, 0, 1, 1, 0 }
};*/
{
	{0,0,0},
	{0,0,1},
	{0,1,0},
};
void DFS(int st,int **& b,int &z)
{
	z++;
	cout << st + 1 << " ";
	visited[st] = true;
	for (int r = 0; r <= n; r++)
		if ((graph[st][r] != 0) && (!visited[r]))
		{
			if (b[st][r] != 1)
				b[st][r] = 1;
			DFS(r, b,z);
		}
}
int  main()
{
	setlocale(LC_ALL, "Rus");
	int start;
	cout << "Матрица смежности графа: " << endl;
	for (int i = 0; i<n; i++)
	{
		visited[i] = false;
		for (int j = 0; j<n; j++)
			cout << setw(3) << graph[i][j];
		cout << endl;
	}
	int z = 0;
	//cout << "Стартовая вершина >> "; cin >> start;
	start = 1;
	bool *vis = new bool[n];
	cout << "Порядок обхода: ";
	int **b = new int *[n];
	for (int i = 0;i < n;i++)
		b[i] = new int[n];
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
			b[i][j] = 0;
	menu :
	DFS(start - 1,b,z);
	cout << endl;
	if (z < n)
	{
		start = start+1;
		goto menu;
	}
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
			cout << setw(3) << b[i][j];
		cout << endl;
	}
	delete[]visited;
	system("pause");
	return 0;
}