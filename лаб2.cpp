// ���2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

vector<int> TetragonSort(vector<int> arr)
{
	int min = 0, i, j, k;
	vector<int> additList, resultList;

	int nGroups = sqrt(arr.size());
	if (nGroups*nGroups < arr.size())
		nGroups++;

	additList.assign(nGroups, INT_MAX); //��������� nGroups ����� ��������� INT_MAX

										//���������� ���������� ���������� ��������������� ��������
	for (i = nGroups*min; i < arr.size(); i += nGroups)
	{
		min = i; //������ ������������
		for (j = i + 1; j < i + nGroups && j < arr.size(); j++)
		{
			if (arr[j] < arr[min])
				min = j;
		}
		//���������� ��-� � ���. ������ � �������� ��-� � ���.
		additList[i / nGroups] = arr[min];
		arr[min] = INT_MAX;
	}

	//�������� ����
	while (true)
	{
		//������������ ����������------------
		min = 0; //������ ������������
		for (k = 1; k < additList.size(); k++)
		{
			if (additList[k] < additList[min])
				min = k;
		}
		resultList.push_back(additList[min]);
		//------------------------------------

		if (resultList.size() == arr.size()) //����� ������
			break;

		//�������� ������
		i = nGroups*min; //��������� ����� ���������
		min = i; //������ ������������
		for (j = i + 1; j < i + nGroups && j < arr.size(); j++)
		{
			if (arr[j] < arr[min])
				min = j;
		}
		//���������� ��-� � ���. ������ � �������� ��-� � ���.
		additList[i / nGroups] = arr[min];
		arr[min] = INT_MAX;
	}


	return resultList;
}



int main()
{
    return 0;
}

