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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<ll> a(n * m), b(n * m);
        for (int i = 0; i < n * m; i++) cin >> a[i], b[i] = a[i];

        auto func = [&](int st, int stp, int len) {
            ll par = (len - 1) % 2, l = 0, r = 0;
            for (int i = par; i < len; i += 2) r += b[st + i * stp];

            for (int i = 0; i < len; i++) {
                auto &v = b[st + i * stp];
                ll x = v;
                v = (i % 2 == 0 ? r : 0) + (i % 2 == par ? l : 0);
                if (i % 2 == 0) l += x;
                if (i % 2 == par) r -= x;
            }
        };

        for (int i = 0; i < n; i++) func(i * m, 1, m);
        for (int i = 0; i < m; i++) func(i, m, n);

        ll ans = 0;
        for (int i = 0; i < n * m; i++) ans = (ans + a[i] * (b[i] % MOD)) % MOD;
        if ((n + m) % 2) ans = -ans;
        cout << (ans + MOD) % MOD << '\n';
    }
}