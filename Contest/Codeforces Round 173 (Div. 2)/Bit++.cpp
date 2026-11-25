# include <iostream>
using namespace std;

int main() {
    int n;
    int ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s.find("++")!=string::npos) {
            ans++;
        }
        if (s.find("--")!=string::npos) {
            ans--;
        }
    }
    cout<<ans;
    return 0;
}