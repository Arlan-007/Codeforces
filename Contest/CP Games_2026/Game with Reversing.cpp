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

    int T = 1;
    cin >> T;
    while (T--) {
        int n; cin >> n;
        string s; cin >> s;
        string t; cin >> t;
        int cnt = 0;
        for (int i = 0; i < n; i++) if (s[i] != t[i]) cnt++;
        string rev = t;
        reverse(rev.begin(), rev.end());
        int cntr = 0;
        for (int i = 0; i < n; i++) if (s[i] != rev[i]) cntr++;
        ll ans1 = 2LL * cnt - (cnt % 2);
        ll ans2;
        if (cntr == 0) ans2 = 2;
        else ans2 = 2LL * cntr - ((cntr % 2) ? 0 : 1);
        cout << min(ans1, ans2) << '\n';
    }
}