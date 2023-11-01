#include <bits./stdc++.h>

using namespace std;

vector<int> sieve(int n) {
    vector<int> primes, check(n + 1);
    for (int i = 2; i <= n; i++) {
        if (!check[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= n; j += i) {
                check[j] = 1;
            }
        }
    }
    return primes;
}

int main() {
    int n;
    cout << "Enter the number you want to stop the sieve algorithm at:\n";
    cin >> n;
    vector<int> primes = sieve(n);
    for (int i = 0; i < primes.size(); i++)
        cout << primes[i] << " \n"[i == primes.size() - 1];
}

