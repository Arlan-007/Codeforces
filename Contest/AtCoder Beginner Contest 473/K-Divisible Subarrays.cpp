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
    // cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> A(n);
        for (int i = 0; i < n; i++) cin >> A[i];

        vector<ll> pref(n + 1, 0);
        for (int i = 0; i < n; i++) pref[i + 1] = (pref[i] + A[i]) % k;

        vector<int> dp(n + 1, 0);
        int best = 0;
        map<ll, int> mp;
        mp[0] = 0;

        for (int i = 1; i <= n; i++) {
            ll r = pref[i];
            int op1 = (mp.count(r) ? mp[r] + 1 : INT_MIN);
            int op2 = best;

            dp[i] = max(op1, op2);
            best = max(best, dp[i]);
            mp[r] = max(mp[r], dp[i]);
        }

        cout << dp[n] << endl;
    }
}