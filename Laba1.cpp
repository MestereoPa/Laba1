#include "stack.h"
#include "list.h"
#include "deque.h"
#include "Keper.h"
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
		cout << "меню" << endl << "выбирете действие" << endl << "1 - создать новое элемент\n2 - работать с существующими\n3 - загрузить из файла\n4 - выгрузить в файл\n5 - вывод данных на экран";
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
					li ->set();
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
			Kep.get();
			
			break;
		case '3':
			Kep.load();
			break;
		case '4':
			Kep.save();
			break;
		case '5':
			
			cout << "Количество элементов size = " << Kep.sizeGet() << endl;
			cout << "Элементы : " << endl;
			for (int i = 0; i < Kep.sizeGet(); i++)
			{
				cout << "элемент номер " << schet++ << endl;
				cout << "___________________________________________________________" << endl;
				Kep[i]->get();
				cout << "___________________________________________________________" << endl;
			}
			cout << endl;
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