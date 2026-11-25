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

const ll MAX_VAL = 1e7 + 1;
int spf[MAX_VAL];

void sieve() {
    for (int i = 1; i < MAX_VAL; ++i) spf[i] = i;

    for (int i = 2; i * i < MAX_VAL; ++i) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAX_VAL; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    sieve();
    while (t--) {
        ll x, y; cin >> x >> y;
        if (gcd(x, y) != 1) {cout << 0 << '\n'; continue;}
        if ((x & 1) != 0 && (y & 1) != 0) {cout << 1 << '\n'; continue;}
        if (abs(x - y) == 1) {cout << -1 << '\n'; continue;}

        ll ext = abs(x - y), ans = INF;
        while(ext > 1) {
            ll nxt = spf[ext];
            ans = min(ans,nxt * (x / nxt + 1) - x);
            while(ext % nxt == 0) ext/=nxt;
        }
        cout << ans << '\n';
    }
}