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
        ll n, k; cin >> n >> k;
        vector<ll> h(n);
        for (auto &x : h) cin >> x;
        rotate(h.begin(), max_element(h.begin(), h.end()), h.end());
        h.push_back(h[0]);

        int lo = 0, hi = h[0];
        while (lo < hi) {
            ll mid = lo + (hi - lo) / 2, used = 0;
            auto a = h;
            for (int i = 1; i <= n; i++) a[i] = max(a[i], a[i - 1] - mid);
            for (int i = n - 1; i >= 0; i--) a[i] = max(a[i], a[i + 1] - mid), used += a[i] - h[i];

            if (used <= k) hi = mid;
            else lo = mid + 1;
        }
        cout << lo << '\n';
    }
}