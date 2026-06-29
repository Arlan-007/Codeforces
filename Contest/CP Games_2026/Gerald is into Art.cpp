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

    int W, H, w1, h1, w2, h2;
    cin >> W >> H >> w1 >> h1 >> w2 >> h2;
    bool pos = false;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            if ((max(w1, w2) <= W && h1 + h2 <= H) || (max(w1, w2) <= H && h1 + h2 <= W)) {
                pos = true;
            }
            if ((w1 + w2 <= W && max(h1, h2) <= H) || (w1 + w2 <= H && max(h1, h2) <= W)) {
                pos = true;
            }
            swap(w2, h2);
        }
    }
    if (pos) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}