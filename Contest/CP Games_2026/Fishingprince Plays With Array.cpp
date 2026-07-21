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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        ll n, m ,k; cin >> n >> m;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        cin >> k;
        vector<ll> b(k);
        for (int i = 0; i < k; i++) cin >> b[i];

        vector<pair<ll,ll>> va , vb;
        for (ll x : a) {
            ll cnt = 1;
            while (x % m == 0) {
                x /= m;
                cnt *= m;
            }
            if (!va.empty() && va.back().first == x) va.back().second += cnt;
            else va.push_back({x, cnt});
        }
        for (ll x : b) {
            ll cnt = 1;
            while (x % m == 0) {
                x /= m;
                cnt *= m;
            }
            if (!vb.empty() && vb.back().first == x) vb.back().second += cnt;
            else vb.push_back({x, cnt});
        }

        if (va == vb) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
}