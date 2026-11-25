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
const ll INF = (ll) 4e18;
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i) cin >> a[i];
        vector<vector<int>> positions(n + 1);
        for (int i = 1; i <= n; ++i) {
            if (a[i] >= 1 && a[i] <= n) positions[a[i]].push_back(i);
        }
        ll answer = 0;
        for (int x = 1; x <= n; ++x) {
            int maxY = n / x;
            for (int y = 1; y <= maxY; ++y) {
                if (positions[y].empty()) continue;
                int gap = x * y; // j = i + gap
                if (positions[x].size() <= positions[y].size()) {
                    for (int iIdx : positions[x]) {
                        int j = iIdx + gap;
                        if (j <= n && a[j] == y) ++answer;
                    }
                } else {
                    for (int jIdx : positions[y]) {
                        int i = jIdx - gap;
                        if (i >= 1 && a[i] == x) ++answer;
                    }
                }
            }
        }
        cout << answer << '\n';
    }
    return 0;
}
