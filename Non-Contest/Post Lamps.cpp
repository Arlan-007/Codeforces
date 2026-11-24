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

    int t = 1;
    // cin >> t;
    while (t--) {
        int n, m, k, x; cin >> n >> m >> k;
        vector<int> p(n);
        while (m--) cin >> x, p[x] = -1;
        for (int i = 1; i < n; i++) p[i] = (p[i] == -1 ? p[i - 1] : i);

        if (p[0] == -1) {
            cout << -1 << '\n';
            return 0;
        }

        ll ans = 1LL << 60;
        for (int l = 1; l <= k; l++) {
            int cost, pos = 0, cnt = 1; cin >> cost;
            while (pos + l < n && p[pos + l] > pos) pos = p[pos + l], cnt++;
            if (pos + l >= n) ans = min(ans, 1LL * cnt * cost);
        }
        cout << (ans == (1LL << 60) ? -1 : ans) << '\n';
    }
}