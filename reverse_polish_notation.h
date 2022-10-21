#ifndef _REVERSE_POLISH_NOTATION_
#define _REVERSE_POLISH_NOTATION_

#include<vector>
#include<string>
using namespace std;
//��������� ������� � ������� ������� ��������
int in_vector(vector<char> v, char value);
//��������� ������ ��������� ���������� ,  ��������� �� ����������� ������ , � ����� ������� ��� �������
void processing_of_string(string& expression);
//���������� ������ ����������� ������ � ������
int give_closing_bracket(string& str, int idx);
//������� ��� ����������� �� �������� �������� �������
string reverse_polish_notationL(string& expression, vector<char>& operators, vector<int> priorities);
//������ � ������� ����� ���������� ��������������� ���������
string reverse_polish_notation(string& expression, vector<char>& operators, vector<int> priorities);

#endif // _REVERSE_POLISH_NOTATION_