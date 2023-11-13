#include <bits./stdc++.h>
#include "instructions.h"

using namespace std;

void instructions::LoadAddress(string reg[], string cell[], string s) {
    reg[HexToInt(string(1, s[1]))] = cell[HexToInt(s.substr(2))];
}

void instructions::LoadPattern(string reg[], string cell[], string s) {
    reg[HexToInt(string(1, s[1]))] = s.substr(2);
}

void instructions::StorePattern(string reg[], string cell[], string s) {
    if (s.substr(2) == "00") cout << reg[HexToInt(string(1, s[1]))];
    cell[HexToInt(s.substr(2))] = reg[HexToInt(string(1, s[1]))];
}

void instructions::MovePattern(string reg[], string s) {
    reg[HexToInt(string(1, s[3]))] = reg[HexToInt(string(1, s[2]))];
}