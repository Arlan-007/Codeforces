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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s1, s2;
        cin >> s1 >> s2;

        vector<int> dp(n+1, 1e9);
        dp[0] = 0;

        for(int i = 1; i <= n; i++){
            dp[i] = dp[i-1] + (s1[i-1] != s2[i-1] ? 1 : 0);
            if(i >= 2){
                int h = (s1[i-2] != s1[i-1] ? 1 : 0) + (s2[i-2] != s2[i-1] ? 1 : 0);
                dp[i] = min(dp[i], dp[i-2] + h);
            }
        }

        cout << dp[n] << "\n";
    }
    return 0;
}