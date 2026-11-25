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
    // cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<ll> s(n+1), dp(n+1);
        for (int i = 1; i <= n; i++) cin >> s[i];
        sort(s.begin() + 1 , s.end());
        for(int l = 2; l <= n; l++){
            for(int i = 1; i + l <= n + 1; i++){
                int j = i + l - 1;
                dp[i] = min(dp[i+1],dp[i]) + s[j] - s[i];
            }
        }
        cout << dp[1] << endl;
    }
}