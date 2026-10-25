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

ll cost(ll x) {
    if (x == 0) return 0;
    if (x == 1) return 5;

    int k = 63 - __builtin_clzll(x + 2);
    ll p = 1LL << k, w = p - 2;
    ll cur = p + k - 1, nex = 2 * p + k;
    return min(nex, cur + cost(x - w));
}

ll f(ll n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return cost(n - 1) - n;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        ll l, r, ans = 0; cin >> l >> r;
        for (ll n = l; n <= r; ++n) ans = (ans + f(n) % MOD) % MOD;
        cout << ans << '\n';
    }
}