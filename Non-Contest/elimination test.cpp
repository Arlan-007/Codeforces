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

using ll = long long;

const ll MOD = 998244353;
const int N = 5005;

ll fact[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fact[0] = 1;
    for (int i = 1; i < N; i++)
        fact[i] = fact[i - 1] * i % MOD;

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n + 1);
        vector<ll> dp(n + 1, fact[n - 1]);
        vector<ll> pref(n + 1);

        for (int i = 1; i < n; i++)
            cin >> a[i];

        ll ans = 0;

        for (int i = 1; i < n; i++) {
            fill(pref.begin(), pref.end(), -1);

            int j = i, m = 0;
            ll sum = 0;

            while (j > 0 && pref[a[j]] == -1) {
                int k = j;
                while (k > 0 && a[k] == a[j])
                    k--;

                int len = j - k;

                pref[a[j]] = sum;
                m++;

                ll term = len * fact[n - m - 1] % MOD;

                if (m % 2 == 0)
                    term = MOD - term;

                sum = (sum + term) % MOD;
                j = k;
            }

            ll old = dp[a[i]];

            for (int x = 1; x <= n; x++) {
                ll sub = (pref[x] == -1 ? sum : pref[x]);

                ll next = (fact[n - 1] - sub + MOD) % MOD;

                if (x == a[i])
                    next = (next + old) % MOD;

                ll diff = (dp[x] - next + fact[n - 1]) % MOD;

                ans ^= diff * i * x;
                dp[x] = next;
            }
        }

        cout << ans << '\n';
    }
}
