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
        int n, d; cin >> n >> d;
        vector<int> l(2 * n), r(2 * n), dep(2 * n), ans(n + 1);
        vector<set<int>> win(2 * n);
        for (int i = n + 1; i < 2 * n; i++) cin >> l[i] >> r[i];
        for (int i = 2 * n - 1; i > n; i--) dep[l[i]] = dep[r[i]] = dep[i] + 1;
        for (int i = 1; i <= n; i++) win[i].insert(i), ans[i] = dep[i];

        for (int i = n + 1; i < 2 * n; i++) {
            int u = l[i], v = r[i];
            if (*win[u].rbegin() < *win[v].rbegin()) swap(u, v);

            int lim = *win[v].rbegin() + d;
            while (!win[u].empty() && *win[u].rbegin() >= lim) {
                auto it = prev(win[u].end());
                ans[*it] = dep[*it] - dep[i];
                win[u].erase(it);
            }

            if (win[u].size() < win[v].size()) swap(u, v);
            win[i].swap(win[u]), win[i].merge(win[v]);
        }
        for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
        cout << endl;
    }
}