#include <bits./stdc++.h>
#include "memory.h"

using namespace std;

void memory::fill() {
    for (int i = 0; i < 256; i++)
        cell[i] = "00";
}

void memory::fetch(string filename) {
    if (filename.find(".txt") == string::npos)
        filename += ".txt";
    ifstream f(filename);
    string instruction;
    int i = 0;
    while (getline(f, instruction)) {
        if (i >= 256) {
            cout << "MEMORY LIMIT EXCEEDED\n";
            exit(0);
        }
        cell[i] = cell[i + 1] = "";
        cell[i] += instruction[2];
        cell[i] += instruction[6];
        cell[i + 1] += instruction[10];
        cell[i + 1] += instruction[11];
        i += 2;
    }
}
