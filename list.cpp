#include "list.h"
list::list()
{
	head->chisl = 0;
	head->ptr = 0;
	size = 0;
	cout << "конструктор список " << endl;
};
list::list(float chisl)
{
	head->chisl = chisl;
	head->ptr = 0;
	size = 1;
};
list::~list()
{
	cout << "диструктор список " << endl;
}
list::list(const list& copy)
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
void list::push(float a)
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
}
void list::push(float a, int choise)
{
	elem* newHead, * buf;
	newHead = new elem;
	buf = head;
	int ind;
	newHead->chisl = a;
	do
	{
		if ((choise >= 0) && (choise <= size))
		{
			ind = 0;
			while (ind < choise - 1)
			{
				ind++;
				buf = buf->ptr;
			}
			if (size == 0)
			{
				newHead->ptr = 0;
			}
			else
			{
				if (choise == size)
				{
					buf->ptr = newHead;
					newHead->ptr = 0;
				}
				else
				{
					if (choise == 0)
					{
						newHead->ptr = head;
						head = newHead;
					}
					else
					{
						newHead->ptr = buf->ptr;
						buf->ptr = newHead;
					}
				}

			}
			newHead->chisl = a;
			size++;
		}
		else
		{
			cout << "повторите ввод" << endl;
		}
	} while ((choise < 0) && (choise > size));
};
float list::pop()
{
	elem* buf, * buf2;
	buf2 = buf = head;
	float a;
	int choise, ind;
	cout << "выберите какой элемент извлечь от 1 до "<<size<<endl;
	cin >> choise;
	do
	{
		if ((choise > 0) && (choise <= size))
		{
			ind = 0;
			choise--;
			while (ind != choise )
			{
				ind++;
				buf = buf->ptr;
			}
			if (size == 0)
			{
				a = buf->chisl;
				delete(buf);
			}
			else
			{
				if (choise == size-1)
				{
					a = buf->ptr->chisl;
					delete(buf->ptr);
					buf->ptr = 0;
				}
				else
				{
					if (choise == 0)
					{
						a = buf->chisl;
						head = buf->ptr;
						delete(buf);
					}
					else
					{
						a = buf->ptr->chisl;
						buf2 = buf->ptr;
						buf->ptr = buf2->ptr;
						delete(buf2);
					}
				}
			}
			size--;
			return a;
		}
		else
		{
			cout << "повторите ввод" << endl;
		}
	} while ((choise < 0) && (choise > size));

}
float list::pop(int choise)
{
	elem* buf, *buf2;
	buf2 = buf = head;
	float a;
	int  ind;
	do
	{
		if ((choise >= 0) && (choise <= size))
		{
			ind = 0;
			while (ind != choise-1)
			{
				ind++;
				buf = buf->ptr;
			}
			if (size == 0)
			{
				a = buf->chisl;
				delete(buf);
			}
			else
			{
				if (choise == size)
				{
					a = buf->ptr->chisl;
					delete(buf->ptr);
					buf->ptr = 0;
				}
				else
				{
					if (choise == 0)
					{
						a = buf->chisl;
						head = buf->ptr;
						delete(buf);
					}
					else
					{
						a = buf->ptr->chisl;
						buf2 = buf->ptr;
						buf->ptr = buf2->ptr;
						delete(buf2);
					}
				}

			}
			size--;
			return a;
		}
		else
		{
			cout << "повторите ввод" << endl;
		}
	} while ((choise < 0) && (choise > size));
};
float& list::operator[] (const int index)
{
	elem* buf = head;
	if ((index >= size) || (index < 0))
	{
		cout << "неверный индекс" << endl;
	}
	else
	{
		for (int i = 0; i < size - index - 1; i++)
		{
			buf = buf->ptr;
		}
		return(buf->chisl);
	}
}
void list::get()
{
	elem* bufHead;
	bufHead = head;
	cout << "Класс ЛИСТ\nКоличество элементов size = " << size << endl;
	cout << "Элементы : ";
	while (bufHead != 0)
	{
		cout << bufHead->chisl << " ";
		bufHead = bufHead->ptr;
	}
	cout << endl;
}
void list::set()
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
void list::save()
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
		fout << 2 << endl << size << endl;
		for (int i = 0; i < size; i++)
		{
			fout << bufhead->chisl << ' ';
			bufhead = bufhead->ptr;
		}
		fout << endl;
		fout.close();
	}
}
