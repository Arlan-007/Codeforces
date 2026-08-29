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
        int n, m; cin >> n >> m;
        vector<ll> cnt(m + 2, 0);
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            cnt[x]++;
        }

        ll ans = 0, large = 0;
        for (int v = m; v >= 1; v--) {
            ll cur = cnt[v] + large + (2LL * v <= m ? cnt[2 * v] : 0);
            ans = max(ans, cur);
            large += cnt[v];
        }
        cout << ans << "\n";
    }
}