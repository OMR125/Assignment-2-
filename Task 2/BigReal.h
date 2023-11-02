#include <bits./stdc++.h>

#ifndef BIGREAL_BIGREAL_H
#define BIGREAL_BIGREAL_H

using namespace std;

class BigReal {
private:
    string s;

    bool isValidReal(string realNumber);

    int sign;
public:
    BigReal(string realNumber = "0");

    BigReal(const BigReal &other);

    void setNum(string realNumber);

    pair <BigReal, BigReal> equalize(const BigReal &b) const;

    void del();

    int size();

    BigReal operator+(const BigReal &other) const;

    void operator+=(BigReal other);

    BigReal operator-(const BigReal &other) const;

    void operator-=(BigReal other);

    bool operator<(const BigReal &other) const;

    bool operator>(const BigReal &other) const;

    bool operator>=(const BigReal &other) const;

    bool operator<=(const BigReal &other) const;

    bool operator!=(const BigReal &other) const;

    bool operator==(const BigReal &other) const;

    friend ostream &operator<<(ostream &out, BigReal other);
};


#endif
