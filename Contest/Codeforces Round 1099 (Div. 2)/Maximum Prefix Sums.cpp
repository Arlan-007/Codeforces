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
        int n; cin >> n;
        string s; cin >> s;
        vector<ll> a(n) , c(n) , pref(n,0) , pref_max(n,0);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> c[i];
        pref[0] = a[0]; pref_max[0] = a[0];
        for (int i = 1; i < n; i++) {pref[i] = pref[i-1]+a[i];pref_max[i] = max(pref[i], pref_max[i-1]);}
        bool flag = false;
        for (int i = 0; i < n; i++) {if (pref_max[i] > c[i]) {flag = true; break;}}
        if (!flag) {
            cout << "YES\n";
            for (int i = 0; i < n; i++) cout << a[i] << " ";
            cout << endl;
        }
        else cout << "NO\n";
    }

    return 0;
}