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

    int q; cin >> q;
    string s, t; cin >> s >> t;
    int n = s.size(), m = t.size();

    vector<int> pos;
    for (int i = 0; i + m <= n; i++) {
        bool ok = true;
        for (int j = 0; j < m; j++) if (s[i + j] != t[j]) {ok = false; break;}
        if (ok) pos.push_back(i + 1);
    }

    while (q--) {
        int l, r; cin >> l >> r;
        auto it = lower_bound(pos.begin(), pos.end(), l);
        if (it != pos.end() && *it <= r - m + 1) cout << "Yes" << "\n";
        else cout << "No" << "\n";
    }
}