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
        int n, h; cin >> n;
        map<int, int> cnt;
        for (int i = 0; i < n; ++i) cin >> h, cnt[h]++;

        vector<int> ans(n);
        int l = 0, r = n - 1, k = 0;
        for (auto [h, f] : cnt) {
            k += min(f, 2), ans[l++] = h;
            while (--f) ans[r--] = h;
        }

        cout << k << '\n';
        for (int h : ans) cout << h << ' ';
        cout << '\n';
    }
}