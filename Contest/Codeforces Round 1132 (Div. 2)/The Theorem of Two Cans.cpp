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

    string ty; cin >> ty;
    int t; cin >> t;
    while (t--) {
        if (ty == "first") {
            int n; cin >> n;
            string s; cin >> s;
            int p = s.find('1');
            vector<pair<int, int>> edges;
            for (int v = 2; v <= n; v++) edges.push_back({p == -1 || s[v - 2] == '1' ? 1 : p + 2, v});
            if (p == -1) edges.push_back({2, 3});

            cout << edges.size() << '\n';
            for (int i = 0; i < edges.size(); i++) {
                auto [u, v] = edges[i];
                if (u > v) swap(u, v);
                if (i % 2) swap(u, v);
                cout << u << ' ' << v << '\n';
            }
        } else {
            int n, m; cin >> n >> m;
            vector<vector<int>> adj(n);
            while (m--) {
                int u, v; cin >> u >> v, u--, v--;
                adj[u].push_back(v); adj[v].push_back(u);
            }

            vector<int> col(n + 1, -1); col[0] = 0;
            queue<int> q; q.push(0);
            bool flg = true;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int v : adj[u]) {
                    if (col[v] == -1) col[v] = col[u] ^ 1, q.push(v);
                    else if (col[v] == col[u]) flg = false;
                }
            }
            for (int i = 1; i < n; i++) cout << (flg ? col[i] : 0);
            cout << '\n';
        }
    }
}