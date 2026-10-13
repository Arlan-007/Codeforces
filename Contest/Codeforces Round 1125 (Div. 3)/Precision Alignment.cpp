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
        ll n, k, lo = INF; cin >> n >> k;
        vector<array<ll, 3>> a(n);
        for (auto &v : a) cin >> v[0] >> v[1] >> v[2], lo = min(lo, v[0] + v[1] + v[2]);

        ll hi = lo + k + 1;
        while (hi >= lo) {
            ll mid = lo + (hi - lo) / 2, cost = 0;
            for (auto v : a) {
                ll s = v[0] + v[1] + v[2];
                if (s >= mid) continue;
                if (v[0] == v[1] && v[1] == v[2]) {cost = k + 1; break;}

                ll e = 0;
                if (v[0] <= v[1] && v[1] <= v[2]) e = min(v[1] - v[0], v[2] - v[1]) + 1;
                cost += mid - s + 2 * e;
                if (cost > k) break;
            }
            if (cost <= k) lo = mid + 1;
            else hi = mid - 1;
        }
        cout << lo - 1 << '\n';
    }
}