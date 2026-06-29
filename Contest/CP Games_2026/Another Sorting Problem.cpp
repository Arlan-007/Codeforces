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

bool Comp(pair<string, int>& A, pair<string, int>& B) {
    string& a = A.first;
    string& b = B.first;
    int n = min(a.length(), b.length());

    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
            if (i % 2 == 0) {
                return a[i] < b[i];
            }
            return a[i] > b[i];
        }
    }
    return a.length() < b.length();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        ll n, m; cin >> n >> m;
        vector<pair<string,int>> a(n);
        string s;
        for (int i = 0; i < n; i++) {cin >> s; a[i].first = s; a[i].second = i;}
        sort(a.begin(), a.end(), Comp);
        for (int i = 0; i < n; i++) cout << a[i].second+1 << " ";
    }

    return 0;
}