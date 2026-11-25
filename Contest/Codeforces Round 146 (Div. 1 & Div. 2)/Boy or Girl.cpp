#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

int main() {
    unordered_set<int> chars;
    string username;
    cin>>username;
    for (int i = 0; i < username.length(); i++) {
        if (!chars.count(username[i])) {
            chars.insert(username[i]);
        }
    }
    if (chars.size()%2==0) cout<<"CHAT WITH HER!";
    else cout<<"IGNORE HIM!";
    return 0;
}