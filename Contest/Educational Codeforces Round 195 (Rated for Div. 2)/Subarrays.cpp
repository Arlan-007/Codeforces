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
        int n, k; cin >> n >> k;
        vector<int> a(n), pref(n + 1);
        for (int i = 0; i < n; i++) cin >> a[i], pref[i + 1] = (pref[i] + a[i]) % k;

        ll ans = 0;
        vector<ll> cnt(k);
        for (int r = k + 1; r <= n; r++) cnt[pref[r - k - 1]]++, ans += cnt[pref[r]];
        cout << ans << '\n';
    }
}