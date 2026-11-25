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
const int MAXN = 200005;
const int MAX_PRIME = 1000005;

ll fact[MAXN], invFact[MAXN];
vector<int> primes;
vector<bool> is_prime(MAX_PRIME + 1, true);

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

void build_sieve() {
    is_prime[0] = false; is_prime[1] = false;
    for (int i = 2; i * i <= MAX_PRIME; i++)
        if (is_prime[i])
            for (int j = i * i; j <= MAX_PRIME; j += i * 2)
                is_prime[j] = false;

    primes.push_back(2);
    for (int i = 3; i <= MAX_PRIME; i += 2)
        if (is_prime[i]) primes.push_back(i);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    precompute();
    build_sieve();

    int n, x; cin >> n;
    vector<ll> cnt(MAX_PRIME + 1), dp(n + 1); dp[0] = 1;
    for (int i = 0; i < 2 * n; i++) cin >> x, cnt[x]++;

    ll ans = fact[n];
    for (int i = 1; i <= MAX_PRIME; i++) {
        if (cnt[i] == 0) continue;

        ans = ans * invFact[cnt[i]] % MOD;
        if (is_prime[i]) for (int j = n; j >= 1; j--) dp[j] = (dp[j] + dp[j - 1] * cnt[i]) % MOD;
    }
    cout << ans * dp[n] % MOD << '\n';
}