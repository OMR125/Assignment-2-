#include <iostream>
using namespace std;
#include<vector>
#include <fstream>
int main() {
    string s[]={"payment","invoice","statement","copy","verify","action","urgent","View","file","bank","money","suspicious","New","Notification","Expire","company","taxes","credit","pay","due","username","please","send","president","ceo","stop","investment","crypto","business","scam"};
    vector<pair<string,int>>check;
    pair<string,int>pair1;
    for (int i = 0; i <30; ++i) {
        pair1= make_pair(s[i],0);
        check.push_back(pair1);
    }
    ifstream email("email.txt");
    vector<string>store;
    string word;
    while(email>>word){
        store.push_back(word);
    }
    for (int i = 0; i <store.size() ; ++i) {
        for (int j = 0; j <30 ; ++j) {
            if (store[i]==check[j].first) {
                check[j].second++;
                cout <<" "<<check[j].first << " " << check[j].second << " ";
                if (j < 10) {
                    cout << (check[j].second) * 3;
                } else if (j < 20) {
                    cout << (check[j].second) * 2;
                } else {
                    cout << check[j].second << " ";
                }
            }
        }
        }
    int sum=0;
    for (int i = 0; i < 30; ++i) {
        if(i<10) {
            sum+=((check[i].second) * 3);
        }
        else if(i<20) {
            sum+=((check[i].second) * 2);
        }
        else
            sum+=(check[i].second);
    }
    cout<<" "<<sum;
}



