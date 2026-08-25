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

const int MAXN = 3e5 + 5;
vector<ll> adj[MAXN];
bool vis[MAXN], has_x[MAXN];
ll sub_size[MAXN];

int dfs(int u, int x) {
    vis[u] = true;
    sub_size[u] = 1;
    has_x[u] = (u == x);

    for (int v : adj[u]) {
        if (!vis[v]) {
            sub_size[u] += dfs(v, x);
            has_x[u] |= has_x[v];
        }
    }
    return sub_size[u];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        int n, x, y; cin >> n >> x >> y;
        for (int i = 0; i < n - 1; i++) {
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(y, x);

        int X = n;
        for (int v : adj[y]) {
            if (has_x[v]) {
                X = sub_size[v];
                break;
            }
        }

        ll bad = sub_size[x] * (n - X);
        cout << 1LL * n * (n - 1) - bad << "\n";
    }
}