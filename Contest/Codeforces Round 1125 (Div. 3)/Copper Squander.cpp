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

class DSU {
    vector<int> p, sz;
public:
    DSU(int n) : p(n), sz(n, 1) {
        iota(p.begin(), p.end(), 0);
    }

    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }

    void unite(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a, b);
        p[b] = a;
        sz[a] += sz[b];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        ll n, m, q, total = 0; cin >> n >> m >> q;
        vector<array<int, 3>> edges(m);
        for (auto &[d, u, v] : edges) cin >> u >> v >> d, total += d;
        sort(edges.begin(), edges.end());

        DSU dsu(n + 1);
        vector<ll> pref{0};
        for (auto [d, u, v] : edges) {
            if (dsu.find(u) == dsu.find(v)) continue;
            dsu.unite(u, v), pref.push_back(pref.back() + d);
        }

        while (q--) {
            ll x; cin >> x;
            int lo = 0, hi = pref.size() - 1;
            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;
                if (pref[mid + 1] - pref[mid] <= x * (n - 1 - mid)) lo = mid + 1;
                else hi = mid;
            }
            ll need = n - lo - 1;
            cout << total - pref[lo] - x * need * (need + 1) / 2 << (q ? ' ' : '\n');
        }
    }
}