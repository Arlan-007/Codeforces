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
        vector<int> l(n + 1), r(n + 1);
        vector<vector<int>> q(n + 1);
        for (int i = 2; i <= n; i++) cin >> l[i] >> r[i], q[r[i]].push_back(i);

        int B = sqrt(n);
        vector<int> a(n + 1, 1), cnt(n / B + 1), par(n + 2);
        iota(par.begin(), par.end(), 0);
        for (int i = 1; i <= n; i++) cnt[i / B]++;

        auto find = [&](this auto&& self, int x) -> int {
            return par[x] == x ? x : par[x] = self(par[x]);
        };


        auto query = [&](int lo, int hi) {
            int res = 0;
            while (lo <= hi && lo % B != 0) res += a[lo++];
            while (lo + B - 1 <= hi) res += cnt[lo / B], lo += B;
            while (lo <= hi) res += a[lo++];
            return res;
        };

        ll ans = 0, x;
        for (int k = 1; k <= n; k++) {
            if (k > 1) {
                x = find(l[k]);
                while (x <= r[k]) a[x] = 0, cnt[x / B]--, par[x] = find(x + 1), x = par[x];
            }
            for (int i : q[k]) ans += query(l[i], r[i]);
        }
        cout << ans << '\n';
    }
}