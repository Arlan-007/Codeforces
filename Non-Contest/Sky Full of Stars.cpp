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

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")

using ll = long long;

const ll INF = (ll) 4e18;
const ll NEG = -INF;
const int MOD = 998244353;

ll power(ll a, ll b) {
    ll r = 1;
    while (b) {
        if (b & 1) r = r * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<ll> fact(n + 1), invFact(n + 1);
        fact[0] = 1;

        for (int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i % MOD;
        invFact[n] = power(fact[n], MOD - 2);
        for (int i = n; i >= 1; --i) invFact[i - 1] = invFact[i] * i % MOD;

        auto C = [&](int k) {return fact[n] * invFact[k] % MOD * invFact[n - k] % MOD;};

        ll x = power(3, n - 1);
        ll p = power(x, n);
        ll row = p * 3 % MOD;
        ll step = power((MOD+1)/3, n);

        ll ans = 0;
        for (int i = 1; i <= n; ++i) {
            ll mix = (power((x - 1 + MOD) % MOD, n) - p + MOD) % MOD;
            ll val = (2 * row + 3 * mix) % MOD;
            val = val * C(i) % MOD;

            if (i & 1) ans = (ans + val) % MOD;
            else  ans = (ans - val + MOD) % MOD;

            x = x * (MOD+1)/3 % MOD;
            p = p * step % MOD;
            row = row * step % MOD * 3 % MOD;
        }
        cout << ans << '\n';
    }
}