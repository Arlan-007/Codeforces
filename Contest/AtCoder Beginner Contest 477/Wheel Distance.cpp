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

    int n, q; cin >> n >> q;
    vector<ll> a(n + 1), b(n + 2, 0), pref(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + a[i];

    vector<ll> dist = b;
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    for (int i = 1; i <= n; i++) pq.push({dist[i], i});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d != dist[u]) continue;

        int v = u == n ? 1 : u + 1;
        if (dist[v] > d + a[u]) pq.push({dist[v] = d + a[u], v});

        v = u == 1 ? n : u - 1;
        if (dist[v] > d + a[v]) pq.push({dist[v] = d + a[v], v});
    }

    while (q--) {
        int s, t; cin >> s >> t;
        if (s == n + 1) {
            cout << dist[t] << '\n';
            continue;
        }
        if (t == n + 1) {
            cout << dist[s] << '\n';
            continue;
        }

        ll x = s < t ? pref[t - 1] - pref[s - 1]: pref[n] - pref[s - 1] + pref[t - 1];
        cout << min({x, pref[n] - x, dist[s] + dist[t]}) << '\n';
    }
}