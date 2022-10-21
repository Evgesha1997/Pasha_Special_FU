#include"Complex.h"
double power(double a, int p) {
	double rez = 1;
	for (int i = 0; i < p; i++)
		rez = rez * a;
	return rez;
}
double extract_double_num(const string& str, int& idx) {
	double rez = 0;
	int f = 1;
	if (str[idx] == '-' and str[idx + 1] != ',' and str[idx + 1] != ']') {
		f = -1;
		idx++;
	}
	if (str[idx] != '0') {
		int step = 0;
		while (int(str[idx]) <= 57 and int(str[idx]) >= 48 and idx < str.size()) {
			rez = rez * 10 + double(str[idx]) - 48;
			idx++;
			step++;
		}
		if (str[idx] == '.') {
			idx++;
			step = 1;
			while (int(str[idx]) <= 57 and int(str[idx]) >= 48 and idx < str.size()) {
				rez = rez + (double(str[idx]) - 48) / power(10, step);
				idx++;
				step++;
			}
		}
		return rez * f;
	}
	idx++;
	return 0;
}

void complex::set(double R, double I) {
	Re = R;
	Im = I;
}
void complex::print() {
	cout << Re << " + " << Im << "i\n";
}
void complex::extract(string& str) {
	int count = 1, lc = 1;
	if (str.size() < 5)
		throw exception("Не верный формат ввода");
	if (str[0] == '[') {
		this->Re = extract_double_num(str, count);
		if (str[count] != ',' or count == lc) throw exception("Не верный формат ввода");
		count++;
		lc = count;
		this->Im = extract_double_num(str, count);
		if (str[count] != ']' or count == lc) throw exception("Не верный формат ввода");
		str.erase(str.begin(), str.begin() + count + 1);
	}
	else throw exception("Не верный формат ввода");
}
complex complex::operator +(complex c2) {
	complex tmp;
	tmp.set(this->Re + c2.Re, this->Im + c2.Im);
	return tmp;
}
complex complex::operator -(complex c2) {
	complex tmp;
	tmp.set(this->Re - c2.Re, this->Im - c2.Im);
	return tmp;
}
complex complex::operator !() {
	complex tmp;
	tmp.set(-(this->Re), -(this->Im));
	return tmp;
}
complex complex::operator *(complex c2) {
	complex tmp;
	tmp.set((this->Re) * (c2.Re) - (this->Im) * (c2.Im), (this->Re) * (c2.Im) + (this->Im) * (c2.Re));
	return tmp;
}
complex complex::operator /(complex c2) {
	complex tmp;
	if (c2.Re == 0 and c2.Im == 0)
		throw exception("В результате вычислений произошло деление на ноль");
	tmp.set(((this->Re) * (c2.Re) + (this->Im) * (c2.Im)) / (c2.Re * c2.Re + c2.Im * c2.Im), ((this->Im) * (c2.Re) - (this->Re) * (c2.Im)) / (c2.Re * c2.Re + c2.Im * c2.Im));
	return tmp;
}
complex complex::operator =(complex cm)
{
	Re = cm.Re;
	Im = cm.Im;
	return *this;
}