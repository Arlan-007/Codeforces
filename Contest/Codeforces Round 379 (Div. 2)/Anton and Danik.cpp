#include <iostream>
using namespace std;

int main() {
    int n;
    string s;
    cin>>n>>s;
    int A = 0;
    for (int i=0;i<n;i++) {
        if (s[i] == 'A')A++;
        else if (s[i] == 'D')A--;
    }
    if (A == 0) cout<<"Friendship";
    else if (A > 0) cout<<"Anton";
    else cout<<"Danik";
    return 0;
}