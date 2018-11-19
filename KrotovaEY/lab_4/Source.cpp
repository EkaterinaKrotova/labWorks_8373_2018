#include <iostream>
#include <conio.h> 
using namespace std;

float stepen(float a, int b)
{
	float result=1;
	if (!a)
	{
		result = 0;
	}
	else if (b > 0)
	{
		for (int i = 0; i < b; i++)
		{
			result = result*a;
		}
	}
	else if (b < 0)
	{
		for (int i = 0; i > b; i--)
		{
			result = result*a;
		}
		result = 1 / result;
	}
	return result;
}
unsigned int factorial(unsigned int a)
{
	unsigned int factorial = 1;
	while (a > 0)
	{
		factorial *= a;
		--a;
	}
	return factorial;
}
bool prost(unsigned int t)
{
	bool result = 0;
	for (int i = 2; i < t; i++)
	{
		if (t%i == 0)
		{
			result = 1;
			break;
		}
	}
	return result;
}
float coren(float a)
{
	int v = 0;
	while (float(int(a))!=a)
	{
		a = a * 100;
			++v;
	}
	int d1, d2;
	float coren;
	for (int i = 1; i <= a; i++)
	{
		d1 = stepen(i, 2);
		d2 = stepen(i + 1, 2);
		if (d2 > a)
		{
			coren = i;
			break;
		}
	}
	coren = 0.5*(coren + a / coren);
	coren = 0.5*(coren + a / coren);
	coren = 0.5*(coren + a / coren);
	coren = coren / stepen(10, v);
	return coren;
}
int main()
{
	setlocale(0, "");
	float a;
	int b;
	cout << "������� ��� ���������� � �������: ";
	cin >> a;
	cout << "������� �������: ";
	cin >> b;
	cout << "���������: ";
	if (a || b)
	{
		cout << stepen(a, b) << endl;
	}
	else 
	{
		cout << "����������������" << endl;
	}
	unsigned int c;
	cout << "������� ����� ��� ���������� ���������� � �������� �� ��������: ";
	cin >> c;
	cout << "���������: " << factorial(c) << endl;
	if (prost(c))
	{
		cout << "����� �� �������� �������" << endl;
	}
	else
	{
		cout << "������� �����" << endl;
	}
	float f;
	cout << "������� ����� ��� ������ ����������� �����: ";
	cin >> f;
	cout << "���������: " << coren(f) << endl;
	_getch();
	return 0;
}