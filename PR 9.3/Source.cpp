// Lab_9_3.cpp
// ������� ³�����
// ����������� ������ � 9.3
// ����������� ������ ��������
// ������ 7

#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>
#include <fstream>


using namespace std;



struct Tovar
{
	string name;
	string market;
	int price;
	int kilk;
	string mass;

};


void Create(Tovar* p, const int N);
void Print(Tovar* p, const int N);
void SortByName(Tovar* p, const int N);
void SortByMarket(Tovar* p, const int N);
void SearchByName(Tovar* p, const int N, const string name);
void PrintSerchByName(Tovar tmp);
void SearchByMarket(Tovar* p, const int N, const string market);
void PrintSearchByMarket(Tovar tmp);
void SaveToFile(Tovar* p, const int N, const char* filename);
void LoadFromFile(Tovar*& p, int& N, const char* filename);
void Remove(Tovar* p, int& N);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N;
	string name;
	string market;
	char filename[100];
	cout << "������ ������� ������ N: "; cin >> N;

	Tovar* p = new Tovar[N];

	int menuItem;
	do {
		cout << endl << endl;
		cout << "������� ��:" << endl << endl;
		cout << " [1] - �������� ����� � ���������" << endl;
		cout << " [2] - ���� ����� �� �����" << endl;
		cout << " [3] - ���������� �� ���� ������" << endl;
		cout << " [4] - ���������� �� ���� ��������" << endl;
		cout << " [5] - ����� ������ �� ����" << endl;
		cout << " [6] - ����� ������ �� ���� ��������" << endl;
		cout << " [7] - ����� ����� � ����" << endl;
		cout << " [8] - ���������� ����� �� �����" << endl;
		cout << " [9] - �������� �����" << endl;
		cout << " [0] - ����� �� ���������� ������ ��������" << endl << endl;
		cout << "������ ��������: "; cin >> menuItem;
		cout << endl << endl << endl;
		switch (menuItem)
		{
		case 1:
			Create(p, N);
			break;
		case 2:
			Print(p, N);
			break;
		case 3:
			SortByName(p, N);
			break;
		case 4:
			SortByMarket(p, N);
			break;
		case 5:
			cin.get();
			cin.sync();
			cout << " ����� ������ : "; getline(cin, name);
			cout << endl;
			SearchByName(p, N, name);
			break;
		case 6:
			cin.get();
			cin.sync();
			cout << " ����� �������� : "; getline(cin, market);
			cout << endl;
			SearchByName(p, N, market);
			break;
		case 7:
			cin.get();
			cin.sync();

			cout << "������ ��'� �����: "; cin.getline(filename, 99);
			SaveToFile(p, N, filename);
			break;
		case 8:
			cin.get();
			cin.sync();
			cout << "������ ��'� �����: "; cin.getline(filename, 99);
			LoadFromFile(p, N, filename);
			break;
		case 9:
			Remove(p, N);
			break;
		case 0:
			break;
		default:
			cout << "�� ����� ��������� ��������! "
				"��� ������ ����� - ����� ��������� ������ ����" << endl;
		}
	} while (menuItem != 0);

	return 0;

}

void Create(Tovar* p, const int N)
{

	for (int i = 0; i < N; i++)
	{
		cout << " � " << i + 1 << ":" << endl;
		cin.get();
		cin.sync();
		cout << " ����� : "; getline(cin, p[i].name);
		cout << " ����� �������� : "; getline(cin, p[i].market);
		cout << " ������ ��������� :"; getline(cin, p[i].mass);
		cout << " ֳ��: "; cin >> p[i].price;
		cout << " ʳ������: "; cin >> p[i].kilk;
		cout << endl;


	}
}

void Print(Tovar* p, const int N)
{
	cout << "==================================================================================================="
		<< endl;
	cout << "                          ������ ������" << endl;

	cout << "==================================================================================================="
		<< endl;
	cout << "|  � |      �����     |    ����� ��������   |  ֳ�� �� ��. (���) | ʳ������ | ������ ��������� |"
		<< endl;
	cout << "---------------------------------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(2) << right << i + 1 << " ";
		cout << "| " << setw(13) << right << p[i].name << " ";
		cout << "| " << setw(15) << right << p[i].market << " "
			 << "| " << setw(18) << right << p[i].price << " "
			 << "| " << setw(9) << right << p[i].kilk << " "
		   	 << "| " << setw(19) << right << p[i].mass << " |" << endl;


	}
	cout << "==================================================================================================="
		<< endl;
	cout << endl;
}
void SortByName(Tovar* p, const int N)
{
	Tovar tmp;
	int Do;

	cout << "������� ��:" << endl << endl;
	cout << " [1] - �� � �� �" << endl;
	cout << " [2] - �� � �� �" << endl;
	cout << "������ ��������: "; cin >> Do;
	switch (Do)
	{
	case 1:
		for (int i0 = 0; i0 < N - 1; i0++)
			for (int i1 = 0; i1 < N - i0 - 1; i1++)
				if (p[i1].name > p[i1 + 1].name)
				{
					tmp = p[i1];
					p[i1] = p[i1 + 1];
					p[i1 + 1] = tmp;
				}
		break;
	case 2:
		for (int i0 = 0; i0 < N - 1; i0++)
			for (int i1 = 0; i1 < N - i0 - 1; i1++)
				if (p[i1].name < p[i1 + 1].name)
				{
					tmp = p[i1];
					p[i1] = p[i1 + 1];
					p[i1 + 1] = tmp;
				}
		break;

	default:
		cout << "�� ����� ��������� ��������! "
			"��� ������ ����� - ����� ��������� ������ ����" << endl;
	}
}

void SortByMarket(Tovar* p, const int N)
{
	Tovar tmp;
	int Do;

	cout << "������� ��:" << endl << endl;
	cout << " [1] - �� � �� �" << endl;
	cout << " [2] - �� � �� �" << endl;
	cout << "������ ��������: "; cin >> Do;
	switch (Do)
	{
	case 1:
		for (int i0 = 0; i0 < N - 1; i0++)
			for (int i1 = 0; i1 < N - i0 - 1; i1++)
				if (p[i1].market > p[i1 + 1].market)
				{
					tmp = p[i1];
					p[i1] = p[i1 + 1];
					p[i1 + 1] = tmp;
				}
		break;
	case 2:
		for (int i0 = 0; i0 < N - 1; i0++)
			for (int i1 = 0; i1 < N - i0 - 1; i1++)
				if (p[i1].market < p[i1 + 1].market)
				{
					tmp = p[i1];
					p[i1] = p[i1 + 1];
					p[i1 + 1] = tmp;
				}
		break;

	default:
		cout << "�� ����� ��������� ��������! "
			"��� ������ ����� - ����� ��������� ������ ����" << endl;
	}
}


void SearchByName(Tovar* p, const int N, const string name)
{
	int Left = 0, Right = N - 1, c;
	Tovar tmp;
	int i = 0;
	do {
		c = (Left + Right) / 2;
		if (p[c].name == name)
		{
			tmp.name = p[c].name;
			tmp.market = p[c].market;
			tmp.price = p[c].price;
			tmp.kilk = p[c].kilk;
			tmp.mass = p[c].mass;
			PrintSerchByName(tmp);
			i++;
			break;
		}


		if ((p[c].name < name))
		{
			Left = c + 1;
		}
		else
		{
			Right = c - 1;
		}

	} while (Left <= Right);

	if (i == 0)
	{
		cout << "������ ������ ����" << endl;
	}
}

void PrintSerchByName(Tovar tmp)
{
	cout << "==================================================================================================="
		<< endl;
	cout << "                          ������� �����" << endl;

	cout << "==================================================================================================="
		<< endl;
	cout << "|  � |      �����     |    ����� ��������   |  ֳ�� �� ��. (���) | ʳ������ | ������ ��������� |"
		<< endl;
	cout << "---------------------------------------------------------------------------------------------------"
		<< endl;

	
	cout << "| " << setw(13) << right << tmp.name << " "
		<< "| " << setw(15) << right << tmp.market << " "
		<< "| " << setw(18) << right << tmp.price << " "
		<< "| " << setw(9) << right << tmp.kilk << " "
		<< "| " << setw(19) << right << tmp.mass << " |" << endl;



	cout << "==================================================================================================="
		<< endl;
	cout << endl;
}

void SearchByMarket(Tovar* p, const int N, const string market)
{
	int Left = 0, Right = N - 1, c;
	Tovar tmp;
	int i = 0;
	do {
		c = (Left + Right) / 2;
		if (p[c].market == market)
		{
			tmp.name = p[c].name;
			tmp.market = p[c].market;
			tmp.price = p[c].price;
			tmp.kilk = p[c].kilk;
			tmp.mass = p[c].mass;
			PrintSearchByMarket(tmp);
			i++;
			break;
		}


		if ((p[c].market < market))
		{
			Left = c + 1;
		}
		else
		{
			Right = c - 1;
		}

	} while (Left <= Right);

	if (i == 0)
	{
		cout << "������ �������� ����" << endl;
	}
}

void PrintSearchByMarket(Tovar tmp)
{
	cout << "==================================================================================================="
		<< endl;
	cout << "                          ������� �������" << endl;

	cout << "==================================================================================================="
		<< endl;
	cout << "|  � |      �����     |    ����� ��������   |  ֳ�� �� ��. (���) | ʳ������ | ������ ��������� |"
		<< endl;
	cout << "---------------------------------------------------------------------------------------------------"
		<< endl;

	cout << "| " << setw(15) << right << tmp.market << " "
		 << "| " << setw(13) << right << tmp.name << " "
		 << "| " << setw(18) << right << tmp.price << " "
		 << "| " << setw(9) << right << tmp.kilk << " "
		 << "| " << setw(19) << right << tmp.mass << " |" << endl;



	cout << "==================================================================================================="
		<< endl;
	cout << endl;
}



void Remove(Tovar* p, int& N)
{
	int K = N - 1;
	string name;
	cin.get();
	cin.sync();
	cout << " ������ ����� ������, ���� ������ �������� : "; getline(cin, name);

	Tovar* t = new Tovar[K];
	int j = 0;

	for (int i = 0; i < N; i++)
		if (name == p[i].name)
		{
			t[j + 1].name = p[i].name;
			t[j + 1].market = p[i].market;
			t[j + 1].price = p[i].price;
			t[j + 1].kilk = p[i].kilk;
			t[j + 1].mass = p[i].mass;
		}


	delete[] p;
	p = t;
	N = K;
}

void SaveToFile(Tovar* p, const int N, const char* filename)
{
	ofstream fout(filename, ios::binary);

	fout.write((char*)&N, sizeof(N));

	for (int i = 0; i < N; i++)
		fout.write((char*)&p[i], sizeof(Tovar));

	fout.close();
}
void LoadFromFile(Tovar*& p, int& N, const char* filename)
{
	delete[] p;

	ifstream fin(filename, ios::binary);

	fin.read((char*)&N, sizeof(N));

	p = new Tovar[N];

	for (int i = 0; i < N; i++)
		fin.read((char*)&p[i], sizeof(Tovar));

	fin.close();
}
