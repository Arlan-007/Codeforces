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

#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")

using ll = long long;
const ll INF = (ll) 4e18;
const int MOD = 1'000'000'007;

ll binpow(ll a, ll b, ll mod = MOD) {
    ll res = 1;
    while (b) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

ll modinv(ll a, ll mod = MOD) {
    return binpow(a, mod - 2, mod);
}

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool in(int x, int y, int n, int m) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll x, y;
    cin >> x >> y;
    vector<ll> dp(y + 1, 0);
    dp[1] = x;

    for (ll i = 2; i <= x; i++) {
        vector<ll> ndp(y + 1, 0);
        ll total = 0;
        for (int j = 1; j <= y; j++) total = (total + dp[j]) % MOD;
        ndp[1] = (x - 1) * total % MOD;
        for (int j = 2; j <= y; j++)
            ndp[j] = dp[j - 1];
        dp = ndp;
    }

    ll ans = 0;
    for (int j = 1; j <= y; j++) ans = (ans + dp[j]) % MOD;
    cout << ans << endl;
}