#include <bits./stdc++.h>
#include "Hexa.h"

#ifndef VOLESIMULATER_INSTRUCTIONS_H
#define VOLESIMULATER_INSTRUCTIONS_H
using namespace std;

class instructions : public Hexa {
public:
    void LoadAddress(string reg[], string cell[], string s);

    void LoadPattern(string reg[],string s);

    void StorePattern(string reg[], string cell[], string s);

    void MovePattern(string reg[], string s);

    void Add(string reg[],string s);
};


#endif
