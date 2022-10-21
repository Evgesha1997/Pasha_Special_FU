#ifndef _LONG_ARIFM_
#define _LONG_ARIFM_
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

#define SIZE_LL 14
#define SIZE_CELL 100000000
using namespace std;
class Big_integer {
private:
	long long num[SIZE_LL];
public:
	Big_integer() {
		for (int i = 0; i < SIZE_LL; i++)
			num[i] = 0;
	}
	Big_integer(long long _num[SIZE_LL]) {
		for (int i = 0; i < SIZE_CELL; i++)
			num[i] = _num[i];
	}
	Big_integer(const Big_integer& cl_obj) {
		for (int i = 0; i < SIZE_LL; i++)
			num[i] = cl_obj.get_ind(i);
	}
	long long get_ind(int i) const {
		return num[i];
	}
	void set_ind(int i, long long x) {
		num[i] = x;
	}

	Big_integer& operator =(const Big_integer& cl_obj) {
		if (&cl_obj == this)
			return *this;
		else {
			for (int i = 0; i < SIZE_LL; i++)
				num[i] = cl_obj.num[i];
		}
		return *this;
	}

	void extract(string& str) {
		int idx = 0;
		while (int(str[idx]) <= 57 and int(str[idx]) >= 48 and idx < str.size()) {
			idx++;
		}
		if (str[idx] != ' ')
			throw exception("Некорректный ввод выражения");
		if (idx > 14 * 9 - 1)
			throw exception("При считывание будет переполнение");
		for (int i = 0; i < 14; i++) {
			for (int j = 0; j <= 8; j++) {
				if (idx - 1 - 9 * i - j < 0)
					break;
				num[i] += (int(str[idx - 1 - 9 * i - j]) - int('0')) * tpow(j);
			}
			if (idx - 1 - 9 * i < 0)
				break;
		}
		str.erase(str.begin(), str.begin() + idx);
		return;
	}

	long long tpow(int a) {
		long long rez = 1;
		for (int i = 0; i < a; i++)
			rez = rez * 10;
		return rez;
	}

	Big_integer operator +(Big_integer other) {
		Big_integer a;
		for (int i = 0; i < SIZE_LL; i++) {
			if (i != SIZE_LL - 1)
				a.set_ind(i + 1, a.get_ind(i + 1) + (a.get_ind(i) + other.get_ind(i) + num[i]) / SIZE_CELL);
			a.set_ind(i, (a.get_ind(i) + other.get_ind(i) + num[i]) % SIZE_CELL);
		}
		return a;
	}
	Big_integer operator -(Big_integer other) {
		Big_integer a;
		for (int i = 0; i < SIZE_LL; i++) {
			if (i != SIZE_LL - 1 && a.get_ind(i) + num[i] - other.get_ind(i) < 0) {
				a.set_ind(i + 1, a.get_ind(i + 1) - 1);
				a.set_ind(i, a.get_ind(i) + SIZE_CELL);
			}
			a.set_ind(i, a.get_ind(i) + num[i] - other.get_ind(i));
		}
		return a;
	}
	Big_integer operator *(Big_integer other) {
		Big_integer a;
		for (int i = 0; i < SIZE_LL; i++)
			for (int j = 0; j < SIZE_LL; j++)
				if (i + j < SIZE_LL)
					a.set_ind(i + j, a.get_ind(i + j) + num[i] * other.get_ind(j));
		for (int i = 0; i < SIZE_LL; i++) {
			if (i != SIZE_LL - 1)
				a.set_ind(i + 1, a.get_ind(i + 1) + a.get_ind(i) / SIZE_CELL);
			a.set_ind(i, a.get_ind(i) % SIZE_CELL);
		}
		return a;
	}
	friend ostream& operator <<  (ostream& os, const Big_integer& a) {
		int flag = 0;
		for (int i = SIZE_LL - 1; i >= 0; i--) {
			long long help = a.get_ind(i);
			if (flag == 1 && help * 10 < SIZE_CELL)
				if (help == 0)
					os << "00000000";
				else {
					while (help * 10 < SIZE_CELL) {
						os << 0;
						help *= 10;
					}
					os << a.get_ind(i);
				}
			else
				if (flag == 1 || flag == 0 && help != 0) {
					os << help;
					flag = 1;
				}
		}
		if (flag == 0)
			os << 0;
		return os;
	}
};

#endif //_LONG_ARIFM_