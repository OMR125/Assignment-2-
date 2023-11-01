#include <bits./stdc++.h>
#include <windows.h>
#include <unistd.h>
using namespace std;

struct player {
public:
    string name = "";
    int score = 0;
    player() {}

    player(string _name, int _score) {
        name = _name;
        score = _score;
    };

    bool operator<(const player &x) const {
        return x.score < score;
    }
};

string temp;

bool comp(player x) {
    return x.name == temp;
}

void print_options() {
    cout << "Pick 1 to add a player in the database.\n";
    cout << "Pick 2 to print the top 10 leaderboard.\n";
    cout << "Pick 3 check if a specific person is currently on the top 10 leaderboard and what was his best score.\n";
    cout << "Pick 0 to Exit.\n";
}
string Modify(string x){
    transform(x.begin(),x.end(),x.begin(),::tolower);
    x[0]= toupper(x[0]);
    return x;
}
int main() {
    multiset <player> Top10, AllTime;
    while (true) {
        print_options();
        int pick, score,Sleep=0;
        string name;
        cin >> pick;
        if (pick == 0)
            break;
        else if (pick == 1) {
            cout << "Enter the person's name:\n";
            cin >> name;
            name = Modify(name);
            cout << "Enter the person's score:\n";
            cin >> score;
            Top10.insert(player(name, score));

            if (Top10.size() > 10)
                Top10.erase(prev(Top10.end()));

            AllTime.insert(player(name, score));
        } else if (pick == 2) {
            for (auto [x, y]: Top10)
                cout << x << " " << y << "\n";
            Sleep = 3;
        } else if (pick == 3) {
            cout << "Enter the person's name:\n";
            cin >> name;
            name = Modify(name);
            temp = name;
            auto Top10_check = find_if(Top10.begin(), Top10.end(), comp);
            auto AllTime_check = find_if(AllTime.begin(), AllTime.end(), comp);

            if (Top10_check != Top10.end())
                cout << "This person is on the top 10 leaderboard and his best score is: " << Top10_check->score << "\n";
            else if (AllTime_check != AllTime.end())
                cout << "This person isn't on the top 10 leaderboard but his best score is: " << AllTime_check->score << "\n";
            else
                cout << "This person isn't in the database!\n";
            Sleep = 2;
        } else
            cout << "Invalid option please pick a number from 0 to 4!!\n";
        sleep(Sleep);
    }
}

