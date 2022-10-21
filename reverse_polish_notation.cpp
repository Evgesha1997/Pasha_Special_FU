#include"reverse_polish_notation.h"
int in_vector(vector<char> v, char value) {
	int f = -1;
	for (int i = 0; i < v.size(); i++) {
		if (value == v[i]) {
			f = i;
			return f;
		}
	}
	return f;
}
int give_closing_bracket(string& str, int idx) {
	int count = 1;
	while (count != 0) {
		idx++;
		if (str[idx] == '(')
			count++;
		else if (str[idx] == ')')
			count--;
	}
	return idx;
}

void processing_of_string(string& expression) {
	int balance = 0, idx = 0, count;
	for (int i = 0; i < expression.size(); i++) {
		if (expression[i] == '(')
			balance++;
		if (expression[i] == ')') {
			balance--;
			if (balance < 0)
				throw exception("Не верно расставлены скобки");
		}
	}
	if (balance > 0) throw exception("Не верно расставлены скобки");

	while (idx < expression.size()) {
		if (expression[idx] == ' ') {
			count = 1;
			while ((idx + count) < expression.size() and expression[idx + count] == ' ')
				count++;
			expression.erase(idx, count);
		}
		idx++;
	}
	if (expression[0] == '-')
		expression[0] = '!';
	for (int i = 1; i < expression.size(); i++) {
		if (expression[i] == '-' and expression[i - 1] == '(')
			expression[i] = '!';
	}
}

string reverse_polish_notationL(string& expression, vector<char>& operators, vector<int> priorities) {
	string rezult;
	int gap_index = -1;
	int min_priority = operators.size();
	if (expression.size() == 0)
		return "";
	//Если выражение заключено в общие скобки то их убираем
	while (true) {
		if (expression[0] == '(') {
			int i = give_closing_bracket(expression, 0);
			if (i == expression.size() - 1) {
				expression.erase(0, 1);
				expression.erase(expression.size() - 1);
			}
			else break;
		}
		else break;
	}

	//Находим последнюю операцию с минимальным приоритетом (gap_index - индекс )
	for (int i = 0; i < expression.size(); i++) {
		if (expression[i] == '(') {
			i = give_closing_bracket(expression, i);
			continue;
		}
		if (expression[i] == '[') {
			while (i < expression.size() and expression[i] != ']') {
				i++;
			}
			continue;
		}
		int f = in_vector(operators, expression[i]);
		if (f != -1) {
			if (priorities[f] <= min_priority) {
				gap_index = i;
				min_priority = priorities[f];
			}
		}
	}

	//Если не нашли знаков операций , то интерпретируем это как переменную
	if (gap_index == -1)
		return expression + " ";
	string expressionL(expression, 0, gap_index);
	string expressionR;
	//Добавляем к результату последнюю неучтённую часть , учитывая при этом , 
	//что последний знак операции с нужным приоритетом может оказаться на конце выражения.
	if (gap_index < expression.size() - 1)
		expressionR.append(expression, gap_index + 1, expression.size() - gap_index);
	else expressionR = "";
	return reverse_polish_notation(expressionL, operators, priorities) + reverse_polish_notation(expressionR, operators, priorities) + expression[gap_index];
}

string reverse_polish_notation(string& expression, vector<char>& operators, vector<int> priorities) {
	processing_of_string(expression);
	string expressionL = reverse_polish_notationL(expression, operators, priorities);
	return expressionL;
}