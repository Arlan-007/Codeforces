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
        ll n; cin >> n;

        int bits = 63 - __builtin_clzll(n);
        ll ans = 0;

        vector<ll> dp(70);
        dp[0] = dp[1] = 1;
        for (int i = 2; i < 70; i++)
            dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % MOD;

        for (int len = 1; len < bits; len++)
            ans = (ans + dp[len - 1]) % MOD;

        if (bits >= 1 && ((n >> (bits - 1)) & 1)) {
            int rem = bits - 1;

            vector<int> b(rem);
            for (int i = 0; i < rem; i++)
                b[i] = (n >> (rem - 1 - i)) & 1;

            vector<ll> f(rem + 2, 0);
            f[rem] = 1;

            for (int i = rem - 1; i >= 0; i--) {
                ll ways = 0;
                if (b[i] == 0) ways += f[i + 1];
                else ways += dp[rem - i - 1];

                if (i + 1 < rem && b[i + 1]) ways += f[i + 2];
                if (b[i] && rem - i >= 2)ways += dp[rem - i - 2];

                f[i] = ways % MOD;
            }

            ans = (ans + f[0]) % MOD;
        }

        cout << ans << "\n";
    }
}