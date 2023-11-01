#include <bits./stdc++.h>

using namespace std;
int get_stars(long long n){
    int i=0;
    while(n%2==0){
        n/=2;
        i++;
    }
    return (1<<i);
}
void print_stars(int n){
    for(int i=0;i<n;i++)
        cout << "* ";
    cout << "\n";
}
int get_spaces(int n){
    if((n&(n-1))==0)
        return 0;
    return (n-1)/2;
}
void print_spaces(int n){
    for(int i=0;i<n;i++)
        cout << " ";
}
long long x;
void rec(long long n){
    if(n==x*2)return;
    long long temp = n;
    int extra=0;
    if(n>x) {
        extra = x/2;
        n-=x;
    }
    print_spaces(2*(extra+get_spaces(n)));
    print_stars(get_stars(n));
    rec(temp+1);
}
int main() {
    cin >> x;
    rec(1);
}
