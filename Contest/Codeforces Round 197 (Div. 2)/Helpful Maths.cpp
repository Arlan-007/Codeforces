#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    string s;
    string ans;
    cin>>s;
    map<char,int> stats;
    for (int i = 0; i < s.length(); i++) {
        stats[s[i]]++;
    }
    for (int i = 0; i < stats['1']; i++) {
        ans+="1";
        if (stats['2']==0 && stats['3']==0 && i!=stats['1']-1) {
            ans+="+";
        } else if (stats['2']!=0 || stats['3']!=0) {
            ans+="+";
        }

    }
    for (int i = 0; i < stats['2']; i++) {
        ans+="2";
        if (stats['3']!=0) {
            ans+="+";
        } else if (i!=stats['2']-1) {
            ans+="+";
        }
    }
    for (int i = 0; i < stats['3']; i++) {
        ans+="3";
        if (i < stats['3']-1) {
            ans+="+";
        }
    }
    cout << ans << endl;
    return 0;
}