// лаб2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

vector<int> TetragonSort(vector<int> arr)
{
	int min = 0, i, j, k;
	vector<int> additList, resultList;

	int nGroups = sqrt(arr.size());
	if (nGroups*nGroups < arr.size())
		nGroups++;

	additList.assign(nGroups, INT_MAX); //заполняем nGroups ячеек значением INT_MAX

										//заполнение первичными значениями дополнительнгго списсска
	for (i = nGroups*min; i < arr.size(); i += nGroups)
	{
		min = i; //индекс минимального
		for (j = i + 1; j < i + nGroups && j < arr.size(); j++)
		{
			if (arr[j] < arr[min])
				min = j;
		}
		//добавление эл-а в доп. список и заполние эл-а в осн.
		additList[i / nGroups] = arr[min];
		arr[min] = INT_MAX;
	}

	//основной цикл
	while (true)
	{
		//формирование результата------------
		min = 0; //индекс минимального
		for (k = 1; k < additList.size(); k++)
		{
			if (additList[k] < additList[min])
				min = k;
		}
		resultList.push_back(additList[min]);
		//------------------------------------

		if (resultList.size() == arr.size()) //точка выхода
			break;

		//основная работа
		i = nGroups*min; //начальная точка просмотра
		min = i; //индекс минимального
		for (j = i + 1; j < i + nGroups && j < arr.size(); j++)
		{
			if (arr[j] < arr[min])
				min = j;
		}
		//добавление эл-а в доп. список и заполние эл-а в осн.
		additList[i / nGroups] = arr[min];
		arr[min] = INT_MAX;
	}


	return resultList;
}



int main()
{
    return 0;
}

