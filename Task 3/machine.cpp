#include "machine.h"

void machine::work() {
    a.fill();
    c.fill();
    string name;
    cout << "Please Enter File name:";
    cin >> name;
    a.fetch(name);
    for (int i = 0; i < 256; i += 2) {
        string x;
        x += a.cell[i];
        x += a.cell[i + 1];
        if (a.cell[i][0] == '1')
            b.LoadAddress(c.reg, a.cell, x);
        else if (a.cell[i][0] == '2')
            b.LoadPattern(c.reg, a.cell, x);
        else if (a.cell[i][0] == '3')
            b.StorePattern(c.reg, a.cell, x);
        else if (a.cell[i][0] == '4')
            b.MovePattern(c.reg, x);
        else if (a.cell[i][0] == 'B') {
            if (c.reg[HexToInt(string(1, x[1]))] == c.reg[0])
                i = HexToInt(x.substr(2)) - 2;
        } else if (a.cell[i][0] == 'C')
            break;

    }
//    for (auto c: a.cell) {
//        cout << c << "\n";
//    }
//    cout << "\n";
//    for (auto c: c.reg) {
//        cout << "0x" << c << "\n";
//    }
}