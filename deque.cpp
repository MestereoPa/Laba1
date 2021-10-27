#include "deque.h"
deque::deque()
{
	head->chisl = 0;
	head->ptr = 0;
	size = 0;
	cout << "����������� ��� " << endl;
};
deque::deque(float chisl)
{
	head->chisl = chisl;
	head->ptr = 0;
	size = 1;
};
deque::~deque()
{
	cout << "���������� ��� " << endl;
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
void deque::push(float newElem)
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
void deque::push()
{
	float newElem;
	int choise;
	cout << "������� ����� �������" << endl;
	cin >> newElem;
	elem* newHead, *buf;
	newHead = new elem;
	buf = head;
	newHead->chisl = newElem;
	cout << "������� ���� �������� �������\n1 - � ������\n2 - � �����" << endl;
	cin >> choise;
		if (choise == 2)
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
			if (choise == 1)
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
				cout << "�������� ����" << endl;
			}
		}

};
float deque::pop()
{
	elem* buf;
	buf = head;
	float a;
	int choise;
	cout <<"�������� ������ ������� �������\n1 - ������\n2 - �����" <<endl;
	cin >> choise;
	do
	{
		if (choise == 2)
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
				cout << "��� ����������";
				return 0;
			}
		}
		else
		{
			if (choise == 1)
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
					cout << "��� ����������";
					return 0;
				}
			}
			else
			{
				cout <<"�������� ����"<<endl;
			}
		}
		
	} while ((choise < 1) && (choise > 2));
};
void deque::get()
{
	elem* bufHead;
	bufHead = head;
	cout << "����� ���\n���������� ��������� size = " << size << endl;
	cout << "�������� : ";
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
void deque::set()
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
void deque::save()
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
		fout << 1 << endl << size << endl;
		for (int i = 0; i < size; i++)
		{
			fout << bufhead->chisl<<' ';
			bufhead = bufhead->ptr;
		}
		fout << endl;
		fout.close();
	}
}
