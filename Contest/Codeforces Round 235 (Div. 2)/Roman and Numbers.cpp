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

    ll n, m; cin >> n >> m;
    vector<int> digit;
    ll tmp = n;
    while (tmp) digit.push_back(tmp % 10), tmp /= 10;
    int k = digit.size();
    sort(digit.begin(), digit.end());

    vector<vector<ll>> dp(1 << k, vector<ll>(m, 0));
    dp[0][0] = 1;
    
    for(int mask = 0; mask < 1<<k; mask++){
        for(int rem = 0; rem < m; rem++){
            if(dp[mask][rem] == 0) continue;
            for(int i = 0; i < k; i++){
                if(mask & (1<<i)) continue;
                if(mask == 0 and digit[i] == 0) continue;
                if(i > 0 and digit[i] == digit[i-1] and !(mask & (1<<(i - 1)))) continue;
                int nmask = mask|(1<<i);
                int nrem = (rem * 10 + digit[i]) % m;
                dp[nmask][nrem] += dp[mask][rem];
            }
        }
    }
    cout << dp[(1<<k)-1][0];
}