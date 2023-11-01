#include <bits./stdc++.h>

using namespace std;

string s;
vector <string> suffix;

void get_combinations(string number, int length) {
    if (!length) {
        suffix.push_back(number);
        return;
    }
    get_combinations(number + '1', length - 1);
    get_combinations(number + '0', length - 1);
}

int main() {
    cout << "Enter the prefix string:\n";
    cin >> s;
    int k;
    cout << "Enter the length of wanted suffix:\n";
    cin >> k;
    get_combinations("", k);
    for (int i = suffix.size() - 1; ~i; i--)
        cout << s << suffix[i] << "\n";
}
