#include <iostream>
#include <conio.h> 
using namespace std;

int main()                       
{        
	setlocale(0, "");
	float left, right;
	cout << "������� ����� �������:";
	cin >> left;
	cout << "������� ������ �������:";
	cin >> right;
	char sign;
	cout << "������� ����:";
	cin >> sign;
	float result;
	switch (sign) {
	case '+': result = left + right;
		break;
	case'-': result = left - right;
		break;
	case'*': result = left * right;
		break;
	case'/': result = left / right;
		break;
	default:
		cout << "������������ ����";
	}
	if (right==0 && sign=='/')
	{
		cout << "�� ���� ������ ������";
	} 
	else if (sign=='+'||sign=='-'||sign=='*'||sign=='/')
	{
         cout << "���������: " << result; 
	}
     _getch();
	 return 0;
}