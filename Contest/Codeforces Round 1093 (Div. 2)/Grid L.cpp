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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        ll p, q;
        cin >> p >> q;

        ll K = 2LL * p + 4LL * q + 1;
        bool found = false;

        for (ll a = 3; a * a <= K; a += 2) {
            if (K % a == 0) {
                ll b = K / a;
                ll n = (a - 1) / 2;
                ll m = (b - 1) / 2;
                if (m - n <= p) {
                    cout << n << " " << m << "\n";
                    found = true;
                    break;
                }
            }
        }

        if (!found) cout << -1 << "\n";
    }

    return 0;
}