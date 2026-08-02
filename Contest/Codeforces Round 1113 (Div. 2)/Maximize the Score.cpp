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
        vector<ll> a(2*n), first(n + 1, -1), other(2*n, -1);
        for (int i = 0; i < 2*n; i++) {
            cin >> a[i];
            if (first[a[i]] == -1) first[a[i]] = i;
            else other[i] = first[a[i]];
        }

        vector<ll> dp(2*n + 1, 0);
        for (int i = 1; i <= 2*n; i++) {
            dp[i] = dp[i - 1] + 1;
            if (other[i-1]!=-1) {
                ll l = other[i-1], len = i-l;
                dp[i] = max(dp[i], dp[l] + len*len);
            }
        }
        cout << dp[2*n] << "\n";
    }
}