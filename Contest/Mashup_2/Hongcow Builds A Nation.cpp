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

int root[1005], sz[1005], gov[1005];

int find(int x) {
    return root[x] == x ? x : root[x] = find(root[x]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        int n, m, k; cin >> n >> m >> k;
        for(int i = 0; i < k; i++) cin >> gov[i];
        for(int i = 1; i <= n; i++) root[i] = i;

        for(int i = 0; i < m; i++) {
            int u, v; cin >> u >> v;
            root[find(v)] = find(u);
        }

        for(int i = 1; i <= n; i++) sz[find(i)]++;

        int ans = 0, mx = 0, left = n;
        for(int x : gov) {
            int r = find(x);
            mx = max(mx, sz[r]);
            ans += sz[r] * (sz[r] - 1) / 2;
            left -= sz[r];
        }

        ans -= mx * (mx - 1) / 2;
        ans += (mx + left) * (mx + left - 1) / 2;
        cout << ans - m << "\n";
    }
}
