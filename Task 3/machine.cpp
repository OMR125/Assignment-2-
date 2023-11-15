#include "machine.h"

void machine::run() {
    mem.fill();
    regs.fill();
    string name;
    cout << "Please enter the File's name:";
    cin >> name;
    mem.fetch(name);
    for (int i = 0; i < 256; i += 2) {
        string x;
        x += mem.cell[i];
        x += mem.cell[i + 1];
        char op = mem.cell[i][0];
        if (op == '1')
            inst.LoadAddress(regs.reg, mem.cell, x);
        else if (op == '2')
            inst.LoadPattern(regs.reg, x);
        else if (op == '3')
            inst.StorePattern(regs.reg, mem.cell, x);
        else if (op == '4')
            inst.MovePattern(regs.reg, x);
        else if (op == '5')
            inst.Add(regs.reg, x);
        else if (mem.cell[i][0] == 'B') {
            if (regs.reg[HexToInt(string(1, x[1]))] == regs.reg[0])
                i = HexToInt(x.substr(2)) - 2;
        } else if (mem.cell[i][0] == 'C')
            break;
    }
    cout << "\nMEMORY:\n";
    for (auto c: mem.cell)
        cout << "0x" << c << "\n";

    cout << "\nRegisters:\n";
    for (auto r: regs.reg)
        cout << "0x" << r << "\n";
}
