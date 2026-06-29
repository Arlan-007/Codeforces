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

ll summ(ll x) {return x * (x + 1) / 2;}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n + 1), b(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) cin >> b[i];

        vector<vector<int>> good(n + 2), bad(n + 2);
        for (int i = 1; i <= n; i++) {
            if (a[i] == b[i] && a[i] <= n) good[a[i]].push_back(i);
            else {
                if (a[i] <= n) bad[a[i]].push_back(i);
                if (b[i] <= n) bad[b[i]].push_back(i);
            }
        }

        auto nxt = [&](const vector<int>& v, int p) {
            auto it = lower_bound(v.begin(), v.end(), p);
            return it != v.end() ? *it : n + 1;
        };

        vector<int> dp(n + 2, n + 1);
        for (int i = n; i >= 1; i--) {
            if (a[i] == b[i] && a[i] < n) {
                int need = a[i] + 1;
                int pos = i + 1;
                int nextGood = nxt(good[need], pos);
                int nextBad = nxt(bad[need], pos);

                if (nextBad < nextGood) dp[i] = nextBad;
                else if (nextGood <= n) dp[i] = dp[nextGood];
            }
        }

        ll ans = 0;
        for (int L = 1; L <= n; L++) {
            int need = 1;
            int pos = L;
            int nextGood = nxt(good[need], pos);
            int nextBad = nxt(bad[need], pos);

            int stop = n + 1;
            if (nextBad < nextGood) stop = nextBad;
            else if (nextGood <= n) stop = dp[nextGood];

            ans += stop - pos;
        }
        cout << ans << '\n';
    }
}