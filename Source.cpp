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
			cout << "Введено либо не число , либо число вышло за допустимые значения , повторите ввод : ";
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
			cout << "Выберете тип чисел для работы :" << endl;
			cout << " Комплексные числа  - 1" << endl;
			cout << " Рациональные числа - 2" << endl;
			cout << " Длинная арифметика - 3" << endl;
			cout << " Завершение работы программы - 4" << endl;
			cout << "Введите ключ : ";
			dialog_tmp = get_norm_input();
			system("cls");
			switch (dialog_tmp) {
			case 1:
				cout << "Вы выбрали комплексные числа!" << endl << "Формат ввода каждого числа: [a,b], где  a и b рациональные числа вида ****.****" << endl;
				cout << "Введите выражение комплексных чисел: " << endl;
				getline(cin, expression);
				getline(cin, expression);
				OPZ = reverse_polish_notation(expression, operators, priorities);
				complex_calc(OPZ);
				break;
			case 2:
				cout << "Вы выбрали рациональные числа!" << endl << "Формат ввода каждого числа: a|b , где  a - целое, b - натуральное" << endl;
				cout << "Введите выражение рациональных чисел: " << endl;
				getline(cin, expression);
				getline(cin, expression);
				OPZ = reverse_polish_notation(expression, operators, priorities);
				rational_calc(OPZ);
				break;
			case 3:
				cout << "Вы выбрали длинную арифметику!" << endl << "Формат ввода каждого числа вида ****.****" << endl;
				cout << "Введите выражение: " << endl;
				getline(cin, expression);
				getline(cin, expression);
				OPZ = reverse_polish_notation(expression, operators, priorities);
				long_calc(OPZ);
				break;
			case 4:
				cout << "Вы успешно завершили работу программы!" << endl;
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