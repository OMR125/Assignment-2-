#include <bits./stdc++.h>
#include "BigReal.h"

bool BigReal::isValidReal(string realNumber) {

}

void BigReal::setNum(string realNumber) {
    if (realNumber.find('.') == string::npos) {
        realNumber += string(".0");
    }
    if (realNumber.find('-') != string::npos) {
        if (realNumber.substr(1)[0] == '.')
            s = '0' + realNumber.substr(1);
        else
            s = realNumber.substr(1);
        sign = 0;
    } else {
        if (realNumber[0] == '.')realNumber = '0' + realNumber;
        s = realNumber;
        sign = 1;
    }
}

BigReal::BigReal(const BigReal &other) {
    s = other.s;
    sign = other.sign;
}

BigReal::BigReal(string realNumber) {
    if (realNumber.find('.') == string::npos) {
        realNumber += string(".0");
    }
    if (realNumber.find('-') != string::npos) {
        s = realNumber.substr(1);
        sign = 0;
    } else {
        s = realNumber;
        sign = 1;
    }
}

void BigReal::del() {
    string c = (*this).s;
    if (c[c.size() - 2] == '.' && c[c.size() - 1] == '0') {
        c.pop_back();
        c.pop_back();
    }
    (*this).s = c;
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
    int beforea = 0, aftera = 0;
    int beforeb = 0, afterb = 0;
    bool flag = 1;
    for (int i = 0; i < a.size(); i++) {
        if (a.s[i] == '.') {
            flag = 0;
            continue;
        }
        if (flag)beforea++;
        else aftera++;
    }
    flag = 1;
    for (int i = 0; i < b.size(); i++) {
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
