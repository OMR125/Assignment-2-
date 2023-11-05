// File: Task 2
// Purpose: perform operations on two big real numbers


// Author: Omar Mahfouz Mohammed
// Section: S3/4
// ID: 20220229
// TA: belal tarek
// Date: Nov 4 2023

// Author: Medhat Ahmed Abdelkarim
// Section: S3/4
// ID: 20220456
// TA: Belal Tarek
// Date: Nov 4 2023

//--------------------------------------------------------------------//
#include <bits./stdc++.h>
#include "bigReal.h"

bool BigReal::isValidReal(string Number) {
    int cnt = 0;
    for (int i = 0; i < Number.size(); ++i) {
        if (Number[i] == '.') {
            cnt++;
        } else if (!(Number[i] >= '0' && Number[i] <= '9')) {
            return false;
        }
    }
    return cnt < 2;
}

BigReal::BigReal(string Number) {
    sign = 1;
    if (Number.find('.') == string::npos)
        Number += string(".0");

    if (Number[0] == '+' || Number[0] == '-') {
        sign = (Number[0] == '-' ? 0 : 1);
        Number = Number.substr(1);
    }
    if (Number[0] == '.')
        Number = '0' + Number;

    if (!isValidReal(Number))
        s = "0.0";
    else {
        s = Number;
        del();
    }
}

void BigReal::setNum(string Number) {
    sign = 1;
    if (Number.find('.') == string::npos)
        Number += string(".0");

    if (Number[0] == '+' || Number[0] == '-') {
        sign = (Number[0] == '-' ? 0 : 1);
        Number = Number.substr(1);
    }
    if (Number[0] == '.')
        Number = '0' + Number;

    if (!isValidReal(Number))
        s = "0.0";
    else {
        s = Number;
        del();
    }
}

BigReal::BigReal(const BigReal &other) {
    s = other.s;
    sign = other.sign;
}

void BigReal::del() {
    while (s[0] == '0' && s[1] != '.')
        s.erase(s.begin(), s.begin() + 1);

    while (s.back() == '0')
        s.pop_back();

    if (s.back() == '.')
        s.pop_back();
}

int BigReal::size() {
    return s.size();
}

bool BigReal::operator==(const BigReal &other) const {
    return s == other.s && sign == other.sign;
}

bool BigReal::operator!=(const BigReal &other) const {
    return !(*this == other);
}

bool BigReal::operator>(const BigReal &other) const {
    if (sign != other.sign)
        return sign > other.sign;
    pair <BigReal, BigReal> temp = equalize(other);
    string a = temp.first.s;
    string b = temp.second.s;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] > b[i])
            return (*this).sign;
        else if (a[i] < b[i])
            return !(*this).sign;
    }
    return false;
}

bool BigReal::operator>=(const BigReal &other) const {
    return *this > other || *this == other;
}

bool BigReal::operator<(const BigReal &other) const {
    return other > *this;
}

bool BigReal::operator<=(const BigReal &other) const {
    return *this < other || *this == other;
}

pair <BigReal, BigReal> BigReal::equalize(const BigReal &temp) const {
    BigReal a = *this;
    BigReal b = temp;
    int before_a = 0, after_a = 0;
    int before_b = 0, after_b = 0;
    bool first_half = 1;
    for (int i = 0; i < a.size(); i++) {
        if (a.s[i] == '.') {
            first_half = 0;
            continue;
        }
        if (first_half)before_a++;
        else after_a++;
    }
    first_half = 1;
    for (int i = 0; i < b.size(); i++) {
        if (b.s[i] == '.') {
            first_half = 0;
            continue;
        }
        if (first_half)before_b++;
        else after_b++;
    }
    if (before_a < before_b) {
        a.s = string(before_b - before_a, '0') + a.s;
    } else
        b.s = string(before_a - before_b, '0') + b.s;
    if (after_a < after_b) {
        a.s += string(after_b - after_a, '0');
    } else
        b.s += string(after_a - after_b, '0');
    BigReal n1(a);
    n1.sign = (*this).sign;
    BigReal n2(b);
    n2.sign = b.sign;
    return {n1, n2};
}

BigReal BigReal::operator+(const BigReal &other) const {
    pair <BigReal, BigReal> temp = equalize(other);
    string a = temp.first.s;
    string b = temp.second.s;
    string c;
    if (!(temp.first.sign && temp.second.sign)) {
        temp.second.sign ^= 1;
        return temp.first - temp.second;
    }
    int carry = 0;
    for (int i = a.size() - 1; i >= 0; i--) {
        if (a[i] == '.') {
            c.push_back('.');
            continue;
        }
        int digit1 = a[i] - '0';
        int digit2 = b[i] - '0';
        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        sum %= 10;
        c.push_back(sum + '0');
    }
    if (carry)c.push_back(carry + '0');
    reverse(c.begin(), c.end());
    if (c[c.size() - 2] == '.' && c[c.size() - 1] == '0') {
        c.pop_back();
        c.pop_back();
    }
    BigReal ans;
    ans.s = c;
    ans.sign = 1;
    return ans;
}

BigReal BigReal::operator-(const BigReal &other) const {
    pair <BigReal, BigReal> temp = equalize(other); // making both numbers the same length
    BigReal a = temp.first;
    BigReal b = temp.second;
    BigReal ans;
    ans.sign = 1;
    if (a.sign && !b.sign) { // a--b = a+b hence call the + operator 
        b.sign = 1;
        ans = a + b;
        return ans;
    }
    if (!a.sign && b.sign) { // -a-b = -(a+b) hence call the + operator but change the sign to negative
        a.sign = 1;
        ans = a + b;
        ans.sign = 0;
        return ans;
    }
    if (!a.sign && !b.sign) { // -a+b = b-a then ensure that b is bigger than a
        a.sign = b.sign = 1;
        if (b < a) {
            ans.sign = 0;
        } else swap(a.s, b.s);
    } else { // a-b then ensure a is bigger than b 
        a.sign = b.sign = 1;
        if (a < b) {
            swap(a.s, b.s);
            ans.sign = 0;
        }
    }
    string n1 = a.s;
    string n2 = b.s;
    string n3;
    int carry = 0;
    for (int i = n1.size() - 1; i >= 0; i--) {
        if (n1[i] == '.') {
            n3.push_back('.');
            continue;
        }
        int digit1 = n1[i] - '0';
        int digit2 = n2[i] - '0';
        int sub = digit1 - digit2 - carry; // subtracting digits with the carry 
        if (sub >= 0) { // if it's non-negative then it's possible to take the carry from this number then make carry =0
            n3.push_back(sub + '0');
            carry = 0;
        } else { 
            /* it's not possible to take the carry from this number so act like i took the carry and + 10 to it,
            carry still or became 1 */ 
            n3.push_back(sub + 10 + '0');
            carry = 1;
        }
    }
    reverse(n3.begin(), n3.end()); // reverse because i was pushing back not pushing front
    ans.s = n3;
    return ans;
}

void BigReal::operator+=(BigReal other) {
    *this = *this + other;
}

void BigReal::operator-=(BigReal other) {
    *this = *this - other;
}

BigReal BigReal::operator++() {
    *this = *this + BigReal("1.0");
    return *this;
}

BigReal BigReal::operator--() {
    *this = *this - BigReal("1.0");
    return *this;
}

ostream &operator<<(ostream &out, BigReal other) {
    BigReal x = other;
    if (!x.sign)out << '-';
    out << x.s;
    return out;
}

istream &operator>>(istream &in, BigReal &other) {
    string temp;
    in >> temp;
    other.setNum(temp);
    return in;
}
