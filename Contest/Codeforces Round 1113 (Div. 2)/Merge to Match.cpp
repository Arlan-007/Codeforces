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
        int n, m;
        cin >> n >> m;
        vector<ll> a(n), b(m);
        for (auto &x : a) cin >> x;
        for (auto &x : b) cin >> x;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        bool ok = (n >= 2 * m);
        for (int j = 0; j < m && ok; j++) {
            ll less = lower_bound(a.begin(), a.end(), b[j]) - a.begin();
            ll greater = n - less;
            if (less < j + 1 || greater < m - j) ok = false;
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}