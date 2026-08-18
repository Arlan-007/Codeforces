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

    int t = 1;
    cin >> t;
    while (t--) {
        ll n, x; cin >> n >> x;
        vector<vector<pair<ll,ll>>> v(n);
        vector<vector<array<ll, 3>>> g(n);
        for (int i = 0, m; i < n; i++) {
            cin >> m;
            v[i].resize(m);
            for (auto &[a,d] : v[i]) cin >> a;
            for (auto &[a,d] : v[i]) {cin >> d; d -= a;}

            ll sum = 0, need = 0;
            for (int j = 0; j < m; j++) {
                auto [a,d] = v[i][j];
                need = max(need, a - sum);
                sum += d;

                if (sum >= 0) {
                    g[i].push_back({need, sum, j + 1});
                    sum = need = 0;
                }
            }
        }

        priority_queue<array<ll, 3>, vector<array<ll, 3>>, greater<array<ll, 3>>> pq;
        vector<int> h(n);

        for (int i = 0; i < n; i++) if (g[i].size()) pq.push({g[i][0][0], i, 0});
        while (pq.size() && pq.top()[0] <= x) {
            auto [need, i, k] = pq.top();
            pq.pop();

            x += g[i][k][1];
            h[i] = g[i][k][2];
            if (++k < g[i].size()) pq.push({g[i][k][0], i, k});
        }

        pair<ll,ll> ans = {0,1};
        for (int i = 0; i < n; i++) {
            ll money = x;
            ll j = h[i];
            while (j < v[i].size() && money >= v[i][j].first) money += v[i][j++].second;
            ans.first = max(ans.first, j);
            if (ans.first == j) ans.second = i+1;
        }
        cout << ans.first << ' ' << ans.second << '\n';
    }
}