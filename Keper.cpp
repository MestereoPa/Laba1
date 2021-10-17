#include "Keper.h"

Keper::Keper()
{
	head->element = 0;
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
	elem2* bufHead;
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
	elem2* buf;
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
	elem2* buf = head;
	if ((ind >= size) || (ind < 0))
	{
		cout << "неверный индекс" << endl;
		return 0;
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
void Keper::save()
{
	ofstream fout;
	fout.open("keper.dat", ios_base::out);
	if (!fout.is_open())
	{
		cout << "файл не открылся" << endl;
	}
	else
	{
		fout << size << endl;
		fout.close();
		elem2* buf = head;
		for (int i = 0; i < size; i++)
		{
			buf->element->save();

		}
	}
	
}
void Keper::load()
{
	ifstream fin;
	int choise;
	int specsize;
	string a, b, c, d;
	queue* qe;
	fin.open("keper.dat");
	if (!fin.is_open())
	{
		cout << "файл не открылся" << endl;
	}
	else
	{
		fin >> specsize;
		for (int i = 0; i < specsize; i++)
		{
			int colvo;
			float a;
			fin >> choise;
			if (choise == 1)
			{
				fin >> colvo;
				deque* de;
				de = new deque;
				for (int i = 0; i < colvo; i++)
				{
					fin >> a;
					de->push(a);
				}
				qe = de;
				push(qe);
			}
			if (choise == 2)
			{
				fin >> colvo;
				list* li;
				li = new list;
				for (int i = 0; i < colvo; i++)
				{
					fin >> a;
					li->push(a);
				}

				qe = li;
				push(qe);
			}
			if (choise == 3)
			{
				fin >> colvo;
				stack* st;
				st = new stack;
				for (int i = 0; i < colvo; i++)
				{
					fin >> a;
					st->push(a);
				}

				qe = st;
				push(qe);
			}

		}

	}

}
void Keper::get()
{
	int schet = 1;
	cout << "Количество элементов size = " << size << endl;
	cout << "Элементы : "<<endl;
	for (int i = 0; i < size; i++)
	{
		cout << "элемент номер " << schet++<<endl;
		cout << "___________________________________________________________"<<endl;
		(*this)[i]->get();
		cout << "___________________________________________________________"<<endl;
	}
	cout << endl;
}
void Keper::push(queue* a)
{
	elem2* newHead;
	newHead = new elem2;
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
int Keper::sizeGet()
{
	return size;
}