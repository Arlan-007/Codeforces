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
        ll n, sum = 0, ans = 0; cin >> n;
        vector<ll> pref(n);
        for (ll &x : pref) cin >> x, sum += x, x = sum;
        pref.pop_back(); n--;

        if (n == 0) {
            cout << (sum < 0 ? -1 : 0) << '\n';
            continue;
        }

        auto pref2 = pref;
        sort(pref2.begin(), pref2.end());
        if (pref2.front() < 0 || pref2.back() > sum) {
            cout << -1 << '\n';
            continue;
        }

        vector<int> bit(n + 1);
        for (int i = n - 1; i >= 0; i--) {
            int r = lower_bound(pref2.begin(), pref2.end(), pref[i]) - pref2.begin() + 1;
            for (int j = r - 1; j > 0; j -= j & -j) ans += bit[j];
            for (int j = r; j <= n; j += j & -j) bit[j]++;
        }
        cout << ans << '\n';
    }
}