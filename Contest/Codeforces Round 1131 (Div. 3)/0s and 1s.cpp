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
const int MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<vector<int>> g(n);
        for (int i = 1, u, v; i < n; i++) {
            cin >> u >> v; u--, v--;
            g[u].push_back(v), g[v].push_back(u);
        }

        string x, y; cin >> x >> y;
        vector<int> q = {0}, par(n, -1), b(n);
        int ans = 0, p = 1;
        bool ok = true;

        for (int l = 0; l < n;) {
            int r = q.size(), bit = -1;
            while (l < r) {
                int u = q[l++], d = y[u] - x[u] - b[u], temp = (d + 2) % 2;
                if (bit != -1 && bit != temp) ok = false;
                bit = temp;

                for (int v : g[u]) if (v != par[u]) par[v] = u, b[v] = d < 0, q.push_back(v);
            }
            ans = (ans + 1LL * bit * p) % MOD;
            p = 2LL * p % MOD;
        }
        cout << (ok ? ans : -1) << '\n';
    }
}