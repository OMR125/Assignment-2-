#include <bits./stdc++.h>
#include "instructions.h"

using namespace std;

void instructions::LoadAddress(string reg[], string cell[], string s) {
    reg[HexToInt(string(1, s[1]))] = cell[HexToInt(s.substr(2))];
}

void instructions::LoadPattern(string reg[], string s) {
    reg[HexToInt(string(1, s[1]))] = s.substr(2);
}

void instructions::StorePattern(string reg[], string cell[], string s) {
    if (s.substr(2) == "00") cout << "0x" << reg[HexToInt(string(1, s[1]))] << "\n";
    else cell[HexToInt(s.substr(2))] = reg[HexToInt(string(1, s[1]))];
}

void instructions::MovePattern(string reg[], string s) {
    reg[HexToInt(string(1, s[3]))] = reg[HexToInt(string(1, s[2]))];
}

void instructions::Add(string reg[], string s) {
    int carry = 0;
    string result;
    bool check=true;
    int bit1 = HexToInt(reg[HexToInt(string(1, s[2]))]);
    int bit2 = HexToInt(reg[HexToInt(string(1, s[3]))]);
    bitset<8>bitset1(bit1);
    bitset<8>bitset2(bit2);
    for (int i = 0; i <8; ++i) {
        int bit_a = bitset1[i];
        int bit_b = bitset2[i];
        int sum = bit_a + bit_b + carry;
        int bit = sum % 2;
        carry = sum / 2;
        result.push_back(bit + '0');
    }
    if(carry==1){
        check=false;
    }
    reverse(result.begin(),result.end());
    bitset<8>bitset3(result);
    int result2= bitset3.to_ulong();
    reg[HexToInt(string(1, s[1]))] = IntToHex(result2);

}
