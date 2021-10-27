#include "list.h"
list::list()
{
	head->chisl = 0;
	head->ptr = 0;
	size = 0;
	cout << "����������� ������ " << endl;
};
list::list(float chisl)
{
	head->chisl = chisl;
	head->ptr = 0;
	size = 1;
};
list::~list()
{
	cout << "���������� ������ " << endl;
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
void list::push(float newElem)
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
}
void list::push()
{
	int index;
	float newElem;
	cout << "������� ����� �������"<<endl;
	cin >> newElem;
	
	elem* newHead, * buf;
	newHead = new elem;
	buf = head;
	int counter;
	newHead->chisl = newElem;
	do
	{
		cout << "������� ������ ����������" << endl;
		cin >> index;
		if ((index >= 0) && (index <= size))
		{
			counter = 0;
			while (counter < size - index)
			{
				counter++;
				buf = buf->ptr;
			}
			if (size == 0)
			{
				newHead->ptr = 0;
			}
			else
			{
				if (index == 0)
				{
					buf->ptr = newHead;
					newHead->ptr = 0;
				}
				else
				{
					if (index == size)
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
			newHead->chisl = newElem;
			size++;
		}
		else
		{
			cout << "��������� ����" << endl;
		}
	} while ((index < 0) && (index > size));
};
float list::pop()
{
	elem* buf, * buf2;
	buf2 = buf = head;
	float a;
	int ind;
	cout << "�������� ����� ������� �������"<<endl;
	cin >> ind;
	if (size == 0)
	{
		cout << "��� ���������" << endl;
	}
	else
	{
		if (ind == size)
		{
			a = head->chisl;
			head = head->ptr;
			delete(buf);
			size--;
			return a;
		}
		else
		{
			for (int i = 1; i < size - ind; i++)
			{
				buf = buf->ptr;
			}
			buf2 = buf->ptr;
			if (ind == 1)
			{
				a = buf2->chisl;
				delete(buf2);
				buf->ptr = 0;
				size--;
				return a;
			}
			else
			{
				if (ind < size || ind > 0)
				{
					a = buf2->chisl;
					buf2 = buf2->ptr;
					delete(buf->ptr);
					buf->ptr = buf2;
					size--;
					return a;
				}
				else
				{
					cout << " ��� ������ ��������" << endl;
					return 0;
				}
			}

		}
	}

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
			cout << "��������� ����" << endl;
		}
	} while ((choise < 0) && (choise > size));
};

void list::get()
{
	elem* bufHead;
	bufHead = head;
	cout << "����� ����\n���������� ��������� size = " << size << endl;
	cout << "�������� : ";
	for (int i = 0; i < size; i++)
	{
		bufHead = head;
		for (int j = i; j < size-1; j++)
		{
			bufHead = bufHead->ptr;
		}
		cout << bufHead->chisl << " ";
	}
	cout << endl;

}
void list::set()
{
	int length;
	float a;
	cout << "�������� ���������� ���������" << endl;
	cin >> length;
	for (int i = 0; i < length; i++)
	{
		cout << "������� �������" << endl;
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
		cout << "���� �� ���������";
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
