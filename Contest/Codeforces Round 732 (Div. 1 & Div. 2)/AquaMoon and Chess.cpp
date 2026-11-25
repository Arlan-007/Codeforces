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
const int MOD = 998'244'353;
const int MAXN = 200005;

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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    precompute();
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;

        int cnt1 = 0, cnt0 = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') cnt0++;
            else if (i + 1 < n && s[i + 1] == '1') cnt1++ , i++;
        }

        ll ans = fact[cnt1 + cnt0] * invFact[cnt0] % MOD * invFact[cnt1] % MOD;
        cout << ans << endl;
    }
}