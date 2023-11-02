#include <bits./stdc++.h>

#ifndef BIGREAL_BIGREAL_H
#define BIGREAL_BIGREAL_H

using namespace std;

class BigReal {
private:
    string s;

    bool isValidReal(string realNumber);

public:
    BigReal(string realNumber = "0");

    BigReal(const BigReal &other);

    void setNum(string realNumber);

    pair <BigReal, BigReal> equalize(BigReal b);

    void del();

    int size();

    int sign();

    BigReal operator+(BigReal &other);

    void operator+=(BigReal other);

    BigReal operator-(BigReal &other);

    void operator-=(BigReal other);

    bool operator<(BigReal &other);

    bool operator>(BigReal &other);

    bool operator==(BigReal &other);

    friend ostream &operator<<(ostream &out, BigReal other);
};


#endif
