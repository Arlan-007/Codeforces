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
        vector<pair<string, string>> song(n);
        for (int i = 0; i < n; i++) cin >> song[i].first >> song[i].second;

        vector<vector<bool>> adj(n, vector<bool>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && (song[i].first == song[j].first || song[i].second == song[j].second)) {
                    adj[i][j] = true;
                }
            }
        }

        vector<vector<bool>> dp(1 << n, vector<bool>(n));
        for (int i = 0; i < n; i++) dp[1 << i][i] = true;

        for (int s = 0; s < (1 << n); s++) {
            for (int l = 0; l < n; l++) {
                if (!dp[s][l]) continue;
                for (int nxt = 0; nxt < n; nxt++) {
                    if ((s & (1 << nxt)) || !adj[l][nxt]) continue;
                    dp[s | (1 << nxt)][nxt] = true;
                }
            }
        }

        int ans = n;
        for (int mask = 0; mask < (1 << n); mask++) {
            for (int i = 0; i < n; i++) {
                if (dp[mask][i]) {
                    ans = min(ans, n - __builtin_popcount(mask));
                    break;
                }
            }
        }
        cout << ans << "\n";
    }
}