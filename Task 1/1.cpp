#include <bits./stdc++.h>

using namespace std;

int main() {
    cout << "Enter the String you want to modify:\n";
    string s;
    getline(cin, s);
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    s[0] = toupper(s[0]);
    string ans;
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            cnt++;
            if (cnt > 1)continue;
        } else cnt = 0;
        ans += s[i];
    }
    cout << ans << "\n";
}
