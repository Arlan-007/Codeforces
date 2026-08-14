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

ll cur, k, cnt[1 << 20];

struct str {
    int l,r,i;
};

void add(int x, int y) {
    if (y == 1)cur += cnt[x^k];
    cnt[x] += y;
    if (y == -1) cur -= cnt[x^k];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        ll n, m; cin >> n >> m >> k;
        vector<ll> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            a[i] ^= a[i-1];
        }

        int B = max(1, (int)sqrt(n));
        vector<str> q(m);
        for (int i = 0; i < m; i++) {
            cin >> q[i].l >> q[i].r;
            q[i].i = i;
        }

        sort(q.begin(), q.end(), [&](const str& x, const str& y) {
            int bx = x.l / B, by = y.l / B;
            if (bx != by) return bx < by;
            return bx & 1 ? x.r < y.r : x.r > y.r;
        });

        vector<ll> ans(m);
        cnt[0] = 1;
        int l = 1, r = 0;
        for (auto& i : q) {
            while (r < i.r) add(a[++r],1);
            while (l > i.l) add(a[--l - 1],1);
            while (l < i.l) add(a[l++ - 1],-1);
            while (r > i.r) add(a[r--],-1);
            ans[i.i] = cur;
        }

        for (int i = 0; i < m; i++) cout << ans[i] << "\n";
    }
}