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
#include <numeric>
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
        ll a,b,c,m;
        cin >> a >> b >> c >> m;
        ll A = m/a;
        ll B = m/b;
        ll C = m/c;
        ll AB = m/lcm(a,b);
        ll AC = m/lcm(a,c);
        ll BC = m/lcm(b,c);
        ll ABC = m/lcm(a,lcm(b,c));
        ll al = A - AB - AC + ABC;
        ll bl = B - AB - BC + ABC;
        ll cl = C - AC - BC + ABC;
        ll ab = AB - ABC;
        ll ac = AC - ABC;
        ll bc = BC - ABC;
        ll alice =6*al +3*(ab + ac) +2*ABC;
        ll bob =6*bl +3*(ab + bc) +2*ABC;
        ll carol =6*cl +3*(ac + bc) +2*ABC;
        cout << alice << " " << bob << " " <<carol << "\n";
    }
}