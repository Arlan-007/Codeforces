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
    cin >> T;
    while (T--) {
        ll t, h, u; cin >> t >> h >> u;
        ll ans = 0;
        ll x = min(t, u);
        ans += 4 * x;
        t -= x; u -= x;
        if(t == 0 && u == 0) ans += h*3;
        else if(t == 0 && u != 0) ans += (h+u)*3;
        else{
            ans += h*3;
            if(t <= 2*h) ans += t*2;
            else{
                ans += (h*2)*2;
                t -= 2*h;
                if(t == 1) ans += 3;
                else ans += 3+ (t-1)*2;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}