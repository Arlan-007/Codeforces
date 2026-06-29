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
static const ll MOD = 676767677LL;

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

    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;

        vector<int> b(n);
        vector<ll> cnt(m, 0);

        for (int i = 0; i < n; ++i) {
            cin >> b[i];
            cnt[b[i]]++;
        }

        vector<ll> pref(m + 1, 0);
        for (int t = 0; t < m; ++t) {
            pref[t + 1] = pref[t] + cnt[t];
        }

        ll ans = 1;

        for (int i = 0; i < n; ++i) {
            int t = b[i];
            if (t == 0) continue;

            int mini = 1e9;
            if (i > 0) mini = min(mini, b[i - 1]);
            if (i + 1 < n) mini = min(mini, b[i + 1]);

            if (mini >= t) {
                ans = 0;
                break;
            }

            ll ways;
            if (mini == t - 1) {
                ways = pref[t];
            } else {
                ways = cnt[t - 1];
            }

            ans = (ans * ways) % MOD;
        }

        cout << ans % MOD << '\n';
    }

    return 0;
}