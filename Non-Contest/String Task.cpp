#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <limits>
using namespace std;

static auto _speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

using ll = long long;
using ld = long double;

template<class T>
using vec = vector<T>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll INF = (ll) 4e18;
const int MOD = 1'000'000'007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        string s;
        cin >> s;
        string vow = "aeiouy";
        for (int i = 0 ; i < s.length(); i++) {
            s[i] = tolower(s[i]);
            auto it = std::find(vow.begin(), vow.end(), s[i]);
            if (it != vow.end()) {
                continue;
            } else {
                cout << '.' << s[i];
            }
        }
    }
    return 0;
}