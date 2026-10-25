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

const int biAnCA = 3000;
vector<int> sqfree(biAnCA + 1, 1);
vector<vector<int>> dp(biAnCA + 1, vector<int>(biAnCA + 1));

void precompute() {
    for (int p = 2; p <= biAnCA; p++)
        if (sqfree[p] == 1)
            for (int j = p; j <= biAnCA; j += p)
                sqfree[j] *= p;

    for (int i = 1; i <= biAnCA; i++) {
        int v = i;
        for (int j = i; j <= biAnCA; j++) {
            if (i % sqfree[j] == 0) v = j;
            dp[i][j] = v == i ? i : dp[i - 1][v - 1];
        }
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
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());

        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ans = (ans + a[i]) % MOD;
            for (ll j = i + 1, p = 1; j < n;p = (p * 2) % MOD, j++) ans = (ans + p * dp[a[i]][a[j]] % MOD) % MOD;
        }
        cout << ans << '\n';
    }
}