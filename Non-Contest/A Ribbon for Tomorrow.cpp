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
const int MAXN = 1000005;

ll fact[MAXN], invFact[MAXN];

ll modpow(ll a, ll b) {
    ll res = 1;
    a = (a % MOD + MOD) % MOD;
    while (b) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

ll modInverse(ll n) {
    return modpow(n, MOD - 2);
}

void precompute() {
    fact[0] = 1;
    invFact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    invFact[MAXN - 1] = modInverse(fact[MAXN - 1]);
    for (int i = MAXN - 2; i >= 1; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}

ll nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    precompute();

    int t = 1;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;

        ll cnt1 = 0, cnt0 = 0;
        ll t0 = 0, t1 = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') cnt1++;
            else cnt0++;

            if (i == 0 || s[i] != s[i-1]) {
                if (s[i] == '0') t0++;
                else t1++;
            }
        }

        ll ans0 = (t0 == 0) ? 1 : nCr(cnt0 - 1, t0 - 1) % MOD;
        ll ans1 = (t1 == 0) ? 1 : nCr(cnt1 - 1, t1 - 1) % MOD;
        cout << ans0 * ans1 % MOD << "\n";
    }
}