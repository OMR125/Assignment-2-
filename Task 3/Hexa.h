#include <bits./stdc++.h>

using namespace std;
#ifndef VOLESIMULATER_HEXA_H
#define VOLESIMULATER_HEXA_H

class Hexa {
public:
    string IntToHex(int x) {
        char s[10];
        snprintf(s, sizeof s, "%X", x);
        string z = s;
        return string(z.size()==1?"0":"",1) + z;
    }

    int HexToInt(string s) {
        return stoi(s, 0, 16);
    }
};


#endif
