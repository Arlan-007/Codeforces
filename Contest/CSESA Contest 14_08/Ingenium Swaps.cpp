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
        int n; cin >> n;
        vector<ll> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        vector<int> pos_a(2*n+2), pos_b(2*n+2);
        for (int i = 0; i < n; i++) pos_a[a[i]] = i;
        for (int i = 0; i < n; i++) pos_b[b[i]] = i;

        vector<int> suf(n+2, INT_MAX);
        for (int j = n; j >= 1; j--) suf[j] = min(pos_b[2*j], suf[j+1]);

        int ans = INT_MAX;
        for (int k = 1; k <= n; k++) {
            int cost = pos_a[2*k - 1] + suf[k];
            ans = min(ans, cost);
        }
        cout << ans << "\n";
    }
}