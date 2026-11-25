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
        int n, p = 0; cin >> n;
        vector<int> a(n), pre(n), suf(n);
        for (int &x : a) cin >> x;
        for (int i = 1; i < n; i++) {
            pre[i] = max(pre[i - 1], abs(a[i] - a[i - 1]));
            if (abs(a[i] - a[i - 1]) > abs(a[p + 1] - a[p])) p = i - 1;
        }
        for (int i = n - 2; i >= 0; i--) suf[i] = max(suf[i + 1], abs(a[i] - a[i + 1]));

        int ans = pre[n - 1], in = 0, gap;
        for (int l = p; l >= 0; l--) {
            if (l < p) in = max(in, abs(a[l] - a[l + 1]));
            gap = 2 * in;
            if (l > 0) gap = max({gap, pre[l - 1], abs(a[l - 1] - 2 * a[p])});
            if (p + 1 < n) gap = max({gap, suf[p + 1], abs(2 * a[l] - a[p + 1])});
            ans = min(ans, gap);
        }

        in = 0;
        for (int r = p + 1; r < n; r++) {
            if (r > p + 1) in = max(in, abs(a[r] - a[r - 1]));
            gap = 2 * in;
            if (p + 1 > 0) gap = max({gap, pre[p], abs(a[p] - 2 * a[r])});
            if (r + 1 < n) gap = max({gap, suf[r + 1], abs(2 * a[p + 1] - a[r + 1])});
            ans = min(ans, gap);
        }
        cout << ans << '\n';
    }
}