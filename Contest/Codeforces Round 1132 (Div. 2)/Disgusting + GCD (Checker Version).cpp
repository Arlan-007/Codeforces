#include <iostream>
#include <vector>
#include <array>
#include <deque>
#include <list>
#include <forward_list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <functional>
#include <utility>
#include <tuple>
#include <string>
#include <cstring>
#include <sstream>
#include <cmath>
#include <complex>
#include <bitset>
#include <random>
#include <limits>
#include <climits>
#include <cfloat>
#include <cassert>
#include <exception>
#include <stdexcept>

using namespace std;

#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

using ll = long long;

const ll INF = (ll) 4e18;
const ll NEG = -INF;
const int MOD = 1'000'000'007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int a, b; cin >> a >> b;
        bool found = false;
        if (a == b) {
            cout << "0" << '\n';
            continue;
        }
        if (gcd(a, b) == 1) {
            cout << "1" << '\n' << b - a << '\n';
            continue;
        }
        for (int c = a + 1; c < b; c++) {
            if (gcd(a, c) == 1 && gcd(c, b) == 1) {
                cout << "2" << '\n' << c - a << ' ' << b - c << '\n';
                found = true;
                break;
            }
        }
        if (found) continue;

        int n = b - a;
        vector<int> dp(n + 1, n + 1), pre(n + 1); dp[0] = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 0; j < i; j++) if (gcd(a + j, a + i) == 1 && dp[j] + 1 < dp[i]) dp[i] = dp[j] + 1, pre[i] = j;

        vector<int> ans;
        int x = n;
        while (x > 0) ans.push_back(x - pre[x]), x = pre[x];
        reverse(ans.begin(), ans.end());

        cout << ans.size() << '\n';
        for (int p : ans) cout << p << ' ';
        cout << '\n';
    }
}