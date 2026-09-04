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

#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline","O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,lzcnt,bmi2,bmi,tune=native")

using ll = long long;

const ll INF = (ll) 4e18;
const ll NEG = -INF;
const int MOD = 1'000'000'007;
const int MAXN = 4e6 + 5;

int n, m;
int dp[MAXN], suff[MAXN];

inline int add(int x, int y) {
    int c = x + y;
    return c >= m ? c - m : c;
}

inline int sub(int x, int y) {
    int c = x - y;
    return c < 0 ? c + m : c;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    dp[n] = suff[n] = 1;

    for(int i = n-1; i >= 1; i--){
        dp[i] = suff[i + 1];

        if (i <= n/2) {
            for(int b = 2, bi = i<<1; bi <= n; b++, bi += i) {
                int mx = bi + b > n ? n + 1 : bi + b;
                dp[i] = add(dp[i], sub(suff[bi], suff[mx]));
            }
        }

        suff[i] = add(suff[i + 1], dp[i]);
    }
    cout << dp[1];
}