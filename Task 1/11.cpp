#include <iostream>
using namespace std;
#include<fstream>
#include<vector>

int main() {
    ifstream compare("comp1.txt");
    string comp1, comp2,comp3,comp4;
    ifstream compare2("comp2.txt");
    vector<string> sum;
    vector<string> sum2;
    vector<char>sum3;
    vector<char>sum4;
    string choice;cout<<"do you want to compare characters or words:";cin>>choice;
    if(choice=="words") {
        while (compare >> comp1) {
            sum.push_back(comp1);
        }
        while (compare2 >> comp2) {
            sum2.push_back(comp2);
        }
        int count = 0;
        if (sum.size() != sum2.size()) {
            cout << "not identical\n";
        } else{
            for (int i = 0; i < sum.size(); ++i) {
                if (sum[i] == sum2[i]) {
                    count++;
                } else {
                    cout << sum2[i] << " " << "\n";
                    for (int j = 0; j < sum2.size(); ++j) {
                        if (sum2[i] == sum2[j]) {
                            for (int k = i; k < i + 11; ++k) {
                                cout << sum2[k] << " ";

                            }
                        }

                    }
                }
            }

            }
        if (count == sum.size()) {
            cout << "they are identical\n";
        }
        compare.close();
        compare2.close();
    }
    else {
        getline(compare, comp3);
        for (int i = 0; i < comp3.size(); ++i) {
            sum3.push_back(comp3[i]);
        }
        getline(compare2, comp4);
        for (int i = 0; i < comp4.size(); ++i) {
            sum4.push_back(comp4[i]);
        }
        int count = 0;
        if (sum.size() != sum2.size()) {
            cout << "not identical\n";
        } else {
            for (int i = 0; i < sum3.size(); ++i) {
                if (sum3[i] == sum4[i]) {
                    count++;
                } else {
                    if(i/75==0) {
                        cout << (i / 75) + 1 << " " << "\n";
                    }
                    else{
                        cout << (i / 75)<< " " << "\n";

                    }
                    for (int j = 0; j < sum4.size(); ++j) {
                        if (sum4[i] == sum4[j]) {
                            for (int k = i; k < i + 75; ++k) {
                                cout << sum4[k];
                            }
                            break;
                        }
                    }

                }
            }
            if (count == sum.size()) {
                cout << "they are identical";
            }
            compare.close();
            compare2.close();
    }
    }


    }



