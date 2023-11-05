// File: task 2
// Purpose: perform operations on two big real numbers


// Author: omar mahfouz mohammed
// Section: s3/4
// ID: 20220229
// TA: belal tarek
// Date: nov 4 2023

// Author: medhat ahmed abdelkarim
// Section: s3/4
// ID: 20220456
// TA: belal tarek
// Date: nov 4 2023

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
    BigReal(string realNumber = "0");

    BigReal(const BigReal &other);

    void setNum(string realNumber);

    pair <BigReal, BigReal> equalize(const BigReal &b) const;

    void del();

    int size();

    BigReal operator+(const BigReal &other) const;

    void operator+=(BigReal other);

    BigReal operator++();

    BigReal operator-(const BigReal &other) const;

    void operator-=(BigReal other);

    BigReal operator--();

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
