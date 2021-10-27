#include "stack.h"
#include "list.h"
#include "deque.h"
#include "Keper.h"
void rabSklass(queue* elemee);
int main(void)
{
	char choise, choise1;
	int ind, ind2, schet = 1;
	string zam;
	Keper Kep;
	queue* Ke;
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
			cout << "какой класс создать\n1 - дек\n2 - лист\n3 - стек\n";
			cin >> choise1;
			cin.ignore(32767, '\n');
			if (choise1 == '1')
			{
				deque* de;
				de = new deque;
				Ke = de;
				de->set();
				Kep.push(Ke);
			}
			else
			{
				if (choise1 == '2')
				{
					list* li;
					li = new list;
					Ke = li;
					li->set();
					Kep.push(Ke);
				}
				else
				{
					if (choise1 == '3')
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
			break;
		case '2':


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
				if (ind < 0 || ind>= Kep.sizeGet())
				{
					throw exception("неверный индекс");
				}
				rabSklass(Kep[ind]);
			}
			catch (const std::exception& ex)
			{
				cout << "Ошибка " << ex.what() << endl;
			}
			break;
		case '3':
			Kep.get();
			cout << "Введите индекс удаляемого элемента : ";
			cin >> ind;
			Kep.del(ind);
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

}
void rabSklass(queue* inputElem)
{
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
			inputElem->get();
			inputElem->push();
			break;
		case '2':
			inputElem->get();
			a = inputElem->pop();
			cout << "извлеченный элемент" << endl;
			cout << a << endl;
			break;
		case '3':
			inputElem->get();
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