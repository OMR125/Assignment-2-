#include <bits./stdc++.h>

using namespace std;

struct dominoT {
    int leftDots, rightDots;
};

void FormsDominoChain(vector <dominoT> tiles, int n, vector<int> positions) {
    do {
        vector <dominoT> order;
        for (int i = 0; i < n; i++)
            order.push_back(tiles[positions[i]]);
        int isvalid = 1;
        for (int i = 0; i < n - 1; i++) {
            if (order[i].rightDots != order[i + 1].leftDots) {
                isvalid = 0;
                break;
            }
        }
        if (isvalid) {
            cout << "These dominos can be linked together and the combination is:\n";
            for (int i = 0; i < n; i++) {
                int l = order[i].leftDots;
                int r = order[i].rightDots;
                if (i > 0)cout << " ";
                cout << l << '|' << r << " " << "-\n"[i == n - 1];
            }
            return;
        }
    } while (next_permutation(positions.begin(), positions.end()));
    cout << "It's impossible to link all the dominos together\n";
}

int main() {
    cout << "Enter the number of dominos:\n";
    int len;
    cin >> len;
    vector <dominoT> tiles;
    vector<int> positions(len);
    iota(positions.begin(), positions.end(), 0);
    for (int i = 0; i < len; i++) {
        int left, right;
        cin >> left >> right;
        tiles.push_back({left, right});
    }
    FormsDominoChain(tiles, len, positions);
}
