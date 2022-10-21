#ifndef _COMPLEX_
#define _COMPLEX_
#include<string>
#include<iostream>
using namespace std;
//Функция возведения в степень 
double power(double a, int p);
// Извлекает из строки число типа double но не удаляет , а возвращает индекс конца в переменную id
//Вспомогательная для extract(string& str) класса complex
double extract_double_num(const string& str, int& idx);
class complex {
public:
	double Re;
	double Im;
	complex() : Re(0), Im(0) {}
	//Функция ручной установки значений
	void set(double R, double I);
	//Функция печати на консоль
	void print();
	//Функция извлекает комплекс. из начала строки и удаляет в случае успеха , иначе кидает exception
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