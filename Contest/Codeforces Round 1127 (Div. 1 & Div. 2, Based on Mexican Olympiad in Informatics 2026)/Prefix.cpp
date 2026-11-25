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
        int n; cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        ll mn = a[0], mx = a[0], ans = a[0];
        for (int i = 1; i < n; ++i) {
            ans = max({ans, a[i], a[i] - mn, a[i] + mx});
            ll nmn = min({a[i], a[i] + mn, a[i] + 2 * mn, a[i] + mx, a[i] + 2 * mx});
            ll nmx = max({a[i], a[i] + mn, a[i] + 2 * mn, a[i] + mx, a[i] + 2 * mx});
            mn = nmn, mx = nmx;
        }
        cout << ans << '\n';
    }
}