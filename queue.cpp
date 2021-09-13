#include "queue.h"
	queue::queue()
	{
		head->chisl = 0;
		head->ptr = 0;
		size = 0;
		cout << "конструктор queue " << endl;
	};
	queue::queue(float chisl)
	{
		head->chisl = chisl;
		head->ptr = 0;
		size = 1;
	};
	queue::~queue()
	{
		elem* buf = head;
		while (head->ptr != 0)
		{
			head = head->ptr;
			delete (buf);
			buf = head;
		}
		delete (head);
		cout << "диструктор queue " << endl;
	};
	queue::queue(const queue& copy)
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

	void queue::push(float a)
	{
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
	};

	float queue::pop()
	{
		elem *buf;
		buf = head;
		float a;
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
	};

	void queue::get()
	{
		elem* bufHead;
		bufHead = head;
		cout << "Количество элементов size = " << size << endl;
		cout << "Элементы : ";
		while (bufHead != 0)
		{
			cout << bufHead->chisl<<" ";
			bufHead = bufHead->ptr;
		}
		cout << endl;
	}
	void queue::set()
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