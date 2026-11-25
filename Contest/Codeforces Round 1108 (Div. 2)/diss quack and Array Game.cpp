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
        vector<int> a(n);
        for (int &x : a) cin >> x;

        ll ans = INF;
        for (int k = 0; k <= 17; k++) {
            int pw = 1 << k;
            ll cur = k;

            for (int x : a) {
                int b = ((x + pw - 1) / pw) * pw;

                ll best = INF;
                for (int y = b; y <= b + 32; y += pw) {
                    ll cost = y - x + __builtin_popcount(y) + (32 - __builtin_clz(y)) - k - 1;
                    best = min(best, cost);
                }
                cur += best;
            }
            ans = min(ans, cur);
        }
        cout << ans << '\n';
    }
}