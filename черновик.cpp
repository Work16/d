// черновик.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"




struct MyFIFO {
	int val;
	int size;
	MyFIFO *Head, *Tail, *Next;
	void Add(const int x); //Добавил функцию добавления для очереди

};

void MyFIFO::Add(int x) {
	static int count = 0;
	MyFIFO *temp = new MyFIFO;  //Создаем вообще новый элемент temp
	Next = temp->Head;            //Создаем связь очереди с вновь созданным элементом, указывая, что следующий элемент очереди имеет адрес его начала
	temp->val = x;                //Записываем принятый элемент в temp, точнее в нужную переменную вовнутрь temp
	if (Head != NULL) {            //Проверка на пустоту. Если не пусто
		Tail->Next = temp;    //Записываем, что следующий элемент в хвосте имеет адрес temp
		Tail = temp;          //Перемещаем хвост на свой следующий элемент. Получается, что хвост теперь начинается в последнем созданном temp 
	}
	else Head = Tail = temp;      //Если же очередь пустая, то тогда, адреса начала, конца очереди и первого созданного элемента должны быть одинаковыми
	count++;

	Tail->Next = Head;
	size = count;
}
