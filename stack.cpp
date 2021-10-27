#include "stack.h"
#include "queue.h"
stack::stack()
{
	head->chisl = 0;
	head->ptr = 0;
	size = 0;
	cout << "конструктор стек " << endl;
};
stack::stack(float chisl)
{
	head->chisl = chisl;
	head->ptr = 0;
	size = 1;
};
stack::~stack()
{
	cout << "диструктор стек "<<endl;
}
stack::stack(const stack& copy)
{
	elem* copyHead = copy.head;
	for (int i = 0; i < copy.size; i++)
	{
		for (int j = 1; j < copy.size - i; j++)
		{
			copyHead = copyHead->ptr;
		}
		push(copyHead->chisl);
		copyHead = head;
	}
}
float stack::pop()
{
	elem* buf;
	buf = head;
	float a;
	if (size > 0)
	{
		a = head->chisl;
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
void stack::get()
{
	elem* bufHead;
	bufHead = head;
	cout << "Класс СТЕК\nКоличество элементов size = " << size << endl;
	cout << "Элементы : ";
	for (int i = 0; i < size; i++)
	{
		bufHead = head;
		for (int j = i; j < size - 1; j++)
		{
			bufHead = bufHead->ptr;
		}
		cout << bufHead->chisl << " ";
	}
	cout << endl;
}
void stack::set()
{
	int length;
	float a;
	cout << "выберите количество элементов" << endl;
	cin >> length;
	for (int i = 0; i < length; i++)
	{
		cout << "введите элемент" << endl;
		cin >> a;
		elem* newHead;
		newHead = new elem;
		newHead->chisl = a;
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
	}
}
void stack::push(float newElem)
{
	elem* newHead;
	newHead = new elem;
	newHead->chisl = newElem;
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
void stack::push()
{
	float newElem; 
	cout << "введите новый элемент" << endl;
	cin >> newElem;
	elem* newHead;
	newHead = new elem;
	newHead->chisl = newElem;
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
void stack::save()
{
	ofstream fout;
	fout.open("keper.dat", ios_base::app);
	if (!fout.is_open())
	{
		cout << "файл не открылсся";
	}
	else
	{
		elem* bufhead = head;
		fout << 3 << endl << size << endl;
		for (int i = 0; i < size; i++)
		{
			fout << bufhead->chisl << ' ';
			bufhead = bufhead->ptr;
		}
		fout << endl;
		fout.close();
	}
}