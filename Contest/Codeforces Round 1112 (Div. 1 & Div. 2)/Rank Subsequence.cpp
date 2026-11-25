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
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<array<int, 4>> a(n);
        for (auto &[l, r, u, v] : a) cin >> l >> r >> u >> v;

        int ans = 0;
        for (int m = n; m >= 1; m--) {
            int j = 1;
            for (auto [l, r, u, v] : a) {
                int right = m - j + 1;
                if ((j < l || j > r) && (right < u || right > v)) j++;
                if (j > m) break;
            }
            if (j > m) {
                ans = m;
                break;
            }
        }
        cout << ans << '\n';
    }
}
