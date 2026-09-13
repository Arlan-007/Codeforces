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

    ll n, m, s; cin >> n >> m >> s;
    vector<pair<ll, ll>> a(m), b(n);
    vector<ll> c(n), ans(m, -1);
    for (int i = 0; i < m; i++) cin >> a[i].first, a[i].second = i;
    for (int i = 0; i < n; i++) cin >> b[i].first, b[i].second = i;
    for (int i = 0; i < n; i++) cin >> c[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    auto KANYE = [&](int t) {
        ans.assign(m, -1);
        ll cnt = 0, pos = 0, j = n - 1, tot = 0;
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;

        for (int i = m - 1; i >= 0; i--) {
            while (j >= 0 && b[j].first >= a[i].first) pq.push({c[b[j].second], b[j].second}), j--;
            if (cnt > 0) cnt--, ans[a[i].second] = pos;
            else {
                if (pq.empty()) return false;
                auto [cost, per] = pq.top(); pq.pop();
                tot += cost, pos = per, cnt = t - 1;
                ans[a[i].second] = pos;
            }
        }
        return tot <= s;
    };

    int lo = 1, hi = m, res = -1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (KANYE(mid)) res = mid, hi = mid - 1;
        else lo = mid + 1;
    }

    if (res == -1) cout << "NO\n";
    else {
        KANYE(res); cout << "YES\n";
        for (int x : ans) cout << x + 1 << " ";
        cout << "\n";
    }
}