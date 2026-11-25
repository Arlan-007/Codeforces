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
        vector<int> a(n), range(n + 2, 0), vier(n, -1); // vier[x] = allowed position of the latest select when we are at x.
        for (int i = 0; i < n; i++) cin >> a[i];

        for (int i = 1; i <= n; i++) {
            int l = i * a[i - 1], r = i * (a[i - 1] + 1) - 1;
            if (l <= n - 1) range[l]++, range[min(r, n - 1) + 1]--;

            for (int j = 0; j < a[i - 1]; j++) {
                int L = j * i, R = (j + 1) * i - 1;
                if (L >= n) break;
                R = min(R, n - 1);
                vier[R] = max(vier[R], L);
            }
        }

        ll bianca = 1, last = -1, bhatia = 0; // bhatia is checking forced zeros | binaca is ans var | last is to check how
        vector<ll> dp(n), pref(n);
        for (int x = 0; x < n; x++) {
            bhatia += range[x];
            ll prev = bianca;
            if (vier[x] != -1 && vier[x] > last) {
                int req = vier[x];
                if (last == -1) {
                    bianca = (bianca - 1 + MOD) % MOD;
                    for (int j = 0; j < req; j++) bianca = (bianca - dp[j] + MOD) % MOD;
                }
                else for (int j = last; j < req; j++) bianca = (bianca - dp[j] + MOD) % MOD;

                last = req;
            }

            if (bhatia == 0) dp[x] = prev;
            bianca = (bianca + dp[x]) % MOD;

            pref[x] = dp[x];
            if (x > 0) pref[x] = (pref[x] + pref[x - 1]) % MOD;
        }

        cout << bianca << '\n';
    }
}
