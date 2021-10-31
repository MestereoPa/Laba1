#include "Menu.h"
int menu()
{
	char choise;
	Keper Kep;
	setlocale(LC_ALL, "rus");
	do {
		system("cls");
		cout << "меню" << endl << "выбирете действие" << endl << "1 - создать новый элемент\n2 - работать с уже существующими элементами\n3 - удаление элемента\n4 - загрузить из файла\n5 - выгрузить в файл\n6 - вывод данных на консоль";
		cout << endl;
		cin >> choise;
		cin.ignore(32767, '\n');
		switch (choise)
		{
		case '1':
			sozdKlass(Kep);
			break;
		case '2':
			rabSklass(Kep);
			break;
		case '3':
			deleteKlass(Kep);
			break;
		case '4':
			Kep.load();
			break;
		case '5':
			Kep.save();
			break;
		case '6':
			Kep.get();
			break;
		case '0':
			break;
		default:
			cout << "неверны ввод";
			break;
		}
		system("pause");
	} while (choise != '0');
	return 0;
}

void rabSklass(Keper& Kep)
{
	int ind;
	try
	{
		if (Kep.sizeGet() == 0)
		{
			throw exception("нет элементов");
		}
		Kep.get();
		cout << "с каким элементом работать введите индекс" << endl;
		cin >> ind;
		ind--;
		if (ind < 0 || ind >= Kep.sizeGet())
		{
			throw exception("неверный индекс");
		}
		char choise;
		int a;
		float newElem;
		setlocale(LC_ALL, "rus");
		do
		{
			system("cls");
			cout << "выберите действия\n 1 - добавить элемент\n 2 - извлечь элемент \n 3 - вывод данных на экран \n 0 - выход" << endl;

			cin >> choise;
			cin.ignore(32767, '\n');
			switch (choise)
			{
			case '1':
				Kep[ind]->get();
				Kep[ind]->push();
				break;
			case '2':
				Kep[ind]->get();
				a = Kep[ind]->pop();
				cout << "извлеченный элемент" << endl;
				cout << a << endl;
				break;
			case '3':
				Kep[ind]->get();
				break;
			case '0':
				break;
			default:
				cout << "неверны ввод";
				break;
			}
			system("pause");

		} while (choise != '0');
	}
	catch (const std::exception& ex)
	{
		cout << "Ошибка " << ex.what() << endl;
	}
}

void sozdKlass(Keper& Kep)
{
	char choise;
	queue* Ke;
	cout << "какой класс создать\n1 - дек\n2 - лист\n3 - стек\n";
	cin >> choise;
	cin.ignore(32767, '\n');
	if (choise == '1')
	{
		deque* de;
		de = new deque;
		Ke = de;
		de->set();
		Kep.push(Ke);
	}
	else
	{
		if (choise == '2')
		{
			list* li;
			li = new list;
			Ke = li;
			li->set();
			Kep.push(Ke);
		}
		else
		{
			if (choise == '3')
			{
				stack* st;
				st = new stack;
				Ke = st;
				st->set();
				Kep.push(Ke);
			}
			else
			{
				cout << "неправильный ввод" << endl;
			}
		}
	}
}
void deleteKlass(Keper& Kep)
{
	int ind;
	Kep.get();
	cout << "Введите индекс удаляемого элемента : ";
	cin >> ind;
	Kep.del(ind);
}