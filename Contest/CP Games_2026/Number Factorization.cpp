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
        ll n;
        cin >> n;

        vector<pair<ll, int>> f;
        for (ll i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                int cnt = 0;

                while (n % i == 0) {
                    n /= i;
                    cnt++;
                }

                f.push_back({i, cnt});
            }
        }

        if (n > 1)
            f.push_back({n, 1});

        ll ans = 0;
        while (true) {
            ll cur = 1;
            bool ok = false;

            for (auto &x : f) {
                if (x.second > 0) {
                    cur *= x.first;
                    x.second--;
                    ok = true;
                }
            }

            if (!ok)
                break;

            ans += cur;
        }

        cout << ans << '\n';
    }
}