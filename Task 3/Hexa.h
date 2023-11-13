#include <bits./stdc++.h>

using namespace std;
#ifndef VOLESIMULATER_HEXA_H
#define VOLESIMULATER_HEXA_H

class Hexa {
public:
    string IntToHex(int x) {
        char s[10];
        snprintf(s, sizeof s, "%X", x);
        return string("0x") + s;
    }

    int HexToInt(string s) {
        return stoi(s, 0, 16);
    }
};


#endif
