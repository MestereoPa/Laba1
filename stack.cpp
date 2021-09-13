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