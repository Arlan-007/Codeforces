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

#pragma GCC optimize("Ofast,unroll-loops,inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,lzcnt,bmi2,bmi,tune=native")

using ll = long long;

const ll INF = (ll) 4e18;
const ll NEG = -INF;
const int MOD = 1'000'000'007;

struct DSU{
    vector<int> p, sz;
    vector<ll> score;

    DSU(int n){
        p.assign(n, 0);
        sz.assign(n, 1);
        score.assign(n, 0);
        for (int i = 0; i < n; i++) p[i] = i;
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
        score[a] += score[b];
    }

    bool same(int u, int v){
        return find(u) == find(v);
    }

    int size(int u){
        u = find(u);
        return sz[u];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;

        DSU dsu(2 * n);
        vector<pair<int, int>> prev;

        for (int i = 0; i < n; i++) {
            if (s[i] == '1'){
                dsu.score[2 * i] = 1;
                dsu.unite(2 * i, 2 * i + 1);

                for (int j = 0; j < prev.size(); j++){
                    int l = prev[j].first;
                    int r = prev[j].second;
                    if (i >= l && i <= r) dsu.unite(2 * i, 2 * (i - 1) + j);
                }
                prev = {{i, i}};
                continue;
            }

            vector<pair<int, int>> nxt = {{0, i - 1}, {i + 1, n - 1}};
            for (int j = 0; j < nxt.size(); j++){
                auto [l, r] = nxt[j];
                dsu.score[2 * i + j] = r - l + 1;
            }
            for (int j = 0; j < prev.size(); j++){
                for (int k = 0; k < nxt.size(); k++){
                    auto [l1, r1] = prev[j];
                    auto [l2, r2] = nxt[k];
                    if (l2 > r1 || r2 < l1) continue;
                    dsu.unite(2 * i + k, 2 * (i - 1) + j);
                }
            }
            prev = nxt;
        }

        ll ans = 0;
        for (int i = 0; i < 2 * n; i++) ans = max(ans, dsu.score[i]);
        cout << ans << "\n";

    }
}