#include <iostream>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops,inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,lzcnt,bmi2,bmi,tune=native")

using ll = long long;

const ll INF = (ll) 4e18;
const ll NEG = -INF;
const int MOD = 1'000'000'007;
const int MAXN = 200005;
const int MAX_PRIME = 100005;

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
    for (int i = 3; i * i <= MAX_PRIME; i += 2)
        if (is_prime[i])
            for (int j = i * i; j <= MAX_PRIME; j += i * 2)
                is_prime[j] = false;

    primes.push_back(2);
    for (int i = 3; i <= MAX_PRIME; i += 2)
        if (is_prime[i]) primes.push_back(i);
}
int main() {
    std::cout << "Basic program 1 \n";
}