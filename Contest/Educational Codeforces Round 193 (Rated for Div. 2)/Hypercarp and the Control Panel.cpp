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
        vector<int> a(n);
        vector<pair<int, int>> b;
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++)
            if (b.empty() || b.back().first != a[i]) b.push_back({a[i], 1});
            else b.back().second++;

        int m = b.size(), ans = m;
        for (int i = 0; i < m - 1; i++)
            if (b[i].second > 1 && b[i + 1].second > 1) {
                ans = m + 2;
                break;
            }

        if (ans == m)
            for (int i = 0; i < m; i++)
                if (b[i].second > 1)
                    if ((i < m - 1 && (i + 2 >= m || b[i + 2].first != b[i].first)) || (i > 0 && (i - 2 < 0 || b[i - 2].first != b[i].first))) {
                        ans = m + 1;
                        break;
                    }

        cout << ans << '\n';
    }
}