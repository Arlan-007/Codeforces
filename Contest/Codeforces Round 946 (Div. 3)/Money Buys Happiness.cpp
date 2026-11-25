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
        ll m, x, tot = 0, ans = 0; cin >> m >> x;
        vector<ll> dp(50001, 1LL << 60); dp[0] = 0;
        for (int i = 0; i < m; i++) {
            ll c, h; cin >> c >> h;
            for (int j = tot; j >= 0; j--) if (dp[j] + c <= i * x) dp[j + h] = min(dp[j + h], dp[j] + c), ans = max(ans, j + h);
            tot += h;
        }
        cout << ans << '\n';
    }
}