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

int n, m;
vector<vector<pair<int, int>>> adj;

pair<vector<ll>, vector<int>> dijkstra(int s) {
    vector<ll> dist(n + 1, INF);
    vector<int> parent(n + 1, -1);
    vector<bool> vis(n + 1, false);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (vis[u]) continue;
        vis[u] = true;

        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    return {dist, parent};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    adj.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    auto [dist, parent] = dijkstra(1);

    if (dist[n] == INF) cout << -1 << "\n";
    else {
        vector<int> path;
        int curr = n;
        while (curr != -1) {
            path.push_back(curr);
            curr = parent[curr];
        }

        reverse(path.begin(), path.end());

        for (int i = 0; i < path.size(); i++) cout << path[i] << " ";
        cout << "\n";
    }
}