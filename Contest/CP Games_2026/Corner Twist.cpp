#include <iostream>
#include <vector>
#include <array>
#include <deque>
#include <list>
#include <forward_list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <functional>
#include <utility>
#include <tuple>
#include <string>
#include <cstring>
#include <sstream>
#include <cmath>
#include <complex>
#include <bitset>
#include <random>
#include <limits>
#include <climits>
#include <cfloat>
#include <cassert>
#include <exception>
#include <stdexcept>

using namespace std;

#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

using ll = long long;

const ll INF = (ll) 4e18;
const ll NEG = -INF;
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        int n,m;
        cin >> n >> m;
        vector<string> a(n),b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        vector<int> str1(m), str2(m), str_1(n), str_2(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                str1[j] += (a[i][j] - '0');
                str1[j] %= 3;
                str2[j] += (b[i][j] - '0');
                str2[j] %= 3;
                str_1[i] += (a[i][j] - '0');
                str_1[i] %= 3;
                str_2[i] += (b[i][j] - '0');
                str_2[i] %= 3;
            }
        }
        bool ok=true;
        for(int i=0;i<n;i++){
            if (!ok) break;
            ok = (str_1[i] == str_2[i]);
        }
        for(int i=0;i<m;i++){
            if (!ok) break;
            ok = (str1[i] == str2[i]);
        }
        if(ok) cout<<"YES\n";
        else cout<<"NO\n";
    }
}