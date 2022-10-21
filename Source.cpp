#include<iostream>
#include<string>
#include<vector>
#include <windows.h>
#include"reverse_polish_notation.h"
#include"calculation.h"
using namespace std;

int get_norm_input() {
	while (true) {
		int value;
		cin >> value;
		if (cin.fail() or value <= 0 or value > 4) {
			cout << "������� ���� �� ����� , ���� ����� ����� �� ���������� �������� , ��������� ���� : ";
			cin.clear();
			cin.ignore(32767, '\n');
		}
		else
			return value;
	}
}

// -(-[1,2]+[5,4])/[1 ,  1] =-3 + 1i
// -3 | 4 + 2 | 4
// (-(-(-(1))))

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int dialog_tmp = 0;
	string OPZ;
	string expression;
	vector<char> operators{ '-','+','/','*', '^', '!'};
	vector<int> priorities{ 0,0,1,1,2,3 };

	while (dialog_tmp != 4) {
		try {
			cout << "�������� ��� ����� ��� ������ :" << endl;
			cout << " ����������� �����  - 1" << endl;
			cout << " ������������ ����� - 2" << endl;
			cout << " ������� ���������� - 3" << endl;
			cout << " ���������� ������ ��������� - 4" << endl;
			cout << "������� ���� : ";
			dialog_tmp = get_norm_input();
			system("cls");
			switch (dialog_tmp) {
			case 1:
				cout << "�� ������� ����������� �����!" << endl << "������ ����� ������� �����: [a,b], ���  a � b ������������ ����� ���� ****.****" << endl;
				cout << "������� ��������� ����������� �����: " << endl;
				getline(cin, expression);
				getline(cin, expression);
				OPZ = reverse_polish_notation(expression, operators, priorities);
				complex_calc(OPZ);
				break;
			case 2:
				cout << "�� ������� ������������ �����!" << endl << "������ ����� ������� �����: a|b , ���  a - �����, b - �����������" << endl;
				cout << "������� ��������� ������������ �����: " << endl;
				getline(cin, expression);
				getline(cin, expression);
				OPZ = reverse_polish_notation(expression, operators, priorities);
				rational_calc(OPZ);
				break;
			case 3:
				cout << "�� ������� ������� ����������!" << endl << "������ ����� ������� ����� ���� ****.****" << endl;
				cout << "������� ���������: " << endl;
				getline(cin, expression);
				getline(cin, expression);
				OPZ = reverse_polish_notation(expression, operators, priorities);
				long_calc(OPZ);
				break;
			case 4:
				cout << "�� ������� ��������� ������ ���������!" << endl;
				break;
			}
			system("pause");
			system("cls");
		}
		catch (exception& ex) {
			cout << ex.what() << endl;
			system("pause");
			system("cls");
		}
	}

	return 0;
}