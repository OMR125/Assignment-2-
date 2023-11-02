#include <bits./stdc++.h>

using namespace std;

int main() {
    string s[] = {"payment", "invoice", "statement", "copy", "verify", "action", "urgent", "view", "file", "bank",
                  "money", "suspicious", "new", "notification", "expire", "company", "taxes", "credit", "pay", "due",
                  "username", "please", "send", "president", "ceo", "stop", "investment", "crypto", "business", "scam"};
    vector <pair<string, int>> check;
    for (int i = 0; i < 30; ++i)
        check.push_back({s[i], 0});
    ifstream email("email.txt");
    string word;
    set<char> st = {',', '.', '?', '!', ';', '-', ':'};
    while (email >> word) {
        while (st.count(word.back()))
            word.pop_back();
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        for (int j = 0; j < 30; ++j)
            check[j].second += (word == check[j].first);
    }
    int sum = 0;
    for (int i = 0; i < 30; ++i) {
        if (i < 10) {
            cout << check[i].first << " " << check[i].second << " " << check[i].second * 3 << "\n";
            sum += (check[i].second * 3);
        } else if (i < 20) {
            cout << check[i].first << " " << check[i].second << " " << check[i].second * 2 << "\n";
            sum += (check[i].second * 2);
        } else {
            cout << check[i].first << " " << check[i].second << " " << check[i].second << "\n";
            sum += check[i].second;
        }
    }
    cout << sum;
}



