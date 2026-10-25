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
        vector<vector<int>> g(n + 1);
        for (int i = 0; i < n - 1; i++) {
            int u, v; cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector<int> dep(n + 1, -1), top(n + 1), dis(n + 1, -1);
        queue<int> q; q.push(1); dep[1] = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : g[u]) {
                if (dep[v] == -1) {
                    dep[v] = dep[u] + 1;
                    top[v] = u == 1 ? v : top[u];
                    q.push(v);
                }
            }
        }

        q.push(n); dis[n] = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : g[u]) {
                if (dis[v] == -1) {
                    dis[v] = dis[u] + 1;
                    q.push(v);
                }
            }
        }

        int ans = dep[n];
        while (m--) {
            int v; cin >> v;
            if (top[v] == top[n]) ans = max(ans, dis[v] + 1);
        }
        cout << ans << '\n';
    }
}