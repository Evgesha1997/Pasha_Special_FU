#include "Rational.h"
#include"Complex.h"
#include"Long_arifm.h"
#include"Stack.h"

void rational_calc(string& OPZ) {
	Stack<Rational> st;
	Rational temp1, temp2, result;

	while (OPZ.size() != 0) {
		if (OPZ[0] != '+' and OPZ[0] != '-' and OPZ[0] != '*' and OPZ[0] != '/' and OPZ[0] != '^' and OPZ[0] != '!') {
			temp1.extract(OPZ);
			st.push(temp1);
		}
		else {
			switch (OPZ[0])
			{
			case '!':
				temp1 = st.look_top();
				st.pop();
				!temp1;
				st.push(temp1);
				break;
			case '+':
				temp2 = st.look_top();
				st.pop();
				temp1 = st.look_top();
				st.pop();
				result = temp1 + temp2;
				st.push(result);
				break;
			case '-':
				temp2 = st.look_top();
				st.pop();
				temp1 = st.look_top();
				st.pop();
				result = temp1 - temp2;
				st.push(result);
				break;
			case '*':
				temp2 = st.look_top();
				st.pop();
				temp1 = st.look_top();
				st.pop();
				result = temp1 * temp2;
				st.push(result);
				break;
			case '/':
				temp2 = st.look_top();
				st.pop();
				temp1 = st.look_top();
				st.pop();
				result = temp1 / temp2;
				st.push(result);
				break;
			case '^':
				temp2 = st.look_top();
				st.pop();
				temp1 = st.look_top();
				st.pop();
				result = (temp1 ^ temp2);
				st.push(result);
				break;
			}
			OPZ.erase(OPZ.begin(), OPZ.begin() + 1);
		}
	}
	if (st.get_size() > 1)
		throw exception("Проверьте корректность введённого выражения и перезапустите этап вычислений!");
	cout << st.look_top() << endl;
}

void complex_calc(string& OPZ) {
	Stack<complex> st;
	complex temp1, temp2, result;
	while (OPZ.size() != 0) {
		if (OPZ[0] != '+' and OPZ[0] != '-' and OPZ[0] != '*' and OPZ[0] != '/' and OPZ[0] != '!') {
			temp1.extract(OPZ);
			st.push(temp1);
		}
		else {
			switch (OPZ[0])
			{
			case '!':
				// унарный минус
				temp1 = st.look_top();
				result = temp1 - temp1 - temp1;
				st.pop();
				st.push(result);
				break;

			case '+':
				temp2 = st.look_top();
				st.pop();
				temp1 = st.look_top();
				st.pop();
				result = temp1 + temp2;
				st.push(result);
				break;
			case '-':
				temp2 = st.look_top();
				st.pop();
				temp1 = st.look_top();
				st.pop();
				result = temp1 - temp2;
				st.push(result);
				break;
			case '*':
				temp2 = st.look_top();
				st.pop();
				temp1 = st.look_top();
				st.pop();
				result = temp1 * temp2;
				st.push(result);
				break;
			case '/':
				temp2 = st.look_top();
				st.pop();
				temp1 = st.look_top();
				st.pop();
				result = temp1 / temp2;
				st.push(result);
				break;
			}
		}
		OPZ.erase(OPZ.begin(), OPZ.begin() + 1);
	}
	if (st.get_size() > 1)
		throw exception("Проверьте корректность введённого выражения и перезапустите этап вычислений!");
	result = st.look_top();
	result.print();
}

void long_calc(string& OPZ) {
	Stack<Big_integer> st;
	Big_integer temp1, temp2, result;
	while (OPZ.size() != 0) {
		if (OPZ[0] != '+' and OPZ[0] != '-' and OPZ[0] != '*' and OPZ[0] != '/') {
			Big_integer tmp;
			tmp.extract(OPZ);
			st.push(tmp);
		}
		else {
			switch (OPZ[0])
			{
			case '+':
				temp2 = st.look_top();
				st.pop();
				temp1 = st.look_top();
				st.pop();
				result = temp1 + temp2;
				st.push(result);
				break;
			case '-':
				temp2 = st.look_top();
				st.pop();
				temp1 = st.look_top();
				st.pop();
				result = temp1 - temp2;
				st.push(result);
				break;
			case '*':
				temp2 = st.look_top();
				st.pop();
				temp1 = st.look_top();
				st.pop();
				result = temp1 * temp2;
				st.push(result);
				break;
			}
		}
		OPZ.erase(OPZ.begin(), OPZ.begin() + 1);
	}
	if (st.get_size() > 1)
		throw exception("Проверьте корректность введённого выражения и перезапустите этап вычислений!");
	cout << st.look_top() << endl;
}