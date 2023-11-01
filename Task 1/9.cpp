#include <bits./stdc++.h>

using namespace std;

bool isvalid(int n) {
    if (n == 42)
        return true;
    if (n % 5 == 0)
        if (n - 42)
            return isvalid(n - 42);
    if (n % 2 == 0)
        if (n - n / 2)
            return isvalid(n - n / 2);
    if (n % 4 == 0 || n % 3 == 0)
        if (n > 10)
            return isvalid(n - (n % 10) * ((n % 100) / 10));
    return false;
}

int main() {
    int n;
    cin >> n;
    cout << isvalid(n) << "\n";
}
