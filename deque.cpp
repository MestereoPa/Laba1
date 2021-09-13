#include "deque.h"
deque::deque()
{
	head->chisl = 0;
	head->ptr = 0;
	size = 0;
	cout << "конструктор дек " << endl;
};
deque::deque(float chisl)
{
	head->chisl = chisl;
	head->ptr = 0;
	size = 1;
};
deque::~deque()
{
	cout << "диструктор дек " << endl;
}
deque::deque(const deque& copy)
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
void deque::push(float a)
{
	elem* newHead, *buf;
	newHead = new elem;
	buf = head;
	int choise;
	newHead->chisl = a;
	do
	{
	cout << "выберите куда добавить элемент\n1 - начало\n2 - конец" << endl;
	cin >> choise;
	
		if (choise == 1)
		{
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
		else
		{
			if (choise == 2)
			{
				if (size == 0)
				{
					newHead->ptr = 0;
					head = newHead;
				}
				else
				{
					while (buf->ptr !=0)
					{
						buf = buf->ptr;
					}
					buf->ptr = newHead;
					newHead->ptr = 0;
				}
				size++;
			}
			else
			{
				cout << "неверный ввод" << endl;
			}
		}

	} while ((choise < 1) && (choise > 2));
};
float deque::pop()
{
	elem* buf;
	buf = head;
	float a;
	int choise;
	cout <<"выберите откуда извлечь элемент\n1 - начало\n2 - конец" <<endl;
	cin >> choise;
	do
	{
		if (choise == 1)
		{
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
		}
		else
		{
			if (choise == 2)
			{
				if (size > 0)
				{
					while (buf->ptr->ptr != 0)
					{
						buf = buf->ptr;
					}
					a = buf->ptr->chisl;
					delete(buf->ptr);
					buf->ptr = 0;
					size--;
					return a;
				}
				else
				{
					cout << "Нет эллементов";
					return 0;
				}
			}
			else
			{
				cout <<"неверный ввод"<<endl;
			}
		}
		
	} while ((choise < 1) && (choise > 2));
};