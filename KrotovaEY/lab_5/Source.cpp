#include <iostream>
#include <conio.h>
using namespace std;

void cl(int *mass, int *mass2, int *mass3, int ctr, int stlb, const int size)
{
	for (int i = 0; i < ctr; ++i)
	{
		for (int g = 0; g < stlb; ++g)
		{
			*(mass3 + (i * size) + g) = *(mass + (i * size) + g) + *(mass2 + (i * size) + g);
		}
	}
}

void V(int *mass, int *mass2, int *mass3, int ctr, int stlb, const int size)
{
	for (int i = 0; i < ctr; ++i)
	{
		for (int g = 0; g < stlb; ++g)
		{
			*(mass3 + (i * size) + g) = *(mass + (i * size) + g) - *(mass2 + (i * size) + g);
		}
	}
}

void Umn(int *mass, int *mass2, int *mass3, int ctr1, int stlb1, int ctr2, int stlb2, const int size)
{
	for (int i = 0; i < ctr1;++i)
	{
		for (int g = 0; g < stlb2;++g)
		{
			for (int y = 0; y < stlb1; ++y)
			{
				*(mass3 + (i * size) + g) += (*(mass + (i*size) + y))*(*(mass2 + (y*size) + g));
			}
		}
	}
}
int main()
{
	char exit = '1';
	while (exit!=27)
	{
		setlocale(0, "");
		const int size = 100;
		int A[size][size];
		int B[size][size];
		int ctr1, ctr2, stlb1, stlb2;
		cout << "������� ���������� ����� ������� �������: ";
		cin >> ctr1;
		cout << "������� ���������� �������� ������� �������: ";
		cin >> stlb1;
		for (int i = 0; i < ctr1; ++i)
		{
			cout << "������� " << i + 1 << " ������ �������" << endl;
			for (int g = 0; g < stlb1; ++g)
			{
				cin >> A[i][g];
			}
			cout << endl;
		}
		cout << "������� ���������� ����� ������� �������: ";
		cin >> ctr2;
		cout << "������� ���������� �������� ������� �������: ";
		cin >> stlb2;
		for (int i = 0; i < ctr2; ++i)
		{
			cout << "������� " << i + 1 << " ������ �������" << endl;
			for (int g = 0; g < stlb2; ++g)
			{
				cin >> B[i][g];
			}
			cout << endl;
		}
		int C[size][size] = { 0 };
		char znak;
		cout << "�������� ��������(+,-,*) ";
		cin >> znak;
		cout << "���������: " << endl;
		switch (znak) {
		case '+':
			if (ctr1 == ctr2 && stlb1 == stlb2)
			{
				cl(*A, *B, *C, ctr1, stlb1, size);
				for (int i = 0; i < ctr1; ++i)
				{
					for (int g = 0; g < stlb1; ++g)
					{
						cout << C[i][g] << "  ";
					}
					cout << endl;
				}
			}
			else
			{
				cout << "���������� �������";
			}
			break;
		case'-':
			if (ctr1 == ctr2 && stlb1 == stlb2)
			{
				V(*A, *B, *C, ctr1, stlb1, size);
				for (int i = 0; i < ctr1; ++i)
				{
					for (int g = 0; g < stlb1; ++g)
					{
						cout << C[i][g] << "  ";
					}
					cout << endl;
				}
			}
			else
			{
				cout << "���������� �������";
			}
			break;
		case'*':
			if (ctr2 == stlb1)
			{
				Umn(*A, *B, *C, ctr1, stlb1, ctr2, stlb2, size);
				for (int i = 0; i < ctr1; ++i)
				{
					for (int g = 0; g < stlb2; ++g)
					{
						cout << C[i][g] << "  ";
					}
					cout << endl;
				}
			}
			else
			{
				cout << "���������� �����������";
			}
			break;
		default:
			cout << "������������ ����";
		}
		cout << endl;
		cout << "��� ����������� ������� ����� �������, ��� ������ ������� ESC";
		exit = _getch();
		cout << endl;
	}
	return 0;
}