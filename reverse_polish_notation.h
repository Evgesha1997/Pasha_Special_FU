#ifndef _REVERSE_POLISH_NOTATION_
#define _REVERSE_POLISH_NOTATION_

#include<vector>
#include<string>
using namespace std;
//Проверяет наличие в векторе данного элемента
int in_vector(vector<char> v, char value);
//Обработка строки позволяет определить ,  правильно ли расставлены скобки , а также удалить все пробелы
void processing_of_string(string& expression);
//Возвращает индекс закрывающей скобки к данной
int give_closing_bracket(string& str, int idx);
//Функция для конвертации по обратной польской нотации
string reverse_polish_notationL(string& expression, vector<char>& operators, vector<int> priorities);
//Обёртка в которой также происходит предварительная обработка
string reverse_polish_notation(string& expression, vector<char>& operators, vector<int> priorities);

#endif // _REVERSE_POLISH_NOTATION_