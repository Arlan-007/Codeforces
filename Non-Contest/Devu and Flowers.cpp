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

vector<ll> f(22), inv(55);

ll nCr(ll n, ll r) {
    if (r > n) return 0;
    if (n - r < r) r = n - r;
    n %= MOD;
    ll ans = 1;
    for(int i = 0; i < r; i++) {
        ans = (ans * (n - i)) % MOD;
        ans = (ans * inv[i + 1]) % MOD;
    }
    return ans;
}

ll modpow(ll a, ll b, ll mod) {
    ll res = 1;
    while (b) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        ll n, s; cin >> n >> s;
        for (int i = 0; i < n; i++) cin >> f[i];
        for (int i = 1; i <= 50; i++) inv[i] = modpow(i, MOD - 2, MOD);

        ll ans = 0;
        for (int mask = 0; mask < (1<<n); mask++) {
            ll x = s;
            ll odd = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1<<i)) {
                    x -= (f[i] + 1);
                    odd++;
                }
            }

            if (x < 0) continue;
            ll temp = nCr(x + n - 1, n - 1);
            if (odd & 1) temp = -temp;
            ans = (ans + temp) % MOD;
        }

        if (ans < 0) ans += MOD;
        cout << ans << endl;

    }
}