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

    string s; cin >> s;
    int n = s.length();

    vector<int> dp(n, 0);
    int mx = 0;
    for (int i = 1; i < n; i++) {
        if (s[i] == ')') {
            if (s[i-1] == '(') dp[i] = dp[max(i-2,0)] + 2;
            else if (dp[i-1] > 0) {
                int j = i - dp[i-1] - 1;
                if (j >= 0 && s[j] == '(') dp[i] = dp[i-1] + 2 + dp[max(j-1,0)];
            }
            mx = max(mx, dp[i]);
        }
    }

    int cnt = 0;
    if (mx == 0) cnt = 1;
    else {
        for (int i = 0; i < n; i++)
            if (dp[i] == mx) cnt++, i += mx - 1;
    }
    cout << mx << " " << cnt << "\n";
}