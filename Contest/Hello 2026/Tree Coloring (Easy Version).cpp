#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using std::cout;
using std::endl;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int p;
    std::cin >> p;
    while (p--) {
        int n;
        std::cin >> n;

        std::vector<std::vector<int>> adj(n + 1);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            std::cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // BFS to compute distances
        std::vector<int> dist(n + 1, -1);
        std::queue<int> q;

        dist[1] = 0;
        q.push(1);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }

        // Build layers
        int maxd = *std::max_element(dist.begin(), dist.end());
        std::vector<int> layer_count(maxd + 1, 0);

        for (int v = 1; v <= n; v++) {
            layer_count[dist[v]]++;
        }

        int max_layer_size = 0;
        for (int x : layer_count) {
            if (x > max_layer_size) max_layer_size = x;
        }

        // Compute children count in the rooted tree
        std::vector<int> children(n + 1, 0);
        for (int u = 1; u <= n; u++) {
            for (int v : adj[u]) {
                if (dist[v] == dist[u] + 1) {
                    children[u]++;
                }
            }
        }

        // Final answer
        int answer = max_layer_size;
        for (int u = 1; u <= n; u++) {
            int need = children[u] + 1;
            if (need > answer) answer = need;
        }

        cout << answer << "\n";
    }

    return 0;
}
