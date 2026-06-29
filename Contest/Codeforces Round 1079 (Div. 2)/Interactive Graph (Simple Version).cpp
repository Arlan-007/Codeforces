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

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        set<pair<int,int>> edges;

        const int MAX_Q = 3840;
        int used = 0;

        for (int k = 1; used < MAX_Q; k++) {
            cout << "? " << k << endl;
            cout.flush();
            used++;

            int q;
            cin >> q;

            if (q == -1) return 0;
            if (q == 0) break;

            vector<int> path(q);
            for (int i = 0; i < q; i++) {
                cin >> path[i];
            }

            for (int i = 0; i + 1 < q; i++) {
                edges.insert({path[i], path[i + 1]});
            }
        }

        cout << "! " << edges.size() << endl;
        for (auto &e : edges) {
            cout << e.first << " " << e.second << endl;
        }
        cout.flush();
    }

    return 0;
}

