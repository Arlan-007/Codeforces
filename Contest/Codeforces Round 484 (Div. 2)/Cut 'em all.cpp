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

    int t = 1;
    // cin >> t;
    while (t--) {
        int n, ans = 0; cin >> n;
        if (n % 2) {
            cout << -1 << '\n';
            continue;
        }

        vector<int> par(n + 1), ord{1}, sz(n + 1, 1);
        vector<vector<int>> adj(n + 1);
        for (int i = 1; i < n; i++) {
            int u, v; cin >> u >> v;
            adj[u].push_back(v); adj[v].push_back(u);
        }
        for (int i = 0; i < n; i++) {
            int u = ord[i];
            for (int v : adj[u]) {
                if (v == par[u]) continue;
                par[v] = u; ord.push_back(v);
            }
        }

        for (int i = n - 1; i > 0; i--) {
            int u = ord[i];
            if (sz[u] % 2 == 0) ans++;
            sz[par[u]] += sz[u];
        }
        cout << ans << '\n';
    }
}
