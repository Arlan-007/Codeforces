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
        int n, m; cin >> n >> m;
        vector<ll> a(n+1,0), b(m+1,0);
        ll sum_a = 0, sum_b = 0;
        for (int i = 0; i < n; i++) {cin >> a[i];}
        for (int i = 0; i < m; i++) {cin >> b[i];}
        for (int i = 0; i < n; i++) sum_a += a[i] - a[i+1] + 1;
        for (int i = 0; i < m; i++) sum_b += b[i] - b[i+1] + 1;

        if (sum_a >= sum_b) cout << 1 << "\n";
        else cout << 2 << "\n";


    }
}