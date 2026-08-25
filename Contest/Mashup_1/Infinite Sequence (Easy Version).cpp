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
        ll n, l, r; cin >> n >> l >> r;
        vector<ll> a(n), pref(n + 1);
        for (ll i = 0; i < n; i++) cin >> a[i];

        pref[0] = 0;
        for (int i = 1; i <= n; i++) {
            pref[i] = pref[i - 1] + a[i - 1];
        }

        if (n % 2 == 0) {
            n++;
            int cur = pref[n / 2] & 1;
            a.push_back(cur);
            pref.push_back(pref.back() + cur);
        }
    }
}