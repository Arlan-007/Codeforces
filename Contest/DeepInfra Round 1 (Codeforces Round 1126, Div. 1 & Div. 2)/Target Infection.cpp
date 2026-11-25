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
        ll n, m, k; cin >> n >> m >> k;
        vector<pair<ll,ll>> a(n), v;
        for (auto &[l, r] : a) {
            cin >> l >> r;
            v.push_back({l, -1});
            v.push_back({r + 1, 1});
            v.push_back({l - m, 1});
            v.push_back({r + 1 - m, -1});
        }
        sort(v.begin(), v.end());

        auto chk = [&](ll x) {
            auto it = upper_bound(a.begin(), a.end(), make_pair(x, INF));
            if (it == a.begin()) return 0LL;
            it--;
            return it->second >= x ? 1LL : 0LL;
        };

        ll f = 0;
        for (auto [l, r] : a) f += max(0LL, min(r, m) - l + 1);
        if (f == k) {
            cout << 1 << '\n';
            continue;
        }

        ll cur = 1, d = chk(m + 1) - chk(1);
        bool found = false;
        for (int i = 0; i < v.size();) {
            ll x = v[i].first, chg = 0;
            while (i < v.size() && v[i].first == x) chg += v[i++].second;

            if (x <= cur) continue;
            ll nf = f + (x - cur) * d;
            if (min(f, nf) <= k && k <= max(f, nf)) {
                cout << cur + (k - f) / d << '\n';
                found = true;
                break;
            }
            f = nf, cur = x, d += chg;
        }

        if (!found) cout << -1 << '\n';
    }
}