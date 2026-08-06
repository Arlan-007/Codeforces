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
        ll n, m ,d; cin >> n >> m >> d;
        vector<ll> p(m), r(m + 1);

        for (int i = 0; i < m; i++) {
            ll r_;
            cin >> p[i] >> r_;
            r[i+1] = r_ + r[i];
        }

        ll sum = r[m];
        ll mx = LLONG_MIN;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                ll next = p[i] + p[j] + 1;
                ll bin = upper_bound(p.begin(), p.end(), next % n) - p.begin();
                mx = max(mx, r[i+1] + r[j+1] - r[bin] - next/n * sum);
            }
        }
        cout << (mx > d ? "YES\n" : "NO\n");
    }
}