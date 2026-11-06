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
const int MOD = 998244353;
const int MAXN = 5005;
ll dp[MAXN], ways[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    dp[0] = dp[2] = dp[3] = 1;
    for (int i = 4; i <= 5000; i++) dp[i] = (dp[i - 2] + dp[i - 3]) % MOD;

    vector<ll> a(5001);
    a[0] = ways[0] = 1;

    for (int i = 1; i <= 5000; i++) {
        for (int j = i; j >= 1; j--) a[j] = (a[j - 1] + j * a[j]) % MOD;
        for (int j = 1; j <= i; j++) ways[i] = (ways[i] + a[j]) % MOD;
        a[0] = 0;
    }

    int t;
    cin >> t;
    while (t--) {
        ll n, v = 0, ans = 1; cin >> n;
        string s; cin >> s;
        vector<int> seen(n);
        for (int l = 0; l < n;) {
            int r = l + 1;
            while (r < n && s[r] != s[r - 1]) r++;

            int len = r - l;
            if (len >= 2) {
                ans = ans * dp[len] % MOD;
                for (int i = l; i < r; i++) seen[i] = 1, v++;
            }
            l = r;
        }

        int cnt0 = 0, cnt1 = 0;
        for (int i = 0; i < n; i++) {
            if (!seen[i]) {
                if (s[i] == '0') cnt0++;
                else cnt1++;
            }
        }

        ll cost = 2LL * v + n - v;
        ans = ans * ways[cnt0] % MOD;
        ans = ans * ways[cnt1] % MOD;
        cout << cost << " " << ans << '\n';
    }
}