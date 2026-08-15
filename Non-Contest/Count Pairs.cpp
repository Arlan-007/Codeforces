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
        ll n, p, k; cin >> n >> p >> k;
        vector<ll> a(n);
        map<ll, ll> freq;
        for (int i = 0; i < n; i++) cin >> a[i];

        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ll x = a[i] % p;
            ll x2 = x * x % p;
            ll x4 = x2 * x2 % p;
            ll val = (x4 - k * x) % p;
            if (val < 0) val += p;
            freq[val]++;
        }

        for (auto &[v, c] : freq) ans += c * (c - 1) / 2;
        cout << ans << endl;
    }
}