#include <bits./stdc++.h>

using namespace std;

int main() {
    string s;
    cout << "Enter the string you want to modify:\n";
    getline(cin, s);
    s.push_back(' ');
    set<char> punctuation = {'.', ',', ' ', '?', '!'};
    for (int i = 1; i < s.size() - 2; i++) {
        string him = s.substr(i, 3);
        transform(him.begin(), him.end(), him.begin(), ::tolower);
        if (him == "him" && punctuation.count(s[i - 1]) && punctuation.count(s[i + 3])) {
            s.insert(i + 3, " or her");
            i += 10;
            continue;
        }
        string he = s.substr(i, 2);
        transform(he.begin(), he.end(), he.begin(), ::tolower);
        if (he == "he" && punctuation.count(s[i + 2]) && punctuation.count(s[i - 1])) {
            s.insert(i + 2, " or she");
            i += 9;
        }
    }
    cout << s << "\n";
}
