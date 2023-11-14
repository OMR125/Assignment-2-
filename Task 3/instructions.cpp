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
void instructions::Add(string reg[],string cell[],string s) {
    int carry = 0;
    string result;
    string bit1 = reg[HexToInt(string(1, s[2]))];string bit2 = reg[HexToInt(string(1, s[3]))];
    for (int i = 0; i < 8; ++i) {
        int bit_a = bit1[i] - '0';
        int bit_b = bit2[i] - '0';
        int sum = bit_a + bit_b + carry;
        int bit = sum % 2;
        carry = sum / 2;

        result.push_back(bit + '0');
    }
    if (carry == 1) {
        result.push_back('1');
    }
    bool check =true;
    if(result.back()=='1'&&result.length()==9){
        result.pop_back();
        check=false;
    }
    reverse(result.begin(), result.end());
    if(!check) {
        reg[HexToInt(string(1, s[1]))] = '-'+result;
    }
    else
        reg[HexToInt(string(1, s[1]))] = result;
}


