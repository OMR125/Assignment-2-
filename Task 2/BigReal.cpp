#include <bits./stdc++.h>
#include "bigReal.h"

bool BigReal::isValidReal(string realNumber) {
    int count = 0;
    for (int i = 0; i < realNumber.length(); ++i) {
        if (realNumber[i] == '.') {
            count++;
        } else if (!(realNumber[i] >= '0' && realNumber[i] <= '9')) {
            return false;
        }
    }
    return count < 2;
}

void BigReal::setNum(string realNumber) {
    if (realNumber.find('.') == string::npos) {
        realNumber += string(".0");
    }
    sign = 1;
    if (realNumber[0] == '+' || realNumber[0] == '-') {
        sign = (realNumber[0] == '-' ? 0 : 1);
        realNumber = realNumber.substr(1);
    }
    if (realNumber[0] == '.')
        realNumber = '0' + realNumber;
    if (!isValidReal(realNumber))
        s = "0.0";
    else
        s = realNumber;
}

BigReal::BigReal(const BigReal &other) {
    s = other.s;
    sign = other.sign;
}

BigReal::BigReal(string realNumber) {
    if (realNumber.find('.') == string::npos) {
        realNumber += string(".0");
    }
    sign = 1;
    if (realNumber[0] == '+' || realNumber[0] == '-') {
        sign = (realNumber[0] == '-' ? 0 : 1);
        realNumber = realNumber.substr(1);
    }
    if (realNumber[0] == '.')
        realNumber = '0' + realNumber;
    if (!isValidReal(realNumber))
        s = "0.0";
    else
        s = realNumber;
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

bool BigReal::operator>(const BigReal &other) const {
    if (sign != other.sign)
        return sign > other.sign;
    pair <BigReal, BigReal> p = equalize(other);
    string a = p.first.s;
    string b = p.second.s;
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

bool BigReal::operator!=(const BigReal &other) const {
    return !(*this == other);
}

pair <BigReal, BigReal> BigReal::equalize(const BigReal &temp) const {
    BigReal a = *this;
    BigReal b = temp;
    int before_a = 0, after_a = 0;
    int before_b = 0, after_b = 0;
    bool flag = 1;
    for (int i = 0; i < a.size(); i++) {
        if (a.s[i] == '.') {
            flag = 0;
            continue;
        }
        if (flag)before_a++;
        else after_a++;
    }
    flag = 1;
    for (int i = 0; i < b.size(); i++) {
        if (b.s[i] == '.') {
            flag = 0;
            continue;
        }
        if (flag)before_b++;
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
    BigReal x(a);
    x.sign = (*this).sign;
    BigReal y(b);
    y.sign = b.sign;
    return {x, y};
}

BigReal BigReal::operator+(const BigReal &other) const {
    pair <BigReal, BigReal> p = equalize(other);
    string a = p.first.s;
    string b = p.second.s;
    string c;
    if (!(p.first.sign && p.second.sign)) {
        p.second.sign ^= 1;
        return p.first - p.second;
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
    BigReal x;
    x.s = c;
    x.sign = 1;
    return x;
}

BigReal BigReal::operator-(const BigReal &other) const {
    pair <BigReal, BigReal> p = equalize(other);
    BigReal a = p.first;
    BigReal b = p.second;
    BigReal c;
    c.sign = 1;
    if (a.sign && !b.sign) {
        b.sign = 1;
        c = a + b;
        return c;
    }
    if (!a.sign && b.sign) {
        a.sign = 1;
        c = a + b;
        c.sign = 0;
        return c;
    }
    if (!a.sign && !b.sign) {
        a.sign = b.sign = 1;
        if (b < a) {
            c.sign = 0;
        } else swap(a.s, b.s);
    } else {
        a.sign = b.sign = 1;
        if (a < b) {
            swap(a.s, b.s);
            c.sign = 0;
        }
    }
    string x = a.s;
    string y = b.s;
    string z;
    int carry = 0;
    for (int i = x.size() - 1; i >= 0; i--) {
        if (x[i] == '.') {
            z.push_back('.');
            continue;
        }
        int digit1 = x[i] - '0';
        int digit2 = y[i] - '0';
        int sub = digit1 - digit2 - carry;
        if (sub >= 0) {
            z.push_back(sub + '0');
            carry = 0;
        } else {
            z.push_back(sub + 10 + '0');
            carry = 1;
        }
    }
    reverse(z.begin(), z.end());
    c.s = z;
    return c;
}

void BigReal::operator+=(BigReal other) {
    *this = *this + other;
}

void BigReal::operator-=(BigReal other) {
    *this = *this - other;
}

ostream &operator<<(ostream &out, BigReal other) {
    BigReal x = other;
    x.del();
    if (!x.sign)out << '-';
    out << x.s;
    return out;
}

BigReal BigReal::operator++() {
    *this = *this + BigReal("1.0");
    return *this;
}

BigReal BigReal::operator--() {
    *this = *this - BigReal("1.0");
    return *this;
}

istream &operator>>(istream &in, BigReal &other) {
    string temp;
    in >> temp;
    other.setNum(temp);
    return in;
}
