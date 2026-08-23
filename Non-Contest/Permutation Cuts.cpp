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
const int MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<ll> a(n,0); bool brk =  false;
        for (int i = 0; i < n-1; i++) cin >> a[i];

        for (auto& x : a) if (x == n) {
            cout << 0 << '\n';
            brk = true; break;
        }

        if (!brk) {
            vector<ll> pref(n), suf(n + 2);
            pref[0] = 1; suf[n] = 1;
            for (int i = 1; i < n; ++i) pref[i] = pref[i - 1] && a[i] >= a[i - 1];
            for (int i = n - 1; i >= 1; --i) suf[i] = suf[i + 1] && a[i] >= a[i + 1];

            ll ans = 0;
            for (int c = 0; c < n; ++c) {
                if (!pref[c + 1] || !suf[c + 1]) continue;
                if (c > 0 && c < n - 1 && a[c] == a[c + 1]) continue;

                vector<int> l, r;
                for (int i = 1; i <= c; ++i) l.push_back(a[i]);
                for (int i = c + 1; i < n; ++i) r.push_back(a[i]);
                reverse(r.begin(), r.end());

                vector<ll> vis(n+1,0);
                int x = 0, y = 0, used = 0;
                ll ways = 1;

                while (x < l.size() || y < r.size()) {
                    int w;
                    if (x == l.size()) w = r[y++];
                    else if (y == r.size()) w = l[x++];
                    else if (l[x] < r[y]) w = l[x++];
                    else if (l[x] > r[y]) w = r[y++];
                    else {
                        cout << 0 << '\n';
                        brk = true; break;
                    }

                    if (!vis[w]) vis[w] = 1;
                    else if (w < used) ways = 0;
                    else ways = ways * (w - used) % MOD;
                    used++;
                }
                ans += ways;
            }
            if (!brk) cout << ans % MOD << '\n';
        }
    }
}