#ifndef _COMPLEX_
#define _COMPLEX_
#include<string>
#include<iostream>
using namespace std;
//������� ���������� � ������� 
double power(double a, int p);
// ��������� �� ������ ����� ���� double �� �� ������� , � ���������� ������ ����� � ���������� id
//��������������� ��� extract(string& str) ������ complex
double extract_double_num(const string& str, int& idx);
class complex {
public:
	double Re;
	double Im;
	complex() : Re(0), Im(0) {}
	//������� ������ ��������� ��������
	void set(double R, double I);
	//������� ������ �� �������
	void print();
	//������� ��������� ��������. �� ������ ������ � ������� � ������ ������ , ����� ������ exception
	void extract(string& str);
	complex operator +(complex c2);
	complex operator -(complex c2);
	complex operator *(complex c2);
	complex operator /(complex c2);
	complex operator =(complex cm);
	complex operator !();

	friend ostream& operator <<(ostream&, const complex&);
};

inline ostream& operator <<(ostream& output, const complex& obj) {
	output << obj.Re << " + " << obj.Im << "i\n";
	return output;
}
#endif // _COMPLEX_