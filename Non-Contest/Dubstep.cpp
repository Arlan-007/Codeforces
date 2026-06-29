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
        string S; cin >> S;
        for (;;) {
            string sub = S.substr(0, 3);
            if (sub == "WUB") {
                S.erase(0, 3);
            } else {
                cout << S[0];
                S.erase(0, 1);
                string sub2 = S.substr(0, 3);
                if (sub2 == "WUB") {
                    cout << " ";
                }
            }
            if (S.empty()) {break;}
        }
    }
    return 0;
}