#include <bits./stdc++.h>

using namespace std;

string recursion(int length, string binary = "") {
    if (length == 0)
        return binary;
    binary = to_string(length % 2) + binary;
    return recursion(length / 2, binary);
}

int main() {
    int n;
    cout << "Enter the number you want its binary representation:\n";
    cin >> n;
    cout << recursion(n);
}
