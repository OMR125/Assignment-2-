#include <bits./stdc++.h>

using namespace std;
#ifndef VOLESIMULATER_HEXA_H
#define VOLESIMULATER_HEXA_H

class Hexa {
public:
    string IntToHex(int n) {
        char ToHex[10];
        snprintf(ToHex, sizeof ToHex, "%X", n);
        string temp = ToHex;
        return string(temp.size() == 1 ? "0" : "", 1) + temp;
    }

    int HexToInt(string s) {
        return stoi(s, 0, 16);
    }
};


#endif
