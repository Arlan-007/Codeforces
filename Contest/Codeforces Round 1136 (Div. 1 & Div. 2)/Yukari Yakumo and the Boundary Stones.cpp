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
        int x, y, m; cin >> x >> y >> m;
        string s; cin >> s;

        int ans = x + y;
        vector<vector<int>> dp(101, vector<int>(101, 0)); dp[x][y] = 1;
        for (int i = 0; i < m; i++) {
            vector<vector<int>> ndp(101, vector<int>(101, 0));
            int lim = x + y + i;
            for (int a = 0; a <= lim; a++) {
                for (int b = 0; a + b <= lim; b++) {
                    if (!dp[a][b]) continue;
                    if (s[i] == '+') {
                        if (a > 0) ndp[a - 1][b + 1] = 1;
                        if (b > 0) ndp[a][b + 1] = 1, ans = max(ans, a + b + 1);
                    } else {
                        if (a > 0) ndp[a - 1][b] = 1;
                        if (b > 0) ndp[a + 1][b - 1] = 1;
                    }
                }
            }
            dp = ndp;
        }
        cout << ans << '\n';
    }
}