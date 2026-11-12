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
        ll n, l; cin >> n >> l;
        vector<ll> a(n), pref(n + 1);
        for (auto &x : a) cin >> x;
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++) pref[i + 1] = pref[i] + a[i];

        ll ans = pref[n - 1], k = l - 1;
        for (int i = 1; i * i <= k; i++) {
            ll p = upper_bound(a.begin(), a.end() - 1, i) - a.begin();
            ll cost = max(pref[n - 1] - pref[p] - (n - p - 1) * i, 0LL);
            cost += max(a[n - 1] - k / i, 0LL);
            ans = min(ans, cost);
        }
        cout << ans << endl;
    }
}