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

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    for(int i = 0; i < k ; i++) cin >> a[i];
    vector<int> b(n);
    for(int i = 0; i < n; i++) cin >> b[i];
    int r = k;
    vector<int> ans;
    while(r > 0){
        for(int i = 0; i < n ; i++){
            if(b[i] == r){
                for(int j = 0; j < k+1-r ; j++) ans.push_back(i+1);
            }
        }
        r--;
    }
    int l = ans.size();
    cout << l << "\n";
    for(int i = 0; i < l ; i++) cout << ans[i] << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(k),b(n);
        for(int i = 0; i < k ; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];
        int r = k;
        vector<int> ans;
        while(r > 0){
            for(int i = 0; i < n ; i++){
                if(b[i] == r){
                    for(int j = 0; j < k+1-r ; j++) ans.push_back(i+1);
                }
            }
            r--;
        }
        int l = ans.size();
        cout << l << "\n";
        for(int i = 0; i < l ; i++) cout << ans[i] << " ";
        cout << endl;
    }
}