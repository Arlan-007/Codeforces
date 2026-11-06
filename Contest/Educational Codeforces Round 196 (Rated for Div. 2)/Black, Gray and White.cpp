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

bool chk(const vector<vector<int>>& g, int k, int x) {
    int n = g.size() - 1;
    vector<int> side(n + 1), q = {x};
    side[x] = -1;

    for (int i = 0; i < q.size(); i++) {
        int u = q[i];
        for (int v : g[u]) {
            if (side[v]) continue;
            side[v] = u == x ? v : side[u];
            q.push_back(v);
        }
    }

    for (int i = 1; i < k - i; i++) if (k - i <= n && side[i] != side[k - i]) return true;
    return false;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, u, v; cin >> n;
        vector<vector<int>> g(n + 1);
        for (int i = 1; i < n; i++) cin >> u >> v, g[u].push_back(v), g[v].push_back(u);

        int ans = n + 1;
        if (n % 2) {
            if (chk(g, n, n)) ans = n;
            else if (chk(g, n + 2, 1)) ans = n + 2;
        }
        cout << ans << '\n';
    }
}