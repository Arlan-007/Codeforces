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

ll diff(vector<ll> a, vector<ll> b) {
    ll sum = 0;
    for (int i = 0; i < a.size(); i++) {
        sum += abs(a[i] - b[i]);
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<ll> a(n),b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        vector<pair<ll, ll>> pos(n),neg(n);
        for (int i = 0; i < n; i++) {
            pos[i].first = max(a[i], b[i]);
            neg[i].first = min(a[i], b[i]);
            pos[i].second = i;
            neg[i].second = i;
        }
        sort(pos.begin(),pos.end() , [](const auto& a,const auto& b) {return a.first < b.first;});
        sort(neg.begin(),neg.end() , [](const auto& a,const auto& b) {return a.first < b.first;});
        ll ans1 = diff(a,b);
        swap(b[pos[0].second],b[neg[n-1].second]);
        ll ans2 = diff(a,b);
        cout << max(ans1,ans2) << endl;
    }
}