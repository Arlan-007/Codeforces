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
const int inf = 1e9;
const ll NEG = -INF;
const int MOD = 1'000'000'007;

const int N = 8192;
const int M = 5001;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin >> n;
    vector<int> a(n), v[M];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        v[a[i]].push_back(i);
    }

    vector<int> dp(N, inf);
    dp[0] = 0;
    for (int i = 1; i < M; i++) {
        if (v[i].size() == 0) continue;
        for (int j = 1; j < N; j++) {
            if (dp[j ^ i] != inf) {
                int x = dp[(j ^ i)];
                int c = lower_bound(v[i].begin(), v[i].end(), x) - v[i].begin();
                if (c < v[i].size()) dp[j] = min(dp[j],v[i][c]);
            }
        }
    }

    int ans = 0;
    for (int i : dp) ans += (i != inf);

    cout << ans << "\n";
    for (int i = 0; i < N; i++) if (dp[i] != inf) cout << i << " ";
    cout << "\n";
}