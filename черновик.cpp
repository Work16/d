// ��������.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"




struct MyFIFO {
	int val;
	int size;
	MyFIFO *Head, *Tail, *Next;
	void Add(const int x); //������� ������� ���������� ��� �������

};

void MyFIFO::Add(int x) {
	static int count = 0;
	MyFIFO *temp = new MyFIFO;  //������� ������ ����� ������� temp
	Next = temp->Head;            //������� ����� ������� � ����� ��������� ���������, ��������, ��� ��������� ������� ������� ����� ����� ��� ������
	temp->val = x;                //���������� �������� ������� � temp, ������ � ������ ���������� �������� temp
	if (Head != NULL) {            //�������� �� �������. ���� �� �����
		Tail->Next = temp;    //����������, ��� ��������� ������� � ������ ����� ����� temp
		Tail = temp;          //���������� ����� �� ���� ��������� �������. ����������, ��� ����� ������ ���������� � ��������� ��������� temp 
	}
	else Head = Tail = temp;      //���� �� ������� ������, �� �����, ������ ������, ����� ������� � ������� ���������� �������� ������ ���� �����������
	count++;

	Tail->Next = Head;
	size = count;
}
