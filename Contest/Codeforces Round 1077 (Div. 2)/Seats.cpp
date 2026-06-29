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

    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        int ones = 0;
        for (char c : s) if (c == '1') ones++;
        if (ones == 0) {
            cout << (n + 2) / 3 << "\n";
            continue;
        }
        int add = 0;
        int i = 0;
        while (i < n) {
            if (s[i] == '1') {
                i++;
                continue;
            }
            int j = i;
            while (j < n && s[j] == '0') j++;
            int len = j - i;
            bool left = (i > 0 && s[i - 1] == '1');
            bool right = (j < n && s[j] == '1');
            if (left && right) {
                add += len / 3;
            } else {
                add += (len + 1) / 3;
            }
            i = j;
        }
        cout << ones + add << "\n";
    }
    return 0;
}