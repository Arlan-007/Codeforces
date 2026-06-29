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
        int n, m, k; cin >> n >> m >> k;
        vector<int> a(n),b(m);
        for (auto &c : a) cin >> c;
        for (auto &c : b) cin >> c;
        string s; cin >> s;
        vector<bool> dead(n , false);
        map<int, vector<int>> death;
        sort(b.begin(),b.end());
        for (int i = 0; i < n; i++) {
            if (b[0] < a[i]) {
                int left = a[i] - (*(lower_bound(b.begin(), b.end(), a[i]) - 1));
                death[-left].push_back(i);
            }
            if (b[m-1] > a[i]) {
                int right = *lower_bound(b.begin(), b.end(), a[i]) - a[i];
                death[right].push_back(i);
            }
        }
        int curr = 0;
        int alive = n;
        for (auto c : s){
            if(c == 'L') curr--;
            else curr++;
            for(auto &p : death[curr]){
                if(dead[p]) continue;
                dead[p] = true;
                alive--;
            }
            death[curr].clear();
            cout << alive << " ";
        }
        cout << endl;
        
    }
}
