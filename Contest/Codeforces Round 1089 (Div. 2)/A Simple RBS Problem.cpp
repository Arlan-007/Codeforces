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
        int n; cin >> n;
        string s,t1;
        cin >> s >> t1;
        vector<bool> v(n,true);
        for (int i = 0; i < n; i++) {
            if (s[i] == t1[i]) continue;
            v[i] = false;
        }
        int patch = 0;
        int start1 = -1 , start2 = -1 , end1 = -1 , end2 = -1;
        for (int i = 0; i < n; i++) {
            if (v[i] == false) {
                if ((i == 0 || v[i-1] == true) && start1 == -1) start1 = i;
                if (i == 0 || v[i-1] == true) start2 = i;
                if ((i == n-1 || v[i+1] == true) && end1 == -1) end1 = i;
                if (i == n-1 || v[i+1] == true) end2 = i;

                if (i == n-1 || v[i+1] == true) patch++;
            }
        }
        if (patch == 0) {
            cout << "YES\n";
            continue;
        }
        if (patch > 2) cout << "NO\n";
        else {
            string sub1 = s.substr(start1, end1 - start1 + 1);
            string sub2 = s.substr(start2, end2 - start2 + 1);

            string temp = s;
            temp.replace(start1, end1 - start1 + 1, sub2);
            temp.replace(start2, end2 - start2 + 1, sub1);

            if (temp == t1) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}