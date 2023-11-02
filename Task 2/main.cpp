#include <bits./stdc++.h>
#include "BigReal.h"

using namespace std;

int main() {
    BigReal x("11.9000000000000000000000000000000001");
    BigReal y("2333333333339.1134322222222292");
    BigReal z = x + y;
    cout << (x == y) << "\n";
    cout << (x > y) << "\n";
    cout << (x < y) << "\n";
    cout << z << "\n";
    z += BigReal("5");
    cout << z << "\n";
}
