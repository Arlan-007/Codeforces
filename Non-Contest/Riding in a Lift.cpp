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

    int n, a, b, k; cin >> n >> a >> b >> k;
    vector<vector<ll>> dp(k + 1, vector<ll>(n + 1, 0));
    vector<ll> pref(n + 2, 0);
    dp[0][a] = 1;

    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) pref[j] = (pref[j - 1] + dp[i - 1][j]) % MOD;

        for (int j = 1; j <= n; j++) {
            if (j == b) continue;

            int left = b > j ? 1 : max(b + 1, (b + j) / 2 + 1);
            int right = b > j ? min(b - 1, (b + j - 1) / 2) : n;

            ll sum = (pref[right] - pref[left - 1] + MOD) % MOD;
            sum = (sum - dp[i - 1][j] + MOD) % MOD;
            dp[i][j] = sum;
        }
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) ans += dp[k][i], ans %= MOD;
    cout << ans << endl;
}