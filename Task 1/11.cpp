#include <iostream>
using namespace std;
#include<deque>
#include<bits/stdc++.h>
int main() {
    deque<pair<int,string>> nigger;
    bool check = true;
    string choice;
    while (check) {
        cout << "\nwhat do you want to do?\n";
        cout << "\tadd a player(write add)\n";
        cout << "\tcheck a players score(write check)\n";
        cout << "\tsee the list of players(write print)\n";
        cout << "\tfinish the game and print the list of players(write finish)\n";
        cout << "\tenter choice : ";
        cin >> choice;
        if (choice == "add") {
            string player;
            int score;
            cout << "\nplease enter a name and a score : ";
            cin >> player >> score;
            pair<int, string> pair1;
            pair1 = make_pair(score, player);
            nigger.push_back(pair1);
        }
        if (choice == "check") {
            string checkPlayer;
            cout << "\nplease enter a players name to check his score : ";
            cin >> checkPlayer;
            int coun=0;
            std::sort(nigger.begin(), nigger.end(),greater<>());
            for (int i = 0; i < nigger.size(); ++i) {
                if (nigger[i].second == checkPlayer) {
                    break;
                }
                    coun++;
                }
            if(coun<10) {
                cout<<nigger[coun].first<<"\n";
            }
                else if (coun > 10 && coun != nigger.size()-1) {
                cout << "this score is not in the top 10 ";
            }
                else if (coun == nigger.size()-1) {
                    cout << "this number was not in the input";
                }
            }
        if (choice == "print") {
            if (nigger.size() < 10) {
                int sum = nigger.size() - 10;
                std::sort(nigger.begin(), nigger.end());
                for (int i = nigger.size() - sum - 1; i <= 0; --i) {
                    cout << nigger[i].second << " " << nigger[i].first;
                }
            }
         else
            std::sort(nigger.begin(), nigger.end());
        for (int i = nigger.size() - 1; i <= 0; --i) {
            cout << nigger[i].second << " " << nigger[i].first;
        }
    }


        if(choice=="finish"){
            check = false;
        }
        }
    if (nigger.size() < 10) {
        int sum = nigger.size() - 10;
        std::sort(nigger.begin(), nigger.end());
        for (int i = nigger.size() - sum - 1; i <= 0; --i) {
            cout << nigger[i].second << " " << nigger[i].first;
        }
    }
    else
        std::sort(nigger.begin(), nigger.end());
    for (int i = nigger.size() - 1; i <= 0; --i) {
        cout << nigger[i].second << " " << nigger[i].first;

    }
}