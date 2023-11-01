#include <bits./stdc++.h>

using namespace std;

vector <string> split(string target, string delimiter) {
    vector <string> answer;
    string add;
    int n = target.size(), m = delimiter.size();
    for (int i = 0; i < n; i++) {
        string substring = target.substr(i, m);
        if (substring == delimiter) {
            answer.push_back(add);
            add = "";
            i += m - 1;
        } else add += target[i];
    }
    if (add != "")answer.push_back(add);
    return answer;
}

int main() {
    string target, delimiter;
    cout << "Enter the target string:\n";
    getline(cin, target);
    cout << "Enter the delimiter string:\n";
    getline(cin, delimiter);
    vector <string> answer = split(target, delimiter);
    for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << " \n"[i == answer.size() - 1];
}
