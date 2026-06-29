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
    ll L, Q;
    cin >> L >> Q;

    vector<tuple<ll,ll,ll,ll>> ops(Q);
    for (auto& [t,a,b,c] : ops) {
        cin >> t;
        if (t == 1) cin >> a >> b >> c;
    }
    vector<ll> ans(L + 1, 0);
    set<ll> free;
    for (ll i = 1; i <= L; i++) free.insert(i);

    ll flips = 0;
    for (ll i = Q - 1; i >= 0; i--) {
        auto [t,a,b,c] = ops[i];
        if (t == 2) { flips++; continue; }
        if (flips % 2) { a = L-b+1; b = L-a+1; }
        for (auto it = free.lower_bound(a); it != free.end() && *it <= b; it = free.erase(it))
            ans[*it] = c;
    }
    for (ll i = 1; i <= L; i++) cout << ans[i] << " ";
    cout << endl;
}
