#include "stdafx.h" 
#include <iostream> 
using namespace std;

struct Employee//Работник фирмы
{
	char Name[20];
	char Phone[20];
	char Language[20];
};

void Print(struct Employee e) //функция вывода на консоль работника
{
	cout << "Name: " << e.Name << ", Phone: " << e.Phone;
	cout << ", Language: " << e.Language;
	cout << endl;
}
void Delete(int n, struct Employee *dB, int max)//функция удаления работника с номером n
{
	for (int i = n; i < max; i++)
		dB[i] = dB[i + 1];
}

void main()
{
	struct Employee dB[10];//Массив структур - список работников
	int last = -1;//будет показывать индекс последнего работника в списке
	int Choise;

	cout << "1-Add employee, 2-Delete, 3-Print, 0-Exit\nChoose: ";
	cin >> Choise;//Пользователь вводит команду

	while (Choise)//Пока он не введёт 0, программа будет повторяться
	{
		cout << endl;
		switch (Choise)
		{
		case 1://Добавить работника
			last++;
			cout << "Name, Phone, Language: " << endl;
			cin >> dB[last].Name >> dB[last].Phone >> dB[last].Language;
			break;
		case 2://Удалить работника
			cout << "Numer of person: ";
			int x;
			cin >> x;
			if (x <= last)
			{
				Delete(x, dB, last);
				last--;
				cout << "Success!" << endl;
			}
			else
				cout << "Wrong number!" << endl;
			break;
		case 3://Вывод всего списка работников
			for (int i = 0; i <= last; i++)
			{
				cout << i << ':';
				Print(dB[i]);
			}
			break;
		default://Неправильная команда
			cout << "Wrong!" << endl;
		}
		cout << endl << "Choose: ";
		cin >> Choise;
	}
}