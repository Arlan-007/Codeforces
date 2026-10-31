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

    int h, w, n, q; cin >> h >> w >> n >> q;
    vector<int> r(n), c(n);
    for (int i = 0; i < n; i++) cin >> r[i] >> c[i];
    sort(r.begin(), r.end()); sort(c.begin(), c.end());

    while (q--) {
        int t, u, d; cin >> t >> u >> d;
        auto &a = t == 1 ? r : c;
        cout << upper_bound(a.begin(), a.end(), d) - lower_bound(a.begin(), a.end(), u) << '\n';
    }
}