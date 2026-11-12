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
const int MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, x; cin >> n;
        vector<int> a(3 * n + 1, 0);
        for (int i = 0; i < n; i++) cin >> x, a[x] = 1;

        vector<vector<int>> dp(8, vector<int>(3)); dp[0][0] = 1;
        for (int i = 3 * n; i >= 0; i--) {
            vector<vector<int>> ndp(8, vector<int>(3));
            for (int j = 0; j < 8; j++) {
                for (int k = 0; k < 3; k++) {
                    int nx = (j << 1) & 7, nk = k + (__builtin_popcount(j) != 2);
                    ndp[nx][k] += dp[j][k], ndp[nx][k] %= MOD;
                    if (a[i] && nk < 3) ndp[nx | 1][nk] += dp[j][k], ndp[nx | 1][nk] %= MOD;
                }
            }
            dp = ndp;
        }
        int ans = -1;
        for (auto &x : dp) for (int y : x) ans += y, ans %= MOD;
        cout << ans << '\n';
    }
}