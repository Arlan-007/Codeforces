#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <limits>
using namespace std;

#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")

using ll = long long;
const ll INF = (ll)4e18;
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

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool in(int x, int y, int n, int m) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

int ask(int i, int j) {
    cout << "? " << i << j << endl;
    int x;
    cin >> x;
    if (x == -1) exit(0);
    return x;
}

bool try_pair(int i, int j) {
    if (ask(i, j) == 1) {
        cout << "! " << i << endl;
        return true;
    }
    return false;
}

void solve() {
    int n;
    cin >> n;

    if (try_pair(1, 2)) return;
    if (try_pair(1, 3)) return;
    if (try_pair(2, 3)) return;

    for (int i = 4; i <= 2 * n - 1; i += 2) {
        if (try_pair(i, i + 1)) return;
    }

    cout << "! " << 2 * n << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
