#include "Menu.h"
int menu()
{
	char choise;
	Keper Kep;
	setlocale(LC_ALL, "rus");
	do {
		system("cls");
		cout << "����" << endl << "�������� ��������" << endl << "1 - ������� ����� �������\n2 - �������� � ��� ������������� ����������\n3 - �������� ��������\n4 - ��������� �� �����\n5 - ��������� � ����\n6 - ����� ������ �� �������";
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
			cout << "������� ����";
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
			throw exception("��� ���������");
		}
		Kep.get();
		cout << "� ����� ��������� �������� ������� ������" << endl;
		cin >> ind;
		ind--;
		if (ind < 0 || ind >= Kep.sizeGet())
		{
			throw exception("�������� ������");
		}
		char choise;
		int a;
		float newElem;
		setlocale(LC_ALL, "rus");
		do
		{
			system("cls");
			cout << "�������� ��������\n 1 - �������� �������\n 2 - ������� ������� \n 3 - ����� ������ �� ����� \n 0 - �����" << endl;

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
				cout << "����������� �������" << endl;
				cout << a << endl;
				break;
			case '3':
				Kep[ind]->get();
				break;
			case '0':
				break;
			default:
				cout << "������� ����";
				break;
			}
			system("pause");

		} while (choise != '0');
	}
	catch (const std::exception& ex)
	{
		cout << "������ " << ex.what() << endl;
	}
}

void sozdKlass(Keper& Kep)
{
	char choise;
	queue* Ke;
	cout << "����� ����� �������\n1 - ���\n2 - ����\n3 - ����\n";
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
				cout << "������������ ����" << endl;
			}
		}
	}
}
void deleteKlass(Keper& Kep)
{
	int ind;
	Kep.get();
	cout << "������� ������ ���������� �������� : ";
	cin >> ind;
	Kep.del(ind);
}