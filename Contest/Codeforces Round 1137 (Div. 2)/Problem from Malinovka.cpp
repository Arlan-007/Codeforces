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
const int MAX_N = 1000000;
vector<bool> sf(MAX_N + 1, true);

void build_sf() {
    for (int p = 2; p * p <= MAX_N; p++)
        for (int j = p * p; j <= MAX_N; j += p * p)
            sf[j] = false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    build_sf();
    while (t--) {
        ll n; cin >> n;
        ll k = sqrt(n);
        vector<ll> w(n + 1);
        ll ans = k * k * k;

        for (int i = 1; i <= n; i++) {
            if (!sf[i]) continue;
            w[i] = sqrt(n / i);
            if (i > 1) ans += 3 * k * w[i] * w[i];
        }

        vector<vector<ll>> ok(k + 1);
        for (int a = 1; a <= k; a++) {
            if (!sf[a]) continue;
            ll lim = n / a;
            ok[a].resize(lim / 64 + 1);
            for (int c = a + 1; c <= lim; c++) if (sf[c] && gcd(a, c) == 1) ok[a][c / 64] |= 1ULL << (c % 64);
        }

        for (int b = 2; b <= k; b++) {
            if (!sf[b]) continue;
            for (int a = 1; a < b; a++) {
                if (!sf[a] || gcd(a, b) != 1) continue;

                for (int j = (b + 1) / 64; j < ok[b].size(); j++) {
                    auto mask = ok[a][j] & ok[b][j];
                    while (mask) {
                        int c = 64 * j + __builtin_ctzll(mask);
                        ans += 6LL * w[a * b] * w[a * c] * w[b * c];
                        mask &= mask - 1;
                    }
                }
            }
        }
        cout << ans << '\n';
    }
}