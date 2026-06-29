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

    int n;
    cin >> n;

    vector<ll> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    vector<ll> cost(5);
    for (int i = 0; i < 5; i++) {
        cin >> cost[i];
    }

    vector<ll> ans(5);
    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += p[i];
        for (int j = 4; j >= 0; j--) {
            ans[j] += cnt / cost[j];
            cnt %= cost[j];
        }
    }
    for (int i = 0; i < 5; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n" << cnt << "\n";
}