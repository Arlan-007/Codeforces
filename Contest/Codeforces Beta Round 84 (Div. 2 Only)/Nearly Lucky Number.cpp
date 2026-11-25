#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin>>s;
    int lucky = 0;
    for (int i=0;i<s.length();i++) {
        if (s[i]=='4' || s[i]=='7') lucky++;
    }
    bool luck = true;
    string l = to_string(lucky);
    for (int i=0;i<l.length();i++) {
        if (l[i]!='4' && l[i]!='7') luck = false;
    }
    if (luck) cout<<"YES";
    else cout<<"NO";
    return 0;
}