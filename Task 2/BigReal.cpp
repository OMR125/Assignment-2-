#include <bits./stdc++.h>
#include "BigReal.h"

void BigReal::setNum(string realNumber) {
    if (realNumber.find('.') == string::npos) {
        realNumber += string(".0");
    }
    s = realNumber;
}

BigReal::BigReal(const BigReal &other) {
    s = other.s;
}

BigReal::BigReal(string realNumber) {
    if (realNumber.find('.') == string::npos) {
        realNumber += string(".0");
    }
    s = realNumber;
}

int BigReal::size() {
    return s.size();
}

int BigReal::sign() {
    return (s[0] == '-' ? -1 : 1);
}

bool BigReal::operator==(BigReal &other) {
    return s == other.s;
}

bool BigReal::operator>(BigReal &other) {
    if (sign() != other.sign())
        return sign() > other.sign();
    for (int i = 0; i < size(); i++) {
        if (s[i] > other.s[i])
            return true;
        else if (s[i] < other.s[i])
            return false;
    }
    return false;
}

bool BigReal::operator<(BigReal &other) {
    return other > *this;
}

pair <BigReal, BigReal> BigReal::equalize(BigReal b) {
    BigReal a = *this;
    int beforea = 0, aftera = 0;
    int beforeb = 0, afterb = 0;
    bool flag = 1;
    for (int i = 0; i < a.size(); i++) {
        if (a.s[i] == '-')continue;
        if (a.s[i] == '.') {
            flag = 0;
            continue;
        }
        if (flag)beforea++;
        else aftera++;
    }
    flag = 1;
    for (int i = 0; i < b.size(); i++) {
        if (b.s[i] == '-')continue;
        if (b.s[i] == '.') {
            flag = 0;
            continue;
        }
        if (flag)beforeb++;
        else afterb++;
    }
    if (beforea < beforeb) {
        a.s = string(beforeb - beforea, '0') + a.s;
    } else
        b.s = string(beforea - beforeb, '0') + b.s;
    if (aftera < afterb) {
        a.s += string(afterb - aftera, '0');
    } else
        b.s += string(aftera - afterb, '0');
    return {a, b};
}

BigReal BigReal::operator+(BigReal &other) {
    pair <BigReal, BigReal> p = equalize(other);
    string a = p.first.s;
    string b = p.second.s;
    string c;
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
    if (c[c.size() - 2] == '.') {
        c.pop_back();
        c.pop_back();
    }
    return c;
}

ostream &operator<<(ostream &out, BigReal other) {
    out << other.s;
    return out;
}
