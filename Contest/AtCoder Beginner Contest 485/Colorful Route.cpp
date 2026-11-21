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

    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, c; cin >> u >> v >> c;
        g[u].push_back({v, c});
    }

    vector<int> fs(n + 1, -1);
    vector<bool> done(n + 1, false);
    queue<tuple<int, int, int>> q;
    q.push({1, 0, 0});

    while (!q.empty()) {
        auto [u, c, d] = q.front();
        q.pop();

        if (u == n) {
            cout << d << '\n';
            return 0;
        }

        if (done[u] || fs[u] == c) continue;
        if (fs[u] == -1) {
            fs[u] = c;
            for (auto [v, col] : g[u])
                if (col != c) q.push({v, col, d + 1});
        } else {
            done[u] = true;
            for (auto [v, col] : g[u])
                if (col == fs[u]) q.push({v, col, d + 1});
        }
    }
    cout << -1 << '\n';
}