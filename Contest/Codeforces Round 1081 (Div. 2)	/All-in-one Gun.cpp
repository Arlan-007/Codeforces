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

    int t;
    cin >> t;
    while (t--) {
        ll n, h, k;
        cin >> n >> h >> k;

        vector<ll> a(n);
        ll S = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            S += a[i];
        }
        ll full = (h - 1) / S;
        ll remain = h - full * S;
        vector<ll> suf(n);
        suf[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; i--) suf[i] = max(suf[i + 1], a[i]);
        ll sum = 0;
        ll minp = 1e18;
        ll best = n;
        for (int i = 0; i < n; i++) {
            sum += a[i];
            minp = min(minp, a[i]);
            if (sum >= remain) {
                best = i + 1;
                break;
            }
            if (i + 1 < n) {
                ll changed = sum - minp + suf[i + 1];
                if (changed >= remain) {
                    best = i + 1;
                    break;
                }
            }
        }
        cout << full * (n + k) + best << "\n";
    }
}
