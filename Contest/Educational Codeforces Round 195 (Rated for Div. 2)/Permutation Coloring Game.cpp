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

const int INF = 1e9;
const ll NEG = -INF;
const int MOD = 1'000'000'007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> a(n), vis(n + 1), len;
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;
            int cur = i, cnt = 0;
            while (!vis[cur]) vis[cur] = 1, cnt++, cur = a[cur] - 1;
            len.push_back(cnt);
        }
        sort(len.rbegin(),len.rend());

        string ans;
        if (k == 1) {
            if (len[0] > 2) ans = "Bob";
            else if (len[0] == 1 || n % 2 == 1) ans = "Alice";
            else ans = "Bob";
        } else if (len[0] > k + 1) {
            ans = "Bob";
        } else if (len[0] == k + 1) {
            if (len.size() > 1 && len[1] == k + 1) ans = "Bob";
            else {
                int non_singleton = 0, singleton = 0;
                for (int i = 1; i < len.size(); i++) {
                    if (len[i] > 1) non_singleton += len[i];
                    else singleton++;
                }

                int alice = non_singleton + singleton % (k + 1);
                if (alice == 0 || alice > k) ans = "Bob";
                else ans = "Alice";
            }
        } else {
            int m = min((int)len.size(), 2 * k);
            vector<vector<int>> dp(k + 1, vector<int>(k + 1, INF));
            dp[0][0] = 0;

            for (int i = 0; i < m; i++) {
                vector<vector<int>> ndp(k + 1, vector<int>(k + 1, INF));
                int s = len[i];

                for (int j = 0; j <= k; j++) {
                    for (int c = 0; c <= k; c++) {
                        int cur = dp[j][c];
                        if (cur == INF) continue;

                        if (j + s <= k && c + 1 <= k) ndp[j + s][c + 1] = min(ndp[j + s][c + 1], cur);
                        int extra = i - c < k ? s - 1 : 0;
                        ndp[j][c] = min(ndp[j][c], cur + extra);
                    }
                }
                dp = ndp;
            }

            bool alice = false;
            for (int j = 0; j <= k; j++) {
                for (int c = 0; c <= k; c++) {
                    if (dp[j][c] <= k) {
                        alice = true;
                    }
                }
            }
            ans = alice ? "Alice" : "Bob";
        }
        cout << ans << '\n';
    }
}