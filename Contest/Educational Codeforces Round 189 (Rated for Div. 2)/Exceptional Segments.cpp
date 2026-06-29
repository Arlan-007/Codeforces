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
const int MOD = 998244353;

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

ll count(ll L, ll R, int m) {
    if (L > R) return 0;
    ll first = L + ((m - L % 4 + 4) % 4);
    if (first > R) return 0;
    return (R - first) / 4 + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        ll n, x;
        cin >> n >> x;

        ll left = 1 + count(1, x - 1, 3);
        ll left_ = count(0, x - 1, 1);
        ll right = count(x, n, 3);
        ll right_ = count(x, n, 1);

        ll ans = ( (left % MOD) * (right % MOD) ) % MOD;
        ans = (ans + (left_ % MOD) * (right_ % MOD)) % MOD;
        cout << ans << '\n';
    }

    return 0;
}