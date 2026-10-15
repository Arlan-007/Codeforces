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
        ll n, k, mx = 0; cin >> n >> k;
        vector<ll> a(n);
        for (auto& x : a) cin >> x, mx = max(mx, x);
        vector<ll> freq(mx + 1);
        for (auto x : a) freq[x]++;

        auto chk = [&](ll mid) {
            vector<ll> cnt = freq;
            ll alive = n, split = 0, mxx = mx, lim = k + n + 2 * mid - 1;

            while (alive > 0) {
                while (cnt[mxx] == 0) mxx--;
                if (mxx > lim) {
                    if (split == mid) return false;
                    cnt[mxx]--, cnt[(mxx + 1) / 2] += 2, alive++, split++;
                } else cnt[mxx]--, alive--, lim--;
            }
            return true;
        };

        ll lo = 0, hi = mx > k ? mx - k : 0;
        while (lo < hi) {
            ll mid = lo + (hi - lo) / 2;
            if (chk(mid)) hi = mid;
            else lo = mid + 1;
        }
        cout << n + 2 * lo << '\n';
    }
}