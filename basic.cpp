#include <iostream>

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")

using ll = long long;

const ll INF = (ll) 4e18;
const ll NEG = -INF;
const int MOD = 1'000'000'007;
const int MAXN = 200005;
const int MAX_PRIME = 100005;

ll fact[MAXN], invFact[MAXN];
vector<int> primes;
bool is_prime[MAX_PRIME + 1];

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
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p <= MAX_PRIME; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= MAX_PRIME; i += p)
                is_prime[i] = false;
        }
    }
    for (int p = 2; p <= MAX_PRIME; p++) {
        if (is_prime[p]) primes.push_back(p);
    }
}
int main() {
    std::cout << "Basic program 1 \n";
}