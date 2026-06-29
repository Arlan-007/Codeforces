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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        ll n, k, x;
        cin >> n >> k >> x;
    
        vector<ll> a(n);
        ll sum = 0;
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        ll full = x / sum;
        ll rem = x % sum;
        if (full > k || (full == k && rem > 0)) {
            cout << 0 << "\n";
            continue;
        }
        ll rem_len = 0;
        if (rem > 0) {
            ll suff = 0;
            for (ll i = n - 1; i >= 0; i--) {
                suff += a[i];
                if (suff >= rem) {
                    rem_len = n - i;
                    break;
                }
            }
        }
        ll need = full * n + rem_len;
        cout << n * k - need + 1 << "\n";
    }
}