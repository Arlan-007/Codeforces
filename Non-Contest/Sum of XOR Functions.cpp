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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<ll> a(n), prefix(n + 1, 0);;
    for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] ^ (cin >> a[i], a[i]);

    ll ans = 0;
    for (int bit = 0; bit < 30; bit++) {
        ll count[2] = {1, 0};
        ll sum[2] = {0, 0};

        for (int r = 1; r <= n; r++) {
            int val = (prefix[r] >> bit) & 1;
            int opp = 1 - val;

            ll cnt = count[opp];
            ll sum_idx = sum[opp];

            ll cont = ((cnt * r % MOD) - sum_idx % MOD + MOD) % MOD;
            ll value = (1LL << bit) % MOD;
            ans = (ans + cont * value % MOD) % MOD;

            count[val]++;
            sum[val] = (sum[val] + r) % MOD;
        }
    }
    cout << ans << "\n";
}