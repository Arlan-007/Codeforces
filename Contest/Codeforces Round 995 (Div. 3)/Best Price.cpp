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
        int n, k; cin >> n >> k;
        vector<ll> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        set<ll> pr;
        pr.insert(0); pr.insert(b[n-1] + 1);
        for (int i = 0; i < n; i++) pr.insert(a[i]), pr.insert(b[i]);

        ll ans = 0;
        for (ll i : pr) {
            ll pos = n - (lower_bound(a.begin(), a.end(), i) - a.begin());
            ll neg = n - (lower_bound(b.begin(), b.end(), i) - b.begin()) - pos;
            if (neg > k) continue;
            ans = max(ans, i * (pos + neg));
        }
        cout << ans << endl;
    }
}