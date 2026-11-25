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
        map<int,int> cnt;

        auto nxt = [](ll x) {
            ll s = 0;
            while (x) {
                s += (x % 10) * (x % 10);
                x /= 10;
            }
            return s;
        };

        while (n--) {
            ll x; cin >> x;
            for (int i = 0; i < 100; i++) x = nxt(x);
            cnt[x]++;
        }

        ll ans = 0;
        for (auto [x, c] : cnt) ans += 1LL * c * (c - 1) / 2;
        cout << ans << '\n';
    }
}