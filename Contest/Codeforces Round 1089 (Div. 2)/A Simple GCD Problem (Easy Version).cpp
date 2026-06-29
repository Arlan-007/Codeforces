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
#include <numeric>
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
        ll n; cin >> n;
        vector<ll> a(n) , b(n);
        for (auto &s : a) cin >> s;
        for (auto &s : b) cin >> s;

        ll count = 0;
        for (int i = 0; i < n; i++) {
            ll l;
            if (i == 0) {
                l = a[1];
            } else if (i == n - 1) {
                l = a[n - 2];
            } else {
                ll g = gcd(a[i - 1], a[i + 1]);
                l = a[i - 1] / g * a[i + 1];
            }

            if (l % a[i] != 0) {
                count++;
            }
        }

        cout << count << "\n";
    }
}