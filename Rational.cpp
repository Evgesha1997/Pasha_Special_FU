#include "Rational.h"

Rational::Rational() {
    _m = 0;
    _n = 1;
}
Rational::Rational(int n, int m) {
    _m = n;
    _n = m;
}
Rational::Rational(const Rational& cl_obj) {
    _m = cl_obj._m;
    _n = cl_obj._n;
}

const Rational& Rational::operator =(const Rational& cl_obj) {
    if (&cl_obj == this)
        return *this;
    else {
        _m = cl_obj._m;
        _n = cl_obj._n;
    }
}
bool Rational::operator >(const Rational& obj) {
    if (_m * obj._n > obj._m * _n)
        return true;
    else
        return false;
}
bool Rational::operator <(const Rational& obj) {
    if (_m * obj._n < obj._m * _n)
        return true;
    else
        return false;
}
Rational Rational::operator +(const Rational& obj) {
    int m, n;
    m = (_m * obj._n + obj._m * _n) / gcd(_m * obj._n + obj._m * _n, _n * obj._n);
    n = (_n * obj._n) / gcd(_m * obj._n + obj._m * _n, _n * obj._n);
    return Rational(m, n);
}
Rational Rational::operator -(const Rational& obj) {
    int m, n;
    m = (_m * obj._n - obj._m * _n) / gcd(_m * obj._n - obj._m * _n, _n * obj._n);
    n = (_n * obj._n) / gcd(_m * obj._n - obj._m * _n, _n * obj._n);
    return Rational(m, n);
}
Rational Rational::operator *(const Rational& obj) {
    int m, n;
    m = (_m * obj._m) / gcd(_m * obj._m, _n * obj._n);
    n = (_n * obj._n) / gcd(_m * obj._m, _n * obj._n);
    return Rational(m, n);
}
Rational Rational::operator /(const Rational& obj) {
    int m, n;
    m = (_m * obj._n) / gcd(_m * obj._n, _n * obj._m);
    n = (_n * obj._m) / gcd(_m * obj._n, _n * obj._m);
    return Rational(m, n);
}
void Rational::operator !() {
    int m, n;
    _m = -1 * this->_m;
    _n = this->_n;
    return;
}
// функция возведения рационального числа в целочисленную степень
// вызывать обязательно в скобках! Пример: (rn1 ^ 3)
Rational Rational::operator ^(const Rational& obj) {
    long long temp_m = 1, temp_n = 1;
    int m, n;
    for (int i = 0; i < obj._m; i++) {
        temp_m *= _m;
        temp_n *= _n;
    }
    m = temp_m / gcd(temp_m, temp_n);
    n = temp_n / gcd(temp_m, temp_n);
    return Rational(m, n);
}

void Rational::extract(string& str) {
    int rez = 0, idx = 0;
    if (str[idx] != '0')
        while (int(str[idx]) <= 57 and int(str[idx]) >= 48 and idx < str.size()) {
            rez = rez * 10 + int(str[idx]) - 48;
            idx++;
        }
    else
        throw exception("Некорректный ввод выражения");
    _m = rez;
    if (str[idx] == '|') {
        idx++;
        rez = 0;
        if (str[idx] != '0')
            while (int(str[idx]) <= 57 and int(str[idx]) >= 48 and idx < str.size()) {
                rez = rez * 10 + int(str[idx]) - 48;
                idx++;
            }
        else
            throw exception("Некорректный ввод выражения");
        _n = rez;

    }
    else if (str[idx] == ' ')
        _n = 1;
    else
        throw exception("Некорректный ввод выражения");

    str.erase(str.begin(), str.begin() + idx + 1);
    return;
}