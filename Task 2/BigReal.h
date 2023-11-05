// File: task 2
// Purpose: perform operations on two big real numbers

// Author: Omar Mahfouz Mohammed
// Section: S3/4
// ID: 20220229
// TA: Belal Tarek
// Date: Nov 4 2023

// Author: Medhat Ahmed Abdelkarim
// Section: S3/4
// ID: 20220456
// TA: Belal Tarek
// Date: Nov 4 2023

//--------------------------------------------------------------------//
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
    BigReal(string Number = "0",bool change = 1);

    BigReal(const BigReal &other);

    void setNum(string Number = "0",bool change = 1);

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

    friend istream &operator>>(istream &in, BigReal &other);
};


#endif
