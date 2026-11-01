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
const int MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<int> dp(m + 3), pref(m + 3);
        dp[1] = dp[2] = 1;

        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= m + 2; j++) pref[j] = (pref[j - 1] + dp[j]) % MOD;
            for (int j = 3; j <= m + 2; j++) dp[j] = (pref[j] - pref[j / 2] + MOD) % MOD;
            dp[2] = pref[2];
        }
        cout << dp[m + 2] << '\n';
    }
}