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

    int n; cin >> n;
    vector<int> x(n);
    for (int &v : x) cin >> v;

    for (int i = 0; i < n; i++) {
        int l = x[i] - x[0], r = x[n - 1] - x[i], ans = 1e9;
        if (i > 0) ans = min(ans, max(l, r + x[i] - x[i - 1]));
        if (i + 1 < n) ans = min(ans, max(l + x[i + 1] - x[i], r));
        cout << (n == 1 ? 0 : ans / 2) << '\n';
    }
}