#include "Keper.h"

Keper::Keper()
{
	head->chisl = 0;
	head->ptr = 0;
	size = 0;
	cout << "конструктор Keper " << endl;
};
Keper::Keper(queue *newElem)
{
	head->element = newElem;
	head->ptr = 0;
	size = 1;
};
Keper::~Keper()
{
	elem* bufHead;
	for (int i = 0; i < size - 1; i++)
	{
		bufHead = head->ptr;
		head->element->~queue();
		head = bufHead;
	}
	head->element->~queue();
	cout << "диструктор Keper " << endl;
}

queue* Keper::pop()
{
	elem* buf;
	buf = head;
	queue *a;
	if (size > 0)
	{
		a = head->element;
		head = head->ptr;
		delete(buf);
		size--;
		return a;
	}
	else
	{
		cout << "Нет эллементов";
		return 0;
	}
};
queue* Keper::operator[] (const int ind)
{
	elem* buf = head;
	if ((ind >= size) || (ind < 0))
	{
		cout << "неверный индекс" << endl;
	}
	else
	{
		for (int i = 0; i < size - ind - 1; i++)
		{
			buf = buf->ptr;
		}
		return(buf->element);
	}
}
void Keper::get()
{
	elem* bufHead;
	bufHead = head;
	cout << "Количество элементов size = " << size << endl;
	cout << "Элементы : ";
	while (bufHead != 0)
	{
		cout << "___________________________________________________________";
		bufHead->element->get();
		bufHead = bufHead->ptr;
	}
	cout << endl;
}
void Keper::push(queue* a)
{
	elem* newHead;
	newHead = new elem;
	newHead->element = a;
	if (size == 0)
	{
		newHead->ptr = 0;
	}
	else
	{
		newHead->ptr = head;
	}
	head = newHead;
	size++;
};
