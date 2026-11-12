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
        int n; cin >> n;
        vector<vector<int>> g(n + 1);
        for (int i = 1; i < n; i++) {
            int u, v; cin >> u >> v;
            g[u].push_back(v); g[v].push_back(u);
        }

        queue<int> q;
        vector<int> deg(n + 1), sz(n + 1, 1), larg(n + 1);
        for (int u = 1; u <= n; u++) {
            deg[u] = g[u].size();
            if (u != 1 && deg[u] == 1) q.push(u);
        }

        int sec = 0, lost = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop(), deg[u] = 0;

            for (int p : g[u]) {
                if (deg[p] == 0) continue;

                int s = sz[u];
                sz[p] += s;

                if (s > larg[p]) swap(s, larg[p]);
                if (p == 1 && s > sec) swap(s, sec);
                lost = max(lost, s);

                if (--deg[p] == 1 && p != 1) q.push(p);
                break;
            }
        }
        cout << n - lost << '\n';
    }
}