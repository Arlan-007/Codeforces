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
        vector <ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        vector <vector <ll>> dp(n, vector <ll> (3, NEG));
        dp[0][0] = a[0];
        ll bhatia = dp[0][0], vier = NEG, bianca = NEG;
        for (int i = 1; i < n; ++i) {
            dp[i][0] = a[i] + i;
            dp[i][1] = bhatia + a[i];
            dp[i][2] = vier + a[i] - i;
            bhatia = max(bhatia, dp[i][0]);
            vier = max(vier, dp[i][1]);
            bianca = max(bianca, dp[i][2]);
        }
        cout << bianca << '\n';
    }
}