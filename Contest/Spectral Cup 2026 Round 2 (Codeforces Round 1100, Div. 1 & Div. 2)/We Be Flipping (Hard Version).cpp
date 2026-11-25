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
#pragma GCC optimize("unroll-loans")

using ll = long long;

const ll INF = (ll) 4e18;
const ll NEG = -INF;
const int MOD = 1'000'000'007;

ll binpow(ll a, ll b, ll mod = MOD) {
    ll res = 1;
    while (b) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

ll modinv(ll a, ll mod = MOD) {
    return binpow(a, mod - 2, mod);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n + 1);
        for (int i = 1; i <= n; ++i) cin >> a[i];
        vector<ll> pref(n + 1, 0), suff(n + 2, 0);
        for (int i = 1; i <= n; ++i) pref[i] = pref[i - 1] + llabs(a[i]);
        for (int i = n; i >= 1; --i) suff[i] = suff[i + 1] + a[i];
        ll best = suff[1];
        int temp = 0;
        for (int r = 1; r <= n; ++r) {
            if (a[r] > 0) {
                ll cur = pref[r - 1] - a[r] + suff[r + 1];
                if (cur > best) {
                    best = cur;
                    temp = r;
                }
            }
        }
        vector<int> ans;
        if (temp != 0) {
            int flip = 0;
            for (int i = temp - 1; i >= 1; --i) {
                ll cur = (flip == 0 ? a[i] : -a[i]);
                if (cur > 0) {
                    ans.push_back(i);
                    flip ^= 1;
                }
            }
            ans.push_back(temp);
        }
        cout << ans.size() << '\n';
        for (int i = 0; i < ans.size(); ++i) {
            cout << ans[i] << " ";
        }
        cout << '\n';
    }

    return 0;
}