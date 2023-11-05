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

bool BigReal::isValidReal(string Number) { // check if the number is valid
    int cnt = 0;
    for (int i = 0; i < Number.size(); ++i) { // check if the number has more than one dot
        if (Number[i] == '.') {
            cnt++;
        } else if (!(Number[i] >= '0' && Number[i] <= '9')) { // check if the number has any symbols that is unacceptable
            return false;
        }
    }
    return cnt < 2; // it returns whether the number is valid or not
}

BigReal::BigReal(string Number,bool change) { // constructor that does the same as the setter
    sign = 1;
    if (Number.find('.') == string::npos)
        Number += string(".0");

    if (Number[0] == '+' || Number[0] == '-') { // we are storing the sign away by taking it from the string so it can give us some flexibility while doing other operations
        sign = (Number[0] == '-' ? 0 : 1);
        Number = Number.substr(1);
    }
    if (Number[0] == '.')
        Number = '0' + Number;

    if (!isValidReal(Number)) {
        s = "0.0";
    }
    else {
        s = Number;
        if(change)
            del();
    }
}

void BigReal::setNum(string Number, bool change){ // setting the number and checking if it is valid or not while also deleting extra zeros
    sign = 1;
    if (Number.find('.') == string::npos)
        Number += string(".0");

    if (Number[0] == '+' || Number[0] == '-') { // we are storing the sign away by taking it from the string so it can give us some flexibility while doing other operations
        sign = (Number[0] == '-' ? 0 : 1);
        Number = Number.substr(1);
    }
    if (Number[0] == '.')
        Number = '0' + Number;

    if (!isValidReal(Number))
        s = "0.0";
    else {
        s = Number;
        if(change)
            del();
    }
}

BigReal::BigReal(const BigReal &other) { // the copy constructor
    s = other.s;
    sign = other.sign;
}

void BigReal::del(){ // we are deleting the extra zeros from both sides that might be extra and does not hold any meaning or value
    while (s[0] == '0' && s[1] != '.') // delete extra zeros from the right but leaving the last zero
        s.erase(0,1);

    while (s.back() == '0') // delete extra zeros from the left
        s.pop_back();

    if (s.back() == '.') // delete the dot if there is no number after
        s.pop_back();
}

int BigReal::size() {
    return s.size();
}

bool BigReal::operator==(const BigReal &other) const { // check if both numbers are equal by comparing the signs and the numbers themselves
    return s == other.s && sign == other.sign;
}

bool BigReal::operator!=(const BigReal &other) const { // check if the two numbers are not equal and return the result
    return !(*this == other);
}

bool BigReal::operator>(const BigReal &other) const { // checking to see if the number is bigger than the other number by checking the sign first and then inspecting the two numbers
    if (sign != other.sign) // checking if the other number is negative
        return sign > other.sign;
    pair <BigReal, BigReal> temp = equalize(other);// equalizing so that we can work
    string a = temp.first.s; // storing the two numbers from the equalized pair
    string b = temp.second.s;
    for (int i = 0; i < a.size(); i++) { // comparing the two numbers
        if (a[i] > b[i])
            return (*this).sign;
        else if (a[i] < b[i])
            return !(*this).sign;
    }
    return false;
}

bool BigReal::operator>=(const BigReal &other) const { // checking to see if the number is bigger than or equal to the other number and then returning the result
    return *this > other || *this == other;
}

bool BigReal::operator<(const BigReal &other) const { // checking to see if the number is less than the other number and then returning the result
    return other > *this;
}

bool BigReal::operator<=(const BigReal &other) const { // checking to see if the number is less than or equal to the other number and then returning the result
    return *this < other || *this == other;
}

pair <BigReal, BigReal> BigReal::equalize(const BigReal &temp) const { // we are making both numbers equal in length by adding zeros so that we can work freely
    BigReal a(s,0);
    a.sign = sign;
    BigReal b(temp.s,0);
    b.sign = temp.sign;
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
    BigReal n1(a.s,0);
    n1.sign = (*this).sign;
    BigReal n2(b.s,0);
    n2.sign = b.sign;
    return {n1, n2};
}

BigReal BigReal::operator+(const BigReal &other) const {
    pair <BigReal, BigReal> temp = equalize(other); // equalizing the two numbers
    string a = temp.first.s; // storing them in pairs
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
        int digit1 = a[i] - '0'; // converting the digits to int
        int digit2 = b[i] - '0';
        int sum = digit1 + digit2 + carry; // we add the two digits and the carry
        carry = sum / 10; // if we have a carry we use this so that it can get us the whole number without any decimals
        sum %= 10; // then we use the variable(sum) so that we can get the remaining part of the whole number we dismissed in the previous step
        c.push_back(sum + '0'); // pushback the answer and make it a charachter
    }
    if (carry)c.push_back(carry + '0');
    reverse(c.begin(), c.end()); // reverse because I was pushing back not pushing front
    return BigReal(c);
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
    reverse(n3.begin(), n3.end()); // reverse because I was pushing back not pushing front
    ans.s = n3;
    return ans;
}

void BigReal::operator+=(BigReal other) { //decrease the value of the number by (other) and then assign the value to the original variable
    *this = *this + other;
}

void BigReal::operator-=(BigReal other) { //decrease the value of the number by (other) and then assign the value to the original variable
    *this = *this - other;
}

ostream &operator<<(ostream &out, BigReal other) { // output the desired number without using getters
    BigReal x = other;
    if (!x.sign)out << '-';
    out << x.s;
    return out;
}

istream &operator>>(istream &in, BigReal &other) { // input the desired number without using setters
    string temp;
    in >> temp;
    other.setNum(temp);
    return in;
}
