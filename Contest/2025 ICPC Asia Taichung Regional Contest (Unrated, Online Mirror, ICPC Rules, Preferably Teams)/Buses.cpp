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
#include <iomanip>
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

    ll n, m, l, x, y; cin >> n >> m >> l >> x >> y;
    vector<pair<ll, ll>> B(n), P(m);
    for (auto &[s, t] : B) cin >> s >> t;
    for (int i = 0; i < m; i++) cin >> P[i].first, P[i].second = i;
    sort(B.begin(), B.end()); sort(P.begin(), P.end());

    priority_queue<pair<ll, ll>> pq;
    vector<double> ans(m);
    int j = 0;

    for (auto [p, id] : P) {
        while (j < n && B[j].first <= p) {
            auto [s, t] = B[j++];
            pq.push({y * s + (x - y) * t, x * t + y * (t - s)});
        }
        while (!pq.empty() && pq.top().second < x * p) pq.pop();

        ll best = x * p;
        if (!pq.empty()) best = max(x * p, pq.top().first);
        ans[id] = double(l - p) / y - double(best - x * p) / (x * y);
    }

    cout << fixed << setprecision(12);
    for (double time : ans) cout << time << '\n';
}