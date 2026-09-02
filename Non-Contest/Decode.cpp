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
        string s; cin >> s;
        int n = s.length();
        vector<ll> pref(n + 1, 0), cnt(2 * n + 1, 0);
        for (int i = 0; i < n; i++) pref[i + 1] = pref[i] + (s[i] == '1' ? 1 : -1);

        ll ans = 0;
        for (int i = 0; i <= n; i++) ans = (ans + (n - i + 1) * cnt[pref[i] + n]) % MOD, cnt[pref[i] + n] = (cnt[pref[i] + n] + (i + 1)) % MOD;
        cout << ans << endl;

    }
}