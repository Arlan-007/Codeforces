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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,m,c;
    cin >> n >> m >> c;
    vector<ll> a(n), b(m), pref(m+1,0);
    for (auto &it : a) cin >> it;
    for (auto &it : b) cin >> it;
    pref[1]=b[0];
    for (int i = 1; i < m; i++ ) pref[i+1]=b[i]+pref[i];
    for (ll i = 0; i < n; i++) {
        ll r = min(i + 1, m);
        ll l = max(0LL, i - (n - m));
        a[i] = (a[i] + (pref[r] - pref[l]))%c;
        cout << a[i] << " ";
    }
    cout << endl;
}