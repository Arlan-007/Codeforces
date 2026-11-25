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
    // cin >> t;
    while (t--) {
        ll n, k; cin >> n >> k;
        vector<ll> inv(k + 2), B(k + 1), power(k + 2);

        inv[1] = 1;
        for (int i = 2; i <= k + 1; ++i) inv[i] = MOD - MOD / i * inv[MOD % i] % MOD;

        // Bernoulli numbers:
        // B_m = -1/(m+1) * sum(C(m+1,j) * B_j)
        B[0] = 1;

        for (int m = 1; m <= k; ++m) {
            ll sum = 0, C = 1;
            for (int j = 0; j < m; ++j) {
                sum = (sum + C * B[j]) % MOD;
                C = C * (m + 1 - j) % MOD * inv[j + 1] % MOD;
            }
            B[m] = (MOD - sum) * inv[m + 1] % MOD;
        }

        power[0] = 1;
        for (int i = 1; i <= k + 1; ++i) power[i] = power[i - 1] * n % MOD;

        ll ans = 0, C = 1;
        for (int j = 0; j <= k; ++j) {
            ll term = C * B[j] % MOD * power[k + 1 - j] % MOD;

            if (j & 1) ans = (ans - term + MOD) % MOD;
            else ans = (ans + term) % MOD;
            C = C * (k + 1 - j) % MOD * inv[j + 1] % MOD;
        }
        cout << ans * inv[k + 1] % MOD << '\n';
    }
}