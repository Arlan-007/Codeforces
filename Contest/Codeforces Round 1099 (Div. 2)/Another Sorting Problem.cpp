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

    int t = 1;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        ll K = 0;
        for (int i = 0; i + 1 < n; i++)
            K = max(K, a[i] - a[i + 1]);
        if (K == 0) {
            cout << "YES\n";
            continue;
        }

        bool can0 = true, can1 = true;
        for (int i = 0; i + 1 < n; i++) {
            bool nxt0 = false, nxt1 = false;

            if (a[i] > a[i + 1]) {
                if (can0) nxt1 = true;
            } else {
                ll gap = a[i + 1] - a[i];
                if (can0) nxt0 = true;
                if (can0) nxt1 = true;
                if (can1) nxt1 = true;
                if (gap >= K && can1)
                    nxt0 = true;
            }

            can0 = nxt0;
            can1 = nxt1;

            if (!can0 && !can1)
                break;
        }

        cout << (can0 || can1 ? "YES" : "NO") << '\n';
    }

    return 0;
}