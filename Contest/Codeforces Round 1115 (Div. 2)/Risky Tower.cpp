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
        ll n, m; cin >> n >> m;
        vector<ll> v(n);
        for (auto &x : v) cin >> x;
        
        vector<vector<ll>> a(n, vector<ll>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
        for (int i = 0; i < n; i++) sort(a[i].rbegin(), a[i].rend());

        int ans = m;
        multiset<ll, greater<ll>> s;
        for (int k = n - 1; k >= 0; k--) {
            for (auto x : a[k]) s.insert(x);
            ll sum = 0;
            int c = 0;
            for (ll x : s) {
                c++;
                sum += x;
                if (sum >= v[k]) {
                    ans = min(ans, c);
                    break;
                }
                if (c > ans) break;
            }
        }

        cout << ans << endl;
    }
}