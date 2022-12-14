#ifndef _RATIONAL_
#define _RATIONAL_
#include <iostream>
#include <cmath>
using namespace std;

// ??????????? ?????????, ???????????? greatest common divisor (???)
static int gcd(int a, int b) {
    a = abs(a), b = abs(b);
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

class Rational {
private:
    int _m, _n;
public:
    // ?? ?????????
    Rational();
    // ?? ?????
    Rational(int n, int m);
    // ???????????
    Rational(const Rational& cl_obj);
    ~Rational() {}

    int get_numerator() const { return _m; }
    int get_denominator() const { return _n; }

    const Rational& operator =(const Rational& cl_obj);
    bool operator >(const Rational& obj);
    bool operator <(const Rational& obj);
    Rational operator +(const Rational& obj);
    Rational operator -(const Rational& obj);
    Rational operator *(const Rational& obj);
    Rational operator /(const Rational& obj);
    void operator !();

    // ???????? ???????? ??????????? ? ???????! ??????: (rn1 ^ 3)
    Rational operator ^(const Rational& obj);

    friend ostream& operator <<(ostream&, const Rational&);
    friend istream& operator >>(istream&, Rational&);

    void extract(string& str);
};

inline ostream& operator <<(ostream& output, const Rational& obj) {
    output << obj._m << " / " << obj._n << endl;
    return output;
}
inline istream& operator >>(istream& input, Rational& obj) {
    input >> obj._m;
    input >> obj._n;
    return input;
}

#endif //_RATIONAL_