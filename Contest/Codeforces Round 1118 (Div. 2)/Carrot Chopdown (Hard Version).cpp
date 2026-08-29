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
        ll n, m, tot = 0; cin >> n >> m;
        vector<ll> cnt(m + 2, 0), suf(m + 3, 0), flr(m + 2, 0);;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            cnt[x]++; tot += x;
        }

        for (int i = m; i >= 1; i--) suf[i] = suf[i + 1] + cnt[i];

        for (int i = 1; i <=m; i++)
            for (int j = i; j <= m; j += i) flr[i] += suf[j];

        for (ll k = 1; k <= m; k++) {
            if (k >= 31 || 1LL << k > m) {
                cout << tot << " ";
                continue;
            }
            ll C = 1 << k, ans = 0;
            for (int i = 1; i <= m; i++) {
                ll cur = flr[i] + cnt[min(C * i, m + 1)];
                for (ll j = C * i; j <= m; j += i) cur -= suf[j];
                ans = max(ans,cur);
            }
            cout << ans << " ";
        }
        cout << "\n";
    }
}