#include <bits./stdc++.h>
#include "machine.h"

using namespace std;

int main() {
    int n;
    while (true) {
        cout << "NOTE: Registers and memory will be printed after the execution of the file:\n";
        cout << "Press 1 to start a new file or 0 to halt the program:\n";
        cin >> n;
        if (!n)
            break;
        else if (n == 1) {
            machine x;
            x.run();
        } else cout << "INVALID OPTION\n";
    }
}
