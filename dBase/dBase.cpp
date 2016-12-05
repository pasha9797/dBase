#include "stdafx.h" 
#include <iostream> 
using namespace std;

struct Employee//�������� �����
{
	char Name[20];
	char Phone[20];
	char Language[20];
};

void Print(struct Employee e) //������� ������ �� ������� ���������
{
	cout << "Name: " << e.Name << ", Phone: " << e.Phone;
	cout << ", Language: " << e.Language;
	cout << endl;
}
void Delete(int n, struct Employee *dB, int max)//������� �������� ��������� � ������� n
{
	for (int i = n; i < max; i++)
		dB[i] = dB[i + 1];
}

void main()
{
	struct Employee dB[10];//������ �������� - ������ ����������
	int last = -1;//����� ���������� ������ ���������� ��������� � ������
	int Choise;

	cout << "1-Add employee, 2-Delete, 3-Print, 0-Exit\nChoose: ";
	cin >> Choise;//������������ ������ �������

	while (Choise)//���� �� �� ����� 0, ��������� ����� �����������
	{
		cout << endl;
		switch (Choise)
		{
		case 1://�������� ���������
			last++;
			cout << "Name, Phone, Language: " << endl;
			cin >> dB[last].Name >> dB[last].Phone >> dB[last].Language;
			break;
		case 2://������� ���������
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
		case 3://����� ����� ������ ����������
			for (int i = 0; i <= last; i++)
			{
				cout << i << ':';
				Print(dB[i]);
			}
			break;
		default://������������ �������
			cout << "Wrong!" << endl;
		}
		cout << endl << "Choose: ";
		cin >> Choise;
	}
}