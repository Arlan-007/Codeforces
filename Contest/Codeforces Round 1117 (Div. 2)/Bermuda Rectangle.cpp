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
        ll S, q; cin >> S >> q;

        vector<ll> d{0};
        for (ll i = 1; i <= S / i; i++)
            if (S % i == 0) {
                d.push_back(i);
                if (i != S / i) d.push_back(S / i);
            }
        sort(d.begin(), d.end());
        vector<ll> pref(d.size());

        for (int i = 1; i < d.size(); i++) pref[i] = pref[i - 1] + (d[i] - d[i - 1]) * (S / d[i]);
        auto sum = [&](ll x) {
            int i = lower_bound(d.begin(), d.end(), x) - d.begin();
            return pref[i - 1] + (x - d[i - 1]) * (S / d[i]);
        };

        while (q--) {
            ll x, y;
            cin >> x >> y;
            ll z = min(x, *prev(upper_bound(d.begin(), d.end(), S / y)));
            cout << z * y + sum(x) - sum(z) << '\n';
        }
    }
}