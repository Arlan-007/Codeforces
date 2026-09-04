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
const int MAX_PRIME = 100005;
const int MAXN = 10'000'007;

vector<int> primes, sum(MAXN, 0), ans(MAXN, -1);
bitset<MAX_PRIME + 1> is_prime;

void build_sieve() {
    is_prime.set();
    is_prime[0] = false; is_prime[1] = false;

    for (int i = 3; i * i <= MAX_PRIME; i += 2)
        if (is_prime[i])
            for (int j = i * i; j <= MAX_PRIME; j += i * 2)
                is_prime[j] = false;

    primes.push_back(2);
    for (int i = 3; i <= MAX_PRIME; i += 2)
        if (is_prime[i]) primes.push_back(i);

    for (int i = 1; i < MAXN; i++)
        for (int j = i; j < MAXN; j += i)
            sum[j] += i;;

    for (int i = MAXN - 1; i >= 1; i--)
        if (sum[i] < MAXN) ans[sum[i]] = i;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    build_sieve();
    while (t--) {
        ll c; cin >> c;
        cout << ans[c] << "\n";
    }
}