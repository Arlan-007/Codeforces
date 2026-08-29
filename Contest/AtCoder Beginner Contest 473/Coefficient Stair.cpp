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

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")

using ll = long long;

const ll INF = (ll) 4e18;
const ll NEG = -INF;
const int MOD = 1'000'000'007;

int n, k;
vector<int> a;
vector<vector<bool>> can;
void solve(int pos, int rem) {
    if (pos > n) {
        if (rem == 0) {
            for (int i = 1; i <= n; i++) cout << a[i] << " ";
            cout << "\n";
        }
        return;
    }

    for (int val = 0; val * pos <= rem; val++) {
        int r = rem - val * pos;
        if (pos < n && !can[pos + 1][r]) continue;
        a[pos] = val;
        solve(pos + 1, r);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        cin >> n >> k;
        a.resize(n + 1);

        can.assign(n + 2, vector<bool>(k + 1, false));
        can[n + 1][0] = true;

        for (int i = n; i >= 1; i--) {
            for (int r = 0; r <= k; r++) {
                can[i][r] = can[i + 1][r];
                if (r >= i && can[i][r - i]) can[i][r] = true;
            }
        }
        solve(1, k);
    }
}