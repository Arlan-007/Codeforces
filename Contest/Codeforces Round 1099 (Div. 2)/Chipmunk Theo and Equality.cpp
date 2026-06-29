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

ll ancestor(ll a, ll b) {
    while (a != b) {
        if (a > b) a = (a + 1) / 2;
        else b = (b + 1) / 2;
    }
    return a;
}

ll dist(ll x, ll target) {
    ll steps = 0;
    while (x != target) {
        if (x & 1) x++;
        else x /= 2;
        steps++;
    }
    return steps;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        ll v = a[0];
        for (int i = 1; i < n; i++) v = ancestor(v, a[i]);

        bool flag = false;
        for (auto x : a) {
            if (x == v) flag = true;
        }

        ll ans1 = 0;
        for (auto x : a) ans1 += dist(x, v);
        ll ans = ans1;
        if (v == 1 || !flag) {
            ll t = 2 * v;
            ll ans2 = 0;
            for (auto x : a) ans2 += dist(x, t);
            ans = min(ans, ans2);
        }

        cout << ans << '\n';
    }
}
