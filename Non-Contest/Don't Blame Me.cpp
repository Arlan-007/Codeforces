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

    int t = 1;
    cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> a(n);
        vector<vector<int>> dp(n + 1, vector<int>(64));
        for (auto &x : a) cin >> x;

        for (int i = 1; i <= n; i++)
            for(int m = 0; m < 64; m++) {
                dp[i][m] = (dp[i][m] + dp[i - 1][m]) % MOD;
                dp[i][m & a[i - 1]] = (dp[i][m & a[i - 1]] + dp[i - 1][m]) % MOD;
            }

        int ans = 0;
        for(int m = 0; m < 64; m++)
            if (__builtin_popcount(m) == k) ans = (ans + dp[n][m]) % MOD;

        cout << ans << "\n";
    }
}
