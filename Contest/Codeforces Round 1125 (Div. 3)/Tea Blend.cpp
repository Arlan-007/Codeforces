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
#include <chrono>

using namespace std;

#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

using ll = unsigned long long;

const ll INF = (ll) 4e18;
const ll NEG = -INF;
const int MOD = 1'000'000'007;
const int M = 1000000;

ll mix(ll x) {
    x += 0x9e3779b97f4a7c15ULL;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
    x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
    return x ^ (x >> 31);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<ll> spf(M + 1), hash(M + 1), h(M + 1);
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    for (int i = 2; i <= M; i++) {
        if (spf[i] == 0) {
            spf[i] = i, hash[i] = mix(rng()) & LLONG_MAX;
            if (1LL * i * i <= M) for (int j = i * i; j <= M; j += i) if (spf[j] == 0) spf[j] = i;
        }
        h[i] = h[i / spf[i]] ^ hash[spf[i]];
    }

    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        unordered_map<ll, int> count;
        for (int &x : a) cin >> x, count[h[x]]++;

        ll ans = 0, pref = 0;
        for (int x : a) pref ^= h[x], ans += count[pref];
        cout << ans << '\n';
    }
}